/*
 ** Copyright (c) 2015, Asim Jamshed, Robin Sommer, Seth Hall, Qiying Wang
 ** and the International Computer Science Institute. All rights reserved.
 **
 ** Redistribution and use in source and binary forms, with or without
 ** modification, are permitted provided that the following conditions are met:
 **
 ** (1) Redistributions of source code must retain the above copyright
 **     notice, this list of conditions and the following disclaimer.
 **
 ** (2) Redistributions in binary form must reproduce the above copyright
 **     notice, this list of conditions and the following disclaimer in the
 **     documentation and/or other materials provided with the distribution.
 **
 **
 ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 ** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 ** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ** ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 ** LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 ** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 ** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 ** INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 ** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 ** POSSIBILITY OF SUCH DAMAGE.
 **/
/* $FreeBSD$ */

#include <symhash.h>

#include <stdbool.h>

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#define prefetch(x) __builtin_prefetch(x)

#define KEY_CACHE_LEN 96

static uint32_t byte_cache[4][256];

static void
build_sym_key_cache(uint32_t *cache, int cache_len)
{
	static const uint8_t key[] = { 0x50, 0x6d };

    uint32_t result = (((uint32_t)key[0]) << 24) |
            (((uint32_t)key[1]) << 16) |
            (((uint32_t)key[0]) << 8)  |
            ((uint32_t)key[1]);

    uint32_t idx = 32;
    int i;

    for (i = 0; i < cache_len; i++, idx++) {
            uint8_t shift = (idx % 8);
            uint32_t bit;

            cache[i] = result;
            bit = ((key[(idx/8) & 1] << shift) & 0x80) ? 1 : 0;
            result = ((result << 1) | bit);
    }
}

static void
build_byte_cache()
{
	int i, j, k;
    uint32_t key_cache[KEY_CACHE_LEN];

	build_sym_key_cache(key_cache, KEY_CACHE_LEN);

	for (j = 0; j < 256; j++) {
		for (i = 0; i < 4; i++) {
			uint8_t b = j;
			byte_cache[i][j] = 0;
			for (k = 0; k < 8; k++) {
				if (b & 0x80)
					byte_cache[i][j] ^= key_cache[8 * i + k];
				b <<= 1U;
			}
		}
	}
}

void symhash_init()
{
    build_byte_cache();
}

uint32_t symhash(uint32_t sip, uint32_t dip, uint16_t sport, uint16_t dport)
{
    uint8_t *sip_b = (uint8_t *)&sip,
            *dip_b = (uint8_t *)&dip,
            *sp_b  = (uint8_t *)&sport,
            *dp_b  = (uint8_t *)&dport;
    uint32_t rc = byte_cache[0][sip_b[3]] ^
	     byte_cache[0][dip_b[3]] ^
	     byte_cache[0][sp_b[1]] ^
	     byte_cache[1][sip_b[2]] ^
	     byte_cache[1][dip_b[2]] ^
	     byte_cache[1][sp_b[0]] ^
	     byte_cache[2][sip_b[1]] ^
	     byte_cache[2][dip_b[1]] ^
	     byte_cache[2][dp_b[1]] ^
	     byte_cache[3][sip_b[0]] ^
	     byte_cache[3][dip_b[0]] ^
	     byte_cache[3][dp_b[0]];

	return rc;
}
