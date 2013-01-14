#ifndef __READAHEAD_UTIL_H__
#define __READAHEAD_UTIL_H__

#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "log.h"
#include "macro.h"

#define NEWLINE "\n\r"
#define WHITESPACE " \t\n\r"

size_t page_size(void);
#define PAGE_ALIGN(l) ALIGN_TO((l), page_size())
#define streq(a,b) (strcmp((a),(b)) == 0)

#define new(t, n) ((t*) malloc_multiply(sizeof(t), (n)))
#define malloc0(n) (calloc((n), 1))

static inline const char* yes_no(bool b) {
        return b ? "yes" : "no";
}

_malloc_ static inline void *malloc_multiply(size_t a, size_t b) {
    if (_unlikely_(b == 0 || a > ((size_t) -1) / b))
        return NULL;

    return malloc(a * b);
}

int close_nointr(int fd);
void close_nointr_nofail(int fd);
int readlink_malloc(const char *p, char **r);
char* startswith(const char *s, const char *prefix);
char *endswith(const char *s, const char *postfix);
char *truncate_nl(char *s);
bool is_main_thread(void);
size_t page_size(void);
int read_one_line_file(const char *fn, char **line);
int write_one_line_file(const char *fn, const char *line);

int block_get_whole_disk(dev_t d, dev_t *ret);

int safe_atou(const char *s, unsigned *ret_u);
int safe_atollu(const char *s, unsigned long long *ret_u);

static inline int safe_atou64(const char *s, uint64_t *ret_u) {
        assert_cc(sizeof(uint64_t) == sizeof(unsigned long long));
        return safe_atollu(s, (unsigned long long*) ret_u);
}

void sigset_add_many(sigset_t *ss, ...);

int posix_fadvise(int fd, off_t offset, off_t len, int advice);
int inotify_init1(int flags);


#endif
