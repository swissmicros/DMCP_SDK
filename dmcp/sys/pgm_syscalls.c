/*

  Copyright (c) 2018 SwissMicros GmbH

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:

  1. Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

  3. Neither the name of the copyright holder nor the names of its
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
  BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
  OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
  OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
  IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.

*/

#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <sys/times.h>

#include <dmcp.h>

#include <main.h>
#include <qspi_crc.h>

void Program_Entry();

prog_info_t const prog_info = {
	PROG_INFO_MAGIC,       // uint32_t pgm_magic;
	0,                     // uint32_t pgm_size;
	(void*)Program_Entry,  // void * pgm_entry;
	PLATFORM_IFC_CNR,      // uint32_t ifc_cnr;
	PLATFORM_IFC_VER,      // uint32_t ifc_ver;
	QSPI_DATA_SIZE,        // uint32_t qspi_size;
	QSPI_DATA_CRC,         // uint32_t qspi_crc;
	PROGRAM_NAME,          // char pgm_name[16];
	PROGRAM_VERSION        // char pg
};



int _read (int file, char *ptr, int len)
{
	return len;
}


int _write(int file, char *ptr, int len)
{
	return len;
}


int _close(int file)
{
	return -1;
}


int _fstat(int file, struct stat *st)
{
	st->st_mode = S_IFCHR;
	return 0;
}

int _isatty(int file)
{
	return 1;
}

int _lseek(int file, int ptr, int dir)
{
	return 0;
}

int _kill(int pid, int sig)
{
	errno = EINVAL;
	return -1;
}

int _getpid(void)
{
	return 1;
}



void free(void *ptr) {
	__sysfn_free(ptr);
}


void *malloc(size_t size) {
	return __sysfn_malloc(size);
}


void *calloc(size_t count, size_t nbytes) {
	return __sysfn_calloc(count, nbytes);
}

void *realloc(void *ptr, size_t size) {
	return __sysfn_realloc(ptr, size);
}



void * __wrap__malloc_r (struct _reent *pr, size_t size) {
	return malloc(size);
}

void * _calloc_r (struct _reent *pr, size_t nmemb, size_t size) {
	return calloc(nmemb, size);
}

void * _realloc_r (struct _reent *pr, void *ptr, size_t size) {
	return realloc(ptr, size);
}

void _free_r (struct _reent *pr, void *ptr) {
	free(ptr);
}


void post_main() {
	// Just start DMCP
	set_reset_magic(RUN_DMCP_MAGIC);
	sys_reset();
}
