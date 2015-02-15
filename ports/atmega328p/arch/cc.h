/*This file has been prepared for Doxygen automatic documentation generation.*/
/*! \file *********************************************************************
 *
 * \brief lwIP abstraction layer for AVR32 UC3.
 *
 * - Compiler:           GNU GCC for AVR32
 * - Supported devices:  All AVR32 devices can be used.
 * - AppNote:
 *
 * \author               Atmel Corporation: http://www.atmel.com \n
 *                       Support and FAQ: http://support.atmel.no/
 *
 *****************************************************************************/

/* Copyright (c) 2007, Atmel Corporation All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. The name of ATMEL may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY AND
 * SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __CC_H__
#define __CC_H__

#include <stdint.h>
#include "cpu.h"

typedef uint8_t    		u8_t;
typedef int8_t     		s8_t;
typedef uint16_t   		u16_t;
typedef int16_t   		s16_t;
typedef uint32_t    	u32_t;
typedef int32_t    		s32_t;

typedef uint32_t 		mem_ptr_t;
typedef int sys_prot_t;

typedef unsigned char		u_char;
typedef unsigned short		u_short;
typedef unsigned int		u_int;

/*! Defines for the LWIP_STATS feature. */
//#define S16_F   "d"
//#define U16_F   "d"
//#define X16_F   "d"
//#define X32_F   "d"
//#define U32_F   "d"
//#define S32_F   "d"

#define S16_F   "hu"
#define U16_F   "hd"
#define X16_F   "hx"
#define X32_F   "u"
#define U32_F   "d"
#define S32_F   "x"

#define LWIP_PLATFORM_DIAG(x)   
#define LWIP_PLATFORM_ASSERT(x)   

/* */
#if __GNUC__
#define PACK_STRUCT_BEGIN
#elif __ICCAVR32__
#define PACK_STRUCT_BEGIN _Pragma("pack(1)")
#endif

#if __GNUC__
#define PACK_STRUCT_STRUCT __attribute__ ((__packed__))
#elif __ICCAVR32__
#define PACK_STRUCT_STRUCT
#endif

#if __GNUC__
#define PACK_STRUCT_END
#elif __ICCAVR32__
#define PACK_STRUCT_END _Pragma("pack()")
#endif

#define PACK_STRUCT_FIELD(x) x

#endif /* __CC_H__ */
