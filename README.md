# G547
Block Device driver (Disk on file)

| Download the main.c and Makefile

| Go to the directory in which code is downloaded and give the command $ make all

| Insert the module using sudo insmod main.ko

| Check if module is loaded using lsmod command

| Check the partition info using cat /proc/partitions also check using ls -l /dev/dof* or sudo fdisk -l

| We have created 2 logical Parititions of the Device(/dev/dof1 & /dev/dof2)

| Take root access using sudo -s command

| Write into disk use cat > /dev/dof ,type something & press enter to read back from the disk on command line use command xxd /dev/dof | less

| Remove the module using sudo rmmod main.ko
