#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tora0615");
MODULE_DESCRIPTION("A simple kernel module example for Linux");

/* Functions define */
static int __init hello_init(void) {
    // This is a function that will be called when the module is loaded
    printk(KERN_INFO "Hello, Kernel!\n");
    return 0;  // success
}
static void __exit hello_exit(void) {
    // This is a function that will be called when the module is removed
    printk(KERN_INFO "Goodbye, Kernel!\n");
}

/* register function to the kernel */
module_init(hello_init);
module_exit(hello_exit);
