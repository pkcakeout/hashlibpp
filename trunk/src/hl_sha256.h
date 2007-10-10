/* 
 * hashlib++ - a simple hash library for C++
 * 
 * Copyright (c) 2007 Benjamin Grüdelbach * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 	1)     Redistributions of source code must retain the above copyright
 * 	       notice, this list of conditions and the following disclaimer.
 * 
 * 	2)     Redistributions in binary form must reproduce the above copyright
 * 	       notice, this list of conditions and the following disclaimer in
 * 	       the documentation and/or other materials provided with the
 * 	       distribution.
 * 	     
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

//---------------------------------------------------------------------- 

/*
 * The hashlib++ SHA256 implementation is derivative from the sourcecode
 * published by Aaron D. Gifford
 *
 * Copyright (c) 2000-2001, Aaron D. Gifford
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTOR(S) ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTOR(S) BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

//---------------------------------------------------------------------- 

/**
 *  @file 	sha256.h
 *  @brief	This file contains the declaration of the SHA256 class
 *  @date 	Di 25 Sep 2007
 */  

//---------------------------------------------------------------------- 
//include protection
#ifndef SHA256_H
#define SHA256_H

//---------------------------------------------------------------------- 
//lenght defines
#define SHA256_BLOCK_LENGTH		64
#define SHA256_SHORT_BLOCK_LENGTH	(SHA256_BLOCK_LENGTH - 8)
#define SHA256_DIGEST_LENGTH		32
#define SHA256_DIGEST_STRING_LENGTH	(SHA256_DIGEST_LENGTH * 2 + 1)

//---------------------------------------------------------------------- 
//typedefs

/**
 * 1-byte  (8-bits)  
 */
typedef unsigned char uint8_t;		

/**
 * 4-bytes (32-bits) 
 */
typedef unsigned int uint32_t;

/** 
 * 8-bytes (64-bits) 
 */
typedef unsigned long long uint64_t;	

/**
 * Exactly 1 byte 
 */ 
typedef uint8_t  sha2_byte;	

/**
 * Exactly 4 bytes 
 */
typedef uint32_t sha2_word32;	

/**
 * Exactly 8 bytes 
 */ 
typedef uint64_t sha2_word64;	

/**
 * SHA265 context
 */
typedef struct SHA256_CTX 
{
	uint32_t	state[8];
	uint64_t	bitcount;
	uint8_t		buffer[SHA256_BLOCK_LENGTH];
} SHA256_CTX;

//----------------------------------------------------------------------

/**
 *  @brief 	This class represents the implementation of 
 *   		the sha256 algorithm.
 *
 *   		Basically the class provides three public member-functions
 *   		to create a hash:  SHA256_Init(), SHA256_Update() and SHA256_End().
 *   		If you want to create a hash based on a string or file quickly
 *   		you should use the sha1wrapper class instead of SHA1.
 */  
class SHA256
{
	private:


		/**
		 *  @brief 	Finalize the sha256 operation
		 *  @author	Benjamin Grüdelbach
		 *  @param	digest The digest to finalize the operation with.
		 *  @param	context The context to finalize.
		 */  
		void SHA256_Final(uint8_t digest[SHA256_DIGEST_LENGTH],
			          SHA256_CTX* context);

		/**
		 *  @brief 	Internal data transformation
		 *  @author	Benjamin Grüdelbach
		 *  @param	context The context to use
		 *  @param	data The data to transform	
		 */  
		void SHA256_Transform(SHA256_CTX* context,
			              const sha2_word32* data);

	public:

		/**
		 *  @brief 	Initialize the context
		 *  @author	Benjamin Grüdelbach
		 *  @param	context The context to init.
		 */  
		void SHA256_Init(SHA256_CTX *context);

		/**
		 *  @brief	Updates the context 
		 *  @author	Benjamin Grüdelbach
		 *  @param	context The context to update.
		 *  @param	data The data for updating the context.
		 *  @param	len The length of the given data.
		 */  
		void SHA256_Update(SHA256_CTX* context,
			           const uint8_t* data,
				   unsigned int len);

		/**
		 *  @brief 	Ends the sha256 operation and return the
		 *  		created hash in the given buffer.
		 *  @author	Benjamin Grüdelbach
		 *  @param	context The context to end.
		 *  @param	buffer This OUT-Parameter contains the created
		 *  		hash after ending the operation.
		 */  
		char* SHA256_End(SHA256_CTX* context,
			         char buffer[SHA256_DIGEST_STRING_LENGTH]);

};

//----------------------------------------------------------------------
//end of include protection
#endif

//----------------------------------------------------------------------
//EOF
