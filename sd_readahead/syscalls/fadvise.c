#include <fcntl.h>

extern long arm_fadvise64_64(int fd, int advice,
        loff_t offset, loff_t len);

int posix_fadvise(int fd, off_t offset, off_t len, int advice) {
    return arm_fadvise64_64(fd, advice, offset, len);
}
