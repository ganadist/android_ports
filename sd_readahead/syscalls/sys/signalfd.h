#ifndef __READAHEAD_SYS_SIGNALFD_H__
#define __READAHEAD_SYS_SIGNALFD_H__
#include <signal.h>

extern int signalfd4(int fd, const sigset_t *mask, size_t sizemask, int flags);
static inline int signalfd (int __fd, const sigset_t *__mask, int __flags) {
    return signalfd4(__fd, __mask, _NSIG/8, __flags);
}

#endif
