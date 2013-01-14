#ifndef __SYS_FANOTIFY_H__
#define __SYS_FANOTIFY_H__
#include <stdint.h>

#define __aligned_u64 __u64 __attribute__((aligned(8)))
#include <linux/fanotify.h>

int fanotify_init (unsigned int __flags, unsigned int __event_f_flags);
int fanotify_mark (int __fanotify_fd, unsigned int __flags,
        uint64_t __mask, int __dfd, const char *__pathname);

#endif
