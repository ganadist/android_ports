#include <errno.h>

int __readahead_set_errno(int n) {
    if (n > -256)
        return __set_errno(-n);
    return n;
}
