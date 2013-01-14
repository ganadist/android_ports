#ifndef __READAHEAD_MACRO_H__
#define __READAHEAD_MACRO_H__

#include <stdint.h>
#include "log.h"

#define _packed_ __attribute__ ((packed))
#define _malloc_ __attribute__ ((malloc))
#define _likely_(x) (__builtin_expect(!!(x),1))
#define _unlikely_(x) (__builtin_expect(!!(x),0))

#define SFD_CLOEXEC O_CLOEXEC
#define SFD_NONBLOCK O_NONBLOCK
#define IN_CLOEXEC O_CLOEXEC
#define IN_NONBLOCK O_NONBLOCK

#define POSIX_FADV_WILLNEED 3

#define CANONICAL_HOST "localhost"

#define MSEC_PER_SEC  1000ULL
#define USEC_PER_SEC  1000000ULL
#define USEC_PER_MSEC 1000ULL
#define NSEC_PER_SEC  1000000000ULL
#define NSEC_PER_MSEC 1000000ULL
#define NSEC_PER_USEC 1000ULL

#define USEC_PER_MINUTE (60ULL*USEC_PER_SEC)
#define NSEC_PER_MINUTE (60ULL*NSEC_PER_SEC)
#define USEC_PER_HOUR (60ULL*USEC_PER_MINUTE)
#define NSEC_PER_HOUR (60ULL*NSEC_PER_MINUTE)
#define USEC_PER_DAY (24ULL*USEC_PER_HOUR)
#define NSEC_PER_DAY (24ULL*NSEC_PER_HOUR)
#define USEC_PER_WEEK (7ULL*USEC_PER_DAY)
#define NSEC_PER_WEEK (7ULL*NSEC_PER_DAY)
#define USEC_PER_MONTH (2629800ULL*USEC_PER_SEC)
#define NSEC_PER_MONTH (2629800ULL*NSEC_PER_SEC)
#define USEC_PER_YEAR (31557600ULL*USEC_PER_SEC)
#define NSEC_PER_YEAR (31557600ULL*NSEC_PER_SEC)

typedef uint64_t usec_t;
usec_t now(clockid_t clock);
int parse_usec(const char *t, usec_t *usec);

/* Rounds up */
#define ALIGN(l) ALIGN_TO((l), sizeof(void*))
static inline size_t ALIGN_TO(size_t l, size_t ali) {
        return ((l + ali - 1) & ~(ali - 1));
}

#define ELEMENTSOF(x) (sizeof(x)/sizeof((x)[0]))

#include <assert.h>
#define assert_se(...) __VA_ARGS__
#define assert_cc assert

#define PTR_TO_ULONG(p) ((unsigned long) ((uintptr_t) (p)))
#define ULONG_TO_PTR(u) ((void*) ((uintptr_t) (u)))

#define PTR_TO_UINT(p) ((unsigned int) ((uintptr_t) (p)))

#define memzero(x,l) (memset((x), 0, (l)))
#define zero(x) (memzero(&(x), sizeof(x)))

#define char_array_0(x) x[sizeof(x)-1] = 0;

#ifndef MAX
#define MAX(a,b)                                \
        __extension__ ({                        \
                        typeof(a) _a = (a);     \
                        typeof(b) _b = (b);     \
                        _a > _b ? _a : _b;      \
                })
#endif


#ifndef false
#define false (0)
#endif
#ifndef true
#define true (1)
#endif

#ifndef LINE_MAX
#define LINE_MAX 2048
#endif

#define program_invocation_short_name "readahead"

#endif
