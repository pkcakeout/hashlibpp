# 
# hashlib++ - a simple hash library for C++
# 
# Copyright (c) 2007 Benjamin Grüdelbach
# 
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:
# 
# 	1)     Redistributions of source code must retain the above copyright
# 	       notice, this list of conditions and the following disclaimer.
# 
# 	2)     Redistributions in binary form must reproduce the above copyright
# 	       notice, this list of conditions and the following disclaimer in
# 	       the documentation and/or other materials provided with the
# 	       distribution.
# 	     
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
# ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#----------------------------------------------------------------------- 
#
# This is the hashlib++ makefile. It builds and installs hashlib++ as a
# static library. See the documentation for more information.
#
# Type 'make' to build the lib.
# Type 'make install' to build and install the lib.
# Type 'make clean' to clean the object files
#
# Benjamin Grüdelbach
# Mi 10 Okt 2007
#
#----------------------------------------------------------------------- 
# Edit the following lines to meet your needs

# Path to install the headerfiles
INCLUDE_PATH = /usr/local/include/

# Path to install the library
LIB_PATH = /usr/local/lib/

# compiler
GCC = g++

#----------------------------------------------------------------------- 
# DON'T CHANGE ANYTHING BELOW
#----------------------------------------------------------------------- 

#----------------------------------------------------------------------- 
#Main-Target
all:		MD5 SHA1 SHA256 LIB

#----------------------------------------------------------------------- 
#all header-files

		
HEADER = 	hl_hashwrapper.h \
		hl_md5.h hl_md5wrapper.h \
		hl_sha1.h hl_sha1wrapper.h \
		hl_sha256.h hl_sha256wrapper.h
		
#----------------------------------------------------------------------- 
# MD5 Targets

MD5 = 		hl_md5.o \
      		hl_md5wrapper.o

MD5:		hl_md5.o hl_md5wrapper.o

hl_md5.o:	hl_md5.cpp hl_md5.h
		$(GCC) -c hl_md5.cpp

hl_md5wrapper.o:	hl_md5wrapper.cpp hl_md5wrapper.h
			$(GCC) -c hl_md5wrapper.cpp

#----------------------------------------------------------------------- 
# SHA1 Targets

SHA1 = 		hl_sha1.o \
       		hl_sha1wrapper.o

SHA1:		hl_sha1.o hl_sha1wrapper.o

hl_sha1.o:	hl_sha1.cpp hl_sha1.h
		$(GCC) -c hl_sha1.cpp

hl_sha1wrapper.o:	hl_sha1wrapper.cpp hl_sha1wrapper.h
			$(GCC) -c hl_sha1wrapper.cpp

#----------------------------------------------------------------------- 
# SHA256 Targets

SHA256 = 	hl_sha256.o \
	 	hl_sha256wrapper.o

SHA256:		hl_sha256.o hl_sha256wrapper.o

hl_sha256.o:	hl_sha256.cpp hl_sha256.h
		$(GCC) -c hl_sha256.cpp

hl_sha256wrapper.o:	hl_sha256wrapper.cpp hl_sha256wrapper.h
			$(GCC) -c hl_sha256wrapper.cpp

#----------------------------------------------------------------------- 
# Creating a static lib using ar

LIB:		MD5 SHA1 SHA256			
		ar rs libhl++.a $(MD5) $(SHA1) $(SHA256)

#----------------------------------------------------------------------- 
#Installing the lib
install:	all
		cp libhl++.a $(LIB_PATH) && \
		cp $(HEADER) $(INCLUDE_PATH)

#----------------------------------------------------------------------- 
# Cleaning object-files

clean:
		rm *.o

#----------------------------------------------------------------------- 
#EOF
