#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>

#include <linux/types.h>

MODULE_AUTHOR("Dudka Maksym <dudkamv@gmail.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint numberOfRepeats = 1;
module_param(numberOfRepeats,uint,0);
MODULE_PARM_DESC(numberOfRepeats, "The amount of times to print hello world");

static int __init initter(void)
{
  uint i = 0;

  printk(KERN_INFO "numberOfRepeats: %d\n", numberOfRepeats);

  if(numberOfRepeats == 0) {
    printk(KERN_WARNING "The numberOfRepeats is 0");
  }else if(numberOfRepeats >=5 && numberOfRepeats <= 10) {
    printk(KERN_WARNING "The numberOfRepeats is between 5 and 10");
  } else if(numberOfRepeats > 10) {
    printk(KERN_ERR "The numberOfRepeats is greater than 10");
    return -EINVAL;
  }

  for(i = 0; i < numberOfRepeats; i++){
    printk(KERN_INFO "Hello, world!\n");
  }
  return 0;
}

static void __exit exitter(void)
{
  /* Do nothing here right now */
}

module_init(initter);
module_exit(exitter);
