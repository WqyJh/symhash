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

#ifndef SYMHASH_H
#define SYMHASH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void symhash_init();

uint32_t symhash(uint32_t sip, uint32_t dip, uint16_t sport, uint16_t dport);

#ifdef __cplusplus
}
#endif

#endif /* SYMHASH_H */
