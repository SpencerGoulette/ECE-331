#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

int init_module(void)
{
	printk(KERN_NOTICE "wwv found\n");
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_NOTICE "Good Bye\n");
}
