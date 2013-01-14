#ifndef __READAHEAD_IOPRIO_H__
#define __READAHEAD_IOPRIO_H__
/* ioprio_set wrapper for android */
#include <linux/ioprio.h>
#include <cutils/iosched_policy.h>


#define ioprio_set(klass, pid, value) \
    android_set_ioprio(pid, IOPRIO_PRIO_CLASS(value),  IOPRIO_PRIO_DATA(value))

#endif
