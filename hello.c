#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

MODULE_AUTHOR("Moroz Denis IV-81");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint count = 1;
module_param(count, uint, S_IRUGO);
MODULE_PARM_DESC(count, "Amount of times hello world message should be repeated");

static int __init hello_init(void)
{
	uint i;

	if (count == 0) {
		printk(KERN_WARNING "WARNING the count is 0\n");
	} else if (count >= 5 && count <= 10) {
		printk(KERN_WARNING "WARNING the count in range of 5,10\n");
	} else if (count > 10) {
		printk(KERN_ERR "The count is greater than 10\n");
		return -EINVAL;
	}

	for (i = 0; i < count; i++) {
		printk(KERN_INFO "Hello, world!\n");
	}

	return 0;

}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);
