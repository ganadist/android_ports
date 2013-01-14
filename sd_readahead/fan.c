
#define __aligned_u64 __u64 __attribute__((aligned(8)))
#include <sys/fanotify.h>
#include <linux/fanotify.h>

#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LOG_NDEBUG 0
#define LOG_TAG "readahead"
#include <cutils/log.h>

int fan_init(char *root) {
    int r;
    int fanotify_fd;

    if ((fanotify_fd = fanotify_init(FAN_CLOEXEC|FAN_NONBLOCK, O_RDONLY|O_LARGEFILE|O_CLOEXEC|O_NOATIME)) < 0)  {
        SLOGE("Failed to create fanotify object: %s", strerror(errno));
        r = -errno;
        goto finish;
    }

    if (fanotify_mark(fanotify_fd, FAN_MARK_ADD|FAN_MARK_MOUNT, FAN_OPEN|FAN_ACCESS, AT_FDCWD, root) < 0) {
        SLOGE("Failed to mark %s: %s", root, strerror(errno));
        r = -errno;
        goto finish;
    }

    r = fanotify_fd;

finish:
    return r;
}
