#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/types.h>
#include<linux/kdev_t.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#include<linux/device.h>
#include<linux/time.h>
#include<linux/random.h>
#include "chardev.h"
#define Device_Name "/dev/imu_char"

static dev_t Major_Number;
static struct cdev c_dev;
static struct class *cls;

static int device_open(struct inode *inode, struct file *file)
{
	printk (KERN_INFO "%s opened\n",Device_Name);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "%s close\n",Device_Name);
	return 0;
}

void  my_read(struct file *f,char __user *buffer, size_t length, loff_t *off)
{

       printk(KERN_INFO pratyush char reading...\n");
}

void  my_write(struct file *f,char __user *buffer, size_t length, loff_t *off)
{

       printk(KERN_INFO pratyush char writing...\n");
}


/*declaring ioctl*/
static long device_ioctl(struct file *file,unsigned int num,unsigned long ioctl_param)
{
 int value;

switch (num)
{
case Gyro_Xaxis:
value=num+24;
break;

case Gyro_Yaxis:
value=num*24;
break;

case Gyro_Zaxis:
value=num+4;
break;

case Acc_Xaxis:
value=num-6;
break;

case Acc_Yaxis:
value=num+33;
break;

case Acc_Zaxis:
value=num%2;
break;

case Magneto_Xaxis:
value=num+9;
break;

case Magneto_Yaxis:
value=num+8;
break;

case Magneto_Zaxis:
value=num+50;
break;

case barometer:
value=num-4;
break;

default:
return -1;
}
printk(KERN_INFO "%s has parameter=%d and value=%d\n",Device_Name, num, value);
return value;


}

static struct file_operations file_op=
{
	.owner= THIS_MODULE,
	.open= device_open,
	.release= device_release,
	.read= my_read,
	.write= my_write,
        .unlocked_ioctl=device_ioctl


};

static int __init device_init(void)
{
	printk(KERN_INFO pratyushchar registered\n");
        
	if(alloc_chrdev_region(&Major_Number,0,10,pratyush assignment1")<0)
	{
		return -1;
	}
         printk(KERN_INFO "Major=%d\n",MAJOR(Major_Number));
	if ((cls=class_create(THIS_MODULE,pratyush chardrv"))==NULL)
	{
		unregister_chrdev_region(Major_Number,10);
		return -1;
	}
	if (device_create(cls,NULL,Major_Number,NULL,"imu_char")==NULL)
	{
		class_destroy(cls);
		unregister_chrdev_region(Major_Number,10);
		return -1;
	}

	cdev_init(&c_dev,&file_op);
	if(cdev_add(&c_dev,Major_Number,10)==-1)
	{
		device_destroy(cls,Major_Number);
		class_destroy(cls);
		unregister_chrdev_region(Major_Number,10);
	}
	return 0;
}

static void __exit device_exit(void)
{
	cdev_del(&c_dev);
	device_destroy(cls,Major_Number);
	class_destroy(cls);
	unregister_chrdev_region(Major_Number,10);
	printk(KERN_INFO pratyush char unregistered\n");
}

module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Twinkle");



