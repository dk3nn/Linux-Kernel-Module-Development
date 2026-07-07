obj-m += simple.o
obj-m += hello.o
obj-m += jiffies_module.o
obj-m += seconds_module.o
obj-m += pid.o

all:
  make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
  
clean:
  make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
