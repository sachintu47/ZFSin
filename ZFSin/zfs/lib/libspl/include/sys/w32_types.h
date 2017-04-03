/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright(c) 2017 Jorgen Lundman <lundman@lundman.net>
 */

/*
 * Unfortunately Windows does not have a #include_next so we
 * renamed this wrapper, and it will have to be manually included
 * after each sys/types.h include
 */


#ifndef _LIBSPL_SYS_W32_TYPES_H
#define	_LIBSPL_SYS_W32_TYPES_H

#include <sys/isa_defs.h>
#include <sys/feature_tests.h>
//#include_next <sys/types.h>
#include <sys/param.h> /* for NBBY */
#include <sys/types32.h>
#include <sys/va_list.h>
#include <sys/timer.h>

#include <stdint.h>
#include <malloc.h>

typedef enum boolean { B_FALSE=0, B_TRUE } boolean_t;
typedef enum boolean bool_t;

typedef unsigned char	uchar_t;
typedef unsigned short	ushort_t;
typedef unsigned int	uint_t;
typedef unsigned long	ulong_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef long long	longlong_t;
typedef unsigned long long u_longlong_t;
typedef char int8_t;
typedef unsigned char uint8_t;
typedef unsigned char uchar_t;
typedef unsigned int u_int;

typedef longlong_t	offset_t;
typedef u_longlong_t	u_offset_t;
typedef u_longlong_t	len_t;
typedef longlong_t	diskaddr_t;

typedef ulong_t		pfn_t;		/* page frame number */
typedef ulong_t		pgcnt_t;	/* number of pages */
typedef long		spgcnt_t;	/* signed number of pages */

typedef longlong_t	hrtime_t;
typedef struct timespec	timestruc_t;
typedef struct timespec timespec_t;

typedef short		pri_t;

typedef int		zoneid_t;
typedef int		projid_t;

typedef int		major_t;
typedef uint_t	minor_t;
typedef int pid_t;

typedef ushort_t o_mode_t; /* old file attribute type */
typedef short		index_t;

typedef unsigned long long rlim64_t;

typedef uint64_t uid_t;
typedef uint64_t gid_t;
typedef uint64_t user_ssize_t;

typedef unsigned long ulong_t;
typedef unsigned char uchar_t;

typedef uint32_t dev_t;

#define F_OK 0
#define W_OK 2
#define R_OK 4

#define MAXPATHLEN MAX_PATH
#define PATH_MAX  MAX_PATH

typedef struct timespec			timestruc_t; /* definition per SVr4 */
typedef struct timespec			timespec_t;


#define strlcpy(D, S, N) strncpy_s((D), (N), (S), _TRUNCATE)
#define strlcat(D, S, N) strncat_s((D), (N), (S), _TRUNCATE)



/*
 * Definitions remaining from previous partial support for 64-bit file
 * offsets.  This partial support for devices greater than 2gb requires
 * compiler support for long long.
 */
#ifdef _LONG_LONG_LTOH
typedef union {
	offset_t _f;    /* Full 64 bit offset value */
	struct {
		int32_t _l; /* lower 32 bits of offset value */
		int32_t _u; /* upper 32 bits of offset value */
	} _p;
} lloff_t;
#endif

#ifdef _LONG_LONG_HTOL
typedef union {
	offset_t _f;    /* Full 64 bit offset value */
	struct {
		int32_t _u; /* upper 32 bits of offset value */
		int32_t _l; /* lower 32 bits of offset value */
	} _p;
} lloff_t;
#endif

#define	ENOTBLK	15	/* Block device required		*/
#define	EDQUOT	49	/* Disc quota exceeded			*/
#define	EBADE	50	/* invalid exchange			*/
#define ESHUTDOWN       58              /* Can't send after socket shutdown */
#define ESTALE          70              /* Stale NFS file handle */

#define O_SHLOCK 0

#define INT_MAX 2147483647

#define	DBL_DIG		15
#define	DBL_MAX		1.7976931348623157081452E+308
#define	DBL_MIN		2.2250738585072013830903E-308

#define	FLT_DIG		6
#define	FLT_MAX		3.4028234663852885981170E+38F
#define	FLT_MIN		1.1754943508222875079688E-38F

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#define O_EXLOCK 0

#define bzero(b,len) (memset((b), '\0', (len)))
#define bcopy(b1,b2,len) (memmove((b2), (b1), (len)))
#define bcmp(b1, b2, len) (memcmp((b2), (b1), (len)))

#define alloca _alloca
#define posix_memalign_free _aligned_free
int posix_memalign(void **memptr, uint32_t alignment, uint32_t size);

#define MIN(a, b)  (((a) < (b)) ? (a) : (b)) 

#define sleep(x) Sleep(x * 1000000)

int fsync(int);

#define lstat _stat64

#define MFSTYPENAMELEN  16
#define MAXPATHLEN      1024
#define MNAMELEN        MAXPATHLEN

#define roundup(x, y)         ((((x) + ((y) - 1)) / (y)) * (y))
#define howmany(x, y)   ((((x) % (y)) == 0) ? ((x) / (y)) : (((x) / (y)) + 1))


#endif