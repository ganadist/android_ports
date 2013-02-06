#include <fcntl.h>

#ifdef __arm__
extern long arm_fadvise64_64(int fd, int advice,
        loff_t offset, loff_t len);
#endif
#ifndef __arm__ // __i386__ || __mips
extern long fadvise64(int fd, loff_t offset,
        size_t len, int advice);
#endif

int posix_fadvise(int fd, off_t offset, off_t len, int advice) {
#ifdef __arm__
    return arm_fadvise64_64(fd, advice, offset, len);
#else
    return fadvise64(fd, offset, len, advice);
#endif
}
