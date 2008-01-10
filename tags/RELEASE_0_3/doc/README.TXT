
hashlib++ - a simple hash library for C++
Copyright (c) 2007,2008 Benjamin Grüdelbach

About this document:
This document explains the basics of the hashlib++ library.  You should read this
stuff if you are new to hashlib++.

MI  9 Jan 2008 

-------------------------------------------------------------------------------	

Table of contents:

0) About hashlib++
1) Current version / What's new?
2) Supported hash functions  
3) Installing hashlib++
4) The structure of hashlib++
5) The library's files
6) Using hashlib++
7) Supported operation systems
8) License
9) Feedback, Questions, Contact
10) Third party agreements

-------------------------------------------------------------------------------	

0) About hashlib++?

hashlib++ is a simple and very easy to use library to create a cryptographic
checksum called "hash". hashlib++ is written in plain C++ and should work with
every compiler and platform. hashlib++ is released under the BSD-license (see
section 8) and therefore free software.

-------------------------------------------------------------------------------	

1) Current version / What's new?

The current stable version of hashlib++ is:  0.3

Improvements for hashlib++ version 0.3:

	* SHA384 and SHA512 support has been added to hashlib++ 
	* Throwing exceptions allow better error-handling
	* Bug fixes

-------------------------------------------------------------------------------	

2) Supported hash functions  

By now hashlib++ supports the following functions:

	* MD5		Message-Digest algorithm 5
	* SHA1  	Secure Hash Algorithm 1
	* SHA2-Family 	Secure Hash Algorithm 256, 384 and 512

-------------------------------------------------------------------------------	
3) Installing hashlib++

Windows:

	For Windows user it is recommend to download the binary setup program
	"Setup.exe" which will install hashlib++ as a static library to your
	system.

	Run Setup.exe and read the license agreements. If you agree click on
	"I Agree" and choose a destination folder for hashlib++ within the
	following page. Finally, click on "Install" to start the installation.

Linux/FreeBSD:
	
	Download the source tarball and untar it. Make sure that g++ is installed
       	and in you $PATH. Switch to the "src" directory and have a look at the 
	makefile. hashlib++ will be compiled and installed as a static library.
       	The headerfiles will be placed into /usr/local/include and the library
       	itself (libhl++.a) will be installed into /usr/local/lib by default.
	You can change the default paths by editing "INCLUDE_PATH" and/or 
	"LIB_PATH" in line 44 and 47 of the makefile to meet your needs.

	Now type 'make' to build hashlib++ as a static library and
	'make install' to install hashlib++ into LIB_PATH and INCLUDE_PATH. 
	Type 'make clean' to clean up the *.o files.
	
Alternative use for Windows, Linux and FreeBSD:

	By default hashlib++ will be installed as a static library and you can
	link your application against it. If you don't want that you can 
	alternatively add all source and header files (or only those you need)
	to your project and compile them with your application.

-------------------------------------------------------------------------------	

4) The structure of hashlib++

hashlib++ provides so called "wrappers" for each supported hash function which
simplify the creation of the relevant hash. Instead of implementing the full
algorithm for the hash function you only have to instantiate a desired wrapper
and call a memberfunction like getHashFromString() or getHashFromFile().  

The wrappers:

	* md5wrapper	for MD5		in hl_md5wrapper.h
	* sha1wrapper	for SHA1	in hl_sha1wrapper.h
	* sha256wrapper	for SHA256	in hl_sha256wrapper.h
	* sha384wrapper	for SHA384	in hl_sha384wrapper.h
	* sha512wrapper	for SHA512	in hl_sha512wrapper.h


-------------------------------------------------------------------------------	

5) The library's files

The library consist of the the following files:

	* hl_hashwrapper.h
	  This is a baseclass of all wrappers.

	* hl_exception.h
	  Class for error-handling.

	* hl_md5.h and hl_md5.cpp
	  These two files implement the MD5 algorithm. 
	
	* hl_md5wrapper.h and hl_md5wrapper.cpp
	  These files represents the MD5 wrapper. 
	
        * hl_sha1.h and hl_sha1.cpp
	  These two files implement the SHA1 algorithm. 
	
	* hl_sha1wrapper.h and hl_sha1wrapper.cpp
	  These files represents the SHA1 wrapper. 

        * hl_sha256.h and hl_sha256.cpp
	  These two files implement the SHA256 algorithm. 
	
	* hl_sha256wrapper.h and hl_sha256wrapper.cpp
	  These files represents the SHA256 wrapper. 

	* hl_sha2ext.h and hl_sha2ext.cpp
	  This is the implementation of SHA384 and SHA512
	  algorithm.

	* hl_2mac.h
	  Contains some macros used in the SHA384 and SHA512
	  implementation.

	* hl_sha384wrapper.h and hl_sha384wrapper.cpp
	  The wrapper class for SHA384.

	* hl_sha512wrapper.h and hl_sha512wrapper.cpp
	  The wrapper class for SHA512.
	
	* libtest.cpp
	  This is a example program which shows how to 
	  use hashlib++. The program expected a filename
	  or a string and creates the hashes of the given
	  file or characters.

-------------------------------------------------------------------------------	

6) Using hashlib++

This section explains how to create a hash with the help of hashlib++.  First of
all you have to include the baseclass "hashwrapper" (hl_hashwrapper.h) and the 
headerfile of the wrapper you want to use:

	#include <hl_hashwrapper.h>
	#include <hl_sha1wrapper.h>
	#include <hl_md5wrapper.h>

After that you can create wrapper objects:

	hashwrapper *md5 = new md5wrapper();
	hashwrapper *sha1 = new sha1wrapper();

Once a wrapper has been instantiated, you can basically call the memberfunctions
getHashFromFile() and getHashFromString() to create a hash from a file or
string.

	try
	{
		std::string mytexthash = md5->getHashFromString("Hello World");
		std::string myfilehash = md5->getHashFromFile("README.TXT");
	}
	catch(hlException &e)
	{
		// your error handling here.
		// use: e.error_number() and
		//      e.error_message()	
	}
		

And that's all! 

	delete md5;
	delete sha1;

Now you can compile your project. Don't forget to link against hashlib++,
if you use it as a static library.
If you are on Linux/FreeBSD/etc. you probably want to build your application
using g++. For example:

	g++ -I/usr/local/include -L/usr/local/lib libtest.cpp -lhl++

If you are using Windows and Visual C++ you can easily add the library to your 
project by using "Project -> Add Existing Item".

For other compilers or IDEs please see the specific documentation of the vendor. 

-------------------------------------------------------------------------------	
  
7) Supported operation systems

hashlib++ was written in standard C++, so it is platform independent and
should work with every C++ compiler. It was tested on the following systems
which are official supported:

	FreeBSD 6.2 with g++ 3.4.6 and 4.1.3
	Microsoft Windows XP with Microsoft Visual C++ 2005 Express Edition
	Gnu/Linux 2.6 with g++ 3.4.6

-------------------------------------------------------------------------------	

8) License

hashlib++ - a simple hash library for C++

Copyright (c) 2007,2008 Benjamin Grüdelbach

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

9) Feedback, Questions, Contact

I would be pleased to hear some feedback from you.
For special question feel free to send me an e-mail.

Benjamin Grüdelbach
bennygr@users.sourceforge.net
http://hashlib2plus.sourceforge.net/ 

-------------------------------------------------------------------------------	

10) Third party agreements

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

	* SHA256 implementation

	  The hashlib++ SHA256,SHA384 and SHA512 implementation is derivative 
	  from the sourcecode published by Aaron D. Gifford
	  
	  Copyright (c) 2000-2001, Aaron D. Gifford All rights reserved.
	  
	  Redistribution and use in source and binary forms, with or without
	  modification, are permitted provided that the following conditions are
	  met:
	  1. Redistributions of source code must retain the above copyright
	  notice, this list of conditions and the following disclaimer.  
	  2. Redistributions in binary form must reproduce the above copyright
	  notice, this list of conditions and the following disclaimer in the
	  documentation and/or other materials provided with the distribution.
	  3. Neither the name of the copyright holder nor the names of
	  contributors may be used to endorse or promote products derived from
	  this software without specific prior written permission.
	  
	  THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTOR(S) ``AS IS''
	  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
	  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
	  PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTOR(S)
       	  BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
       	  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
	  THE POSSIBILITY OF SUCH DAMAGE.
	    
-------------------------------------------------------------------------------	
EOF
