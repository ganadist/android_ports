#ifndef __SYSCALL_NO_H__
#define __SYSCALL_NO_H__

/* from arch/arm/include/asm/unistd.h */
#ifndef __NR_inotify_init1
#define __NR_inotify_init1 360
#endif
#ifndef __NR_fanotify_init
#define __NR_fanotify_init 367
#endif
#ifndef __NR_fanotify_mark
#define __NR_fanotify_mark 368
#endif
#ifndef __NR_signalfd4
#define __NR_signalfd4 355
#endif
#ifndef __NR_signalfd
#define __NR_signalfd 349
#endif
#ifndef __NR_arm_fadvise64_64
#define __NR_arm_fadvise64_64 270
#endif

#endif
