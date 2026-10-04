/*
 * SysMonX character-device DRIVER STARTER.
 *
 * This is intentionally a minimal learning skeleton.
 * The capstone requirement is for the student to understand,
 * redesign and complete the driver rather than submit AI-generated code.
 */

#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "sysmon"

static dev_t sysmon_dev;
static struct cdev sysmon_cdev;

static int sysmon_open(struct inode *inode, struct file *file)
{
    pr_info("sysmon: device opened\n");
    return 0;
}

static int sysmon_release(struct inode *inode, struct file *file)
{
    pr_info("sysmon: device closed\n");
    return 0;
}

static ssize_t sysmon_read(struct file *file, char __user *buffer,
                           size_t len, loff_t *offset)
{
    const char message[] =
        "SysMonX driver starter: implement your own kernel/user interface.\n";
    size_t size = sizeof(message) - 1;

    if (*offset >= size)
        return 0;

    if (len > size - *offset)
        len = size - *offset;

    if (copy_to_user(buffer, message + *offset, len))
        return -EFAULT;

    *offset += len;
    return len;
}

static const struct file_operations sysmon_fops = {
    .owner = THIS_MODULE,
    .open = sysmon_open,
    .read = sysmon_read,
    .release = sysmon_release,
};

static int __init sysmon_init(void)
{
    int ret;

    ret = alloc_chrdev_region(&sysmon_dev, 0, 1, DEVICE_NAME);
    if (ret)
        return ret;

    cdev_init(&sysmon_cdev, &sysmon_fops);
    ret = cdev_add(&sysmon_cdev, sysmon_dev, 1);

    if (ret) {
        unregister_chrdev_region(sysmon_dev, 1);
        return ret;
    }

    pr_info("sysmon: registered major=%d minor=%d\n",
            MAJOR(sysmon_dev), MINOR(sysmon_dev));

    return 0;
}

static void __exit sysmon_exit(void)
{
    cdev_del(&sysmon_cdev);
    unregister_chrdev_region(sysmon_dev, 1);
    pr_info("sysmon: unloaded\n");
}

module_init(sysmon_init);
module_exit(sysmon_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Student");
MODULE_DESCRIPTION("SysMonX character device starter");
