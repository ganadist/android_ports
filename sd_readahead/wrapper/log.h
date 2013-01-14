#ifndef __READAHEAD_LOG_H__
#define __READAHEAD_LOG_H__
/* systemd log macros for android */
#define LOG_NDEBUG 0
#define LOG_TAG "readahead"
#include <cutils/log.h>

#define log_debug(...)      SLOGD(__VA_ARGS__)
#define log_warning(...)    SLOGW(__VA_ARGS__)
#define log_error(...)      SLOGE(__VA_ARGS__)
#define log_info(...)       SLOGI(__VA_ARGS__)
#define log_set_target(x)   (x)
#define log_parse_environment() (0) 
#define log_oom()           (0)
#define log_open()          (0)

#define log_assert_failed(...) SLOGE("%s %s %s %s", __VA_ARGS__)

#define LOG_TARGET_SAFE (0)

#endif
