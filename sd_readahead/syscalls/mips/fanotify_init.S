/* autogenerated by gensyscalls.py */
#include <machine/asm.h>
#include "syscall_no.h"
    .text
    .globl fanotify_init
    .align 4
    .ent fanotify_init

fanotify_init:
    .set noreorder
    .cpload $t9
    li $v0, __NR_fanotify_init
    syscall
    bnez $a3, 1f
    move $a0, $v0
    j $ra
    nop
1:
    la $t9,__readahead_set_errno
    j $t9
    nop
    .set reorder
    .end fanotify_init
