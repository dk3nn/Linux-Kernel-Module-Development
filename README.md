# Linux-Kernel-Module-Development
5 loadable Linux kernel modules built to understand kernel programming, '/proc' file systems, and process management

## Modules
### simple.c
Character device driver module, takes user input parameters 'my_name' and 'my_number' and prints a greeting with with those input values and calculates the GCD on exit

### hello.c
Creates '/proc/hello' that returns "hello world" by calling a kernel function, not by reading an actual file

### jiffies_modules.c
Creates '/proc/jiffies' that displays the current jiffies counter

### seconds_module.c
Creates '/proc/seconds' that shows how many seconds have passed since the module was loaded

### pid.c 
Creates '/proc/pid' in which the use write a PID into, then it reads back the process name, PID, and state. Uses 'pid_task()' to look up a 'task_struct', which contains all the kernel's information about a given process.

## Stack
C, Linux Kernel, VirtualBox, Ubuntu/Bodhi Linux

## Setup
1. Clone repo
''git clone https://github.com/dk3nn/Linux-Kernel-Module-Development.git''
2. Go to project folder
''cd Linux-Kernel-Module-Development''
3. Compile modules
''make''
4. Insert a module
''sudo insmod simple.ko
sudo insmod hello.ko
sudo insmod jiffies_module.ko
sudo insmod seconds_module.ko
sudo insmod pid.ko''
5. Check kernel messages
''dmesg''
6. Read /proc files
''cat /proc/hello
cat /proc/jiffies
cat /proc/seconds''
7. Use pid module
''echo 1 > /proc/pid
cat /proc/pid''
8. Remove modules
''sudo rmmod simple
sudo rmmod hello
sudo rmmod jiffies_module
sudo rmmod seconds_module
sudo rmmod pid''
9. Clean build files
''make clean ''
