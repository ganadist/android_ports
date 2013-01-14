#ifndef __READAHEAD_MISSING_H__
#define __READAHEAD_MISSING_H__

#ifndef FS_IOC_FIEMAP
#include <linux/fs.h>
#include <linux/fiemap.h>
#define FS_IOC_FIEMAP           _IOWR('f', 11, struct fiemap)
#endif

#ifndef BTRFS_IOCTL_MAGIC
#define BTRFS_IOCTL_MAGIC 0x94
#endif

#ifndef BTRFS_PATH_NAME_MAX
#define BTRFS_PATH_NAME_MAX 4087
#endif

struct btrfs_ioctl_vol_args {
            int64_t fd;
                    char name[BTRFS_PATH_NAME_MAX + 1];
};

#ifndef BTRFS_IOC_DEFRAG
#define BTRFS_IOC_DEFRAG _IOW(BTRFS_IOCTL_MAGIC, 2, struct btrfs_ioctl_vol_args)
#endif

#ifndef BTRFS_SUPER_MAGIC
#define BTRFS_SUPER_MAGIC 0x9123683E
#endif

#endif
