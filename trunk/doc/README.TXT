
hashlib++ - a simple hash library for C++
Copyright (c) 2007 Benjamin Grüdelbach

About this document:
This document explains the basics of the hashlib++ library.  You should read this
stuff if you are new to hashlib++.

Mi 19 Sep 2007

-------------------------------------------------------------------------------	

Table of contents:

0) About hashlib++
1) Current version
2) Supported hash functions  
3) The structure of hashlib++
4) The library's files
5) Using hashlib++
6) Supported operation systems
7) License
8) Feedback, Questions, Contact
9) Third party agreements

-------------------------------------------------------------------------------	

0) About hashlib++?

hashlib++ is a simple and very easy to use library to create a cryptographic
checksum called "hash". hashlib++ is written in plain C++ and should work with
every compiler and platform. hashlib++ is released under the BSD-license (see
section 7) and therefore free software.

-------------------------------------------------------------------------------	

1) Current version

The current stable version of hashlib++ is:  0.1 rc 1

-------------------------------------------------------------------------------	

2) Supported hash functions  

hashlib++ is in a very early state, thus only two functions are supported at the
moment:

	* MD5	Message-Digest algorithm 5
	* SHA1  Secure Hash Algorithm 1

-------------------------------------------------------------------------------	

3) The structure of hashlib++

hashlib++ provides so called "wrappers" for each supported hash function which
simplify the creation of the relevant hash. Instead of implementing the full
algorithm for the hash function you only have to instantiate a desired wrapper
and call a memberfunction like getHashFromString() or getHashFromFile().  

TODO: see for more details

-------------------------------------------------------------------------------	

4) The library's files

The library consist of the the following files:

	* hashwrapper.h
	  This is a baseclass of all wrappers.

	* md5.h and md5.cpp
	  These two files implement the MD5 algorithm. 
	
	* md5wrapper.h and md5wrapper.cpp
	  These files represents the MD5 wrapper. 
	  Use this wrapper to easily create a MD5 hash.
	
        * sha1.h and sha1.cpp
	  These two files implement the SHA1 algorithm. 
	
	* sha1wrapper.h and sha1wrapper.cpp
	  These files represents the SHA1 wrapper. 
	  Use this wrapper to easily create a SHA1 hash.
	
	* libtest.cpp
	  This is a example program which shows how to 
	  use hashlib++. The program expected a filename
	  or a string and creates the SHA1 and MD5 hash
	  of the given file or characters.

-------------------------------------------------------------------------------	

5) Using hashlib++

This section explains how to create a hash with the help of hashlib++.  First of
all you have to include the baseclass "hashwrapper.h" and the headerfile of the
wrapper you want to use:

	#include "hashwrapper.h"
	#include "sha1wrapper.h"
	#include "md5wrapper.h"

After that you can create wrapper objects:

	hashwrapper *md5 = new md5wrapper();
	hashwrapper *sha1 = new sha1wrapper();

Once a wrapper has been instantiated, you can basically call the memberfunctions
getHashFromFile() and getHashFromString() to create a hash from a file or
string.

	std::string mytexthash = md5->getHashFromString("Hello World");
	std::string myfilehash = md5->getHashFromFile("README.TXT");

And that's all! 

	delete md5;
	delete sha1;

Now you can add the corresponding *.cpp files (For MD5 for example: md5.cpp and
md5wrapper.cpp) to your project and start compiling.

-------------------------------------------------------------------------------	
  
6) Supported operation systems

hashlib++ was written in standard C++, so it is platform independent and
should work with every C++ compiler. It was tested on the following systems
which are official supported:

	FreeBSD 6.2 with g++ 3.4.6

-------------------------------------------------------------------------------	

7) License

hashlib++ - a simple hash library for C++

Copyright (c) 2007 Benjamin Grüdelbach

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

	1)     Redistributions of source code must retain the above copyright
	       notice, this list of conditions and the following disclaimer.

	2)     Redistributions in binary form must reproduce the above copyright
	       notice, this list of conditions and the following disclaimer in
	       the documentation and/or other materials provided with the
	       distribution.
	     
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

-------------------------------------------------------------------------------	

8) Feedback, Questions, Contact

I would be pleased to hear some feedback from you.
For special question feel free to send me an e-mail.

Benjamin Grüdelbach
bennygr@users.sourceforge.net
http://hashlib2plus.sourceforge.net/ 

-------------------------------------------------------------------------------	

9) Third party agreements

	* MD5 implementation

	  The hashlib++ MD5 implementation is derivative from the sourcecode
	  published in RFC 1321 which contains the following copyright: 

	  Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All rights
	  reserved.

	  License to copy and use this software is granted provided that it is
	  identified as the "RSA Data Security, Inc. MD5 Message-Digest
	  Algorithm" in all material mentioning or referencing this software or
	  this function.

	  License is also granted to make and use derivative works provided that
	  such works are identified as "derived from the RSA Data Security, Inc.
	  MD5 Message-Digest Algorithm" in all material mentioning or
	  referencing the derived work.

	  RSA Data Security, Inc. makes no representations concerning either the
	  merchantability of this software or the suitability of this software
	  for any particular purpose. It is provided "as is" without express or
	  implied warranty of any kind.

	  These notices must be retained in any copies of any part of this
	  documentation and/or software.

	* SHA1 implementation
	  
	  The hashlib++ SHA1 implementation is derivative from the sourcecode
	  published in RFC 3174 which contains the following copyright: 
	  
	  Copyright (C) The Internet Society (2001).  All Rights Reserved.
	  
	  This document and translations of it may be copied and furnished to
	  others, and derivative works that comment on or otherwise explain it
	  or assist in its implementation may be prepared, copied, published and
	  distributed, in whole or in part, without restriction of any kind,
	  provided that the above copyright notice and this paragraph are
	  included on all such copies and derivative works.  However, this
	  document itself may not be modified in any way, such as by removing
	  the copyright notice or references to the Internet Society or other
	  Internet organizations, except as needed for the purpose of developing
	  Internet standards in which case the procedures for copyrights defined
	  in the Internet Standards process must be followed, or as required to
	  translate it into languages other than English.
	  
	  The limited permissions granted above are perpetual and will not be
	  revoked by the Internet Society or its successors or assigns.
	  
	  This document and the information contained herein is provided on an
	  "AS IS" basis and THE INTERNET SOCIETY AND THE INTERNET ENGINEERING
	  TASK FORCE DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT
	  NOT LIMITED TO ANY WARRANTY THAT THE USE OF THE INFORMATION HEREIN
	  WILL NOT INFRINGE ANY RIGHTS OR ANY IMPLIED WARRANTIES OF
	  MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
	    
-------------------------------------------------------------------------------	
EOF
