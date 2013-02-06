#ifndef __SYSCALL_NO_H__
#define __SYSCALL_NO_H__

/* from arch/arm/include/asm/unistd.h */
#ifdef __arm__
#ifndef __NR_SYSCALL_BASE
#define __NR_SYSCALL_BASE 0
#endif
#ifndef __NR_arm_fadvise64_64
#define __NR_arm_fadvise64_64   (__NR_SYSCALL_BASE+ 270)
#endif
#ifndef __NR_signalfd4
#define __NR_signalfd4          (__NR_SYSCALL_BASE+ 355)
#endif
#ifndef __NR_inotify_init1
#define __NR_inotify_init1      (__NR_SYSCALL_BASE+ 360)
#endif
#ifndef __NR_fanotify_init
#define __NR_fanotify_init      (__NR_SYSCALL_BASE+ 367)
#endif
#ifndef __NR_fanotify_mark
#define __NR_fanotify_mark      (__NR_SYSCALL_BASE+ 368)
#endif
#endif

/* from arch/x86/include/generated/asm/unistd_32.h */
#ifdef __i386__
#ifndef __NR_fadvise64
#define __NR_fadvise64          250
#endif
#ifndef __NR_signalfd4
#define __NR_signalfd4          327
#endif
#ifndef __NR_inotify_init1
#define __NR_inotify_init1      332
#endif
#ifndef __NR_fanotify_init
#define __NR_fanotify_init      338
#endif
#ifndef __NR_fanotify_mark
#define __NR_fanotify_mark      339
#endif
#endif

/* from arch/mips/include/asm/unistd.h */
#ifdef __mips__
#ifndef __NR_Linux
#define __NR_Linux              4000
#endif
#ifndef __NR_fadvise64
#define __NR_fadvise64          (__NR_Linux+ 254)
#endif
#ifndef __NR_signalfd4
#define __NR_signalfd4          (__NR_Linux+ 324)
#endif
#ifndef __NR_inotify_init1
#define __NR_inotify_init1      (__NR_Linux+ 329)
#endif
#ifndef __NR_fanotify_init
#define __NR_fanotify_init      (__NR_Linux+ 336)
#endif
#ifndef __NR_fanotify_mark
#define __NR_fanotify_mark      (__NR_Linux+ 337)
#endif
#endif

#endif
