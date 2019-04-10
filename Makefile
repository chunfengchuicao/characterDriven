obj-m := cdev_moudle.o
KDIR := /usr/src/linux-headers-4.15.0-47-generic/
PWD  :=$(shell pwd)
all:
	make -C $(KDIR) M=$(PWD) modules 
clean:
	rm -f *.ko *.o *.mod.o *.mod.c *.symvers *.bak *.order

