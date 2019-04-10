
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/device.h>

 
MODULE_LICENSE("GPL");

struct cdev cdev;

dev_t devno;

static const struct file_operations mem_fops =
{
};

/*设备驱动模块加载函数*/
static int  lzdev_init(void)
{
  /*初始化cdev结构*/
  cdev_init(&cdev, &mem_fops);
  
  /* 注册字符设备 */
  alloc_chrdev_region(&devno, 0, 2, "lzmdev");
  cdev_add(&cdev, devno, 2);
  return 0;
}
 
/*模块卸载函数*/
static void  lzdev_exit(void)
{
  cdev_del(&cdev);   /*注销设备*/
  unregister_chrdev_region(devno, 2); /*释放设备号*/
}
 
module_init(lzdev_init);
module_exit(lzdev_exit);