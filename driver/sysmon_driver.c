/* Learning starter: complete the driver protocol yourself. */
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#define DEVICE_NAME "sysmon"
static dev_t devno; static struct cdev cdev;
static int open_fn(struct inode*i,struct file*f){pr_info("sysmon: open\n");return 0;}
static int release_fn(struct inode*i,struct file*f){pr_info("sysmon: release\n");return 0;}
static ssize_t read_fn(struct file*f,char __user*b,size_t len,loff_t*off){const char msg[]="SysMonX driver starter. Implement your own protocol.\n"; size_t n=sizeof(msg)-1; if(*off>=n)return 0; if(len>n-*off)len=n-*off; if(copy_to_user(b,msg+*off,len))return -EFAULT; *off+=len; return len;}
static const struct file_operations fops={.owner=THIS_MODULE,.open=open_fn,.read=read_fn,.release=release_fn};
static int __init init_fn(void){int r=alloc_chrdev_region(&devno,0,1,DEVICE_NAME); if(r)return r; cdev_init(&cdev,&fops); r=cdev_add(&cdev,devno,1); if(r) unregister_chrdev_region(devno,1); pr_info("sysmon: major=%d minor=%d\n",MAJOR(devno),MINOR(devno)); return r;}
static void __exit exit_fn(void){cdev_del(&cdev);unregister_chrdev_region(devno,1);pr_info("sysmon: unloaded\n");}
module_init(init_fn); module_exit(exit_fn); MODULE_LICENSE("GPL"); MODULE_AUTHOR("Student"); MODULE_DESCRIPTION("SysMonX character device learning starter");
