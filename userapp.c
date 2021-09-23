#include "chardev.h"

#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>
#define DEVICE_FILE_NAME "/dev/imu_char"
/////////////////////////////////////////////////////////////////

/* call 1*/

int Gyro_readXaxis(int fd)
{
int ret_val=0;
int message=0;

ret_val=ioctl(fd, Gyro_Xaxis,message);

if(ret_val==0)
{
printf("ioctl_gyro_readXaxis failed: %i\n",ret_val);
exit(-1);
}
printf("Reading in X axis in gyrometer: %d\n",ret_val);
return 0;
}
/*  call 2*/
int Gyro_readYaxis(int fd)
{
int ret_val;
char message[100];

ret_val=ioctl(fd, Gyro_Yaxis,message);

if(ret_val==0)
{
printf("ioctl_gyro_readYaxis failed: %i\n",ret_val);
exit(-1);
}

printf("Reading in y axis in gyrometer: %d\n",ret_val);
return 0;
}

/* call 3*/
int Gyro_readZaxis(int fd)
{
int ret_val;
char message[100];

ret_val=ioctl(fd, Gyro_Zaxis,message);

if(ret_val<0)
{
printf("ioctl_gyro_readZaxis failed: %d\n",ret_val);
exit(-1);
}

printf("Reading in Z axis in gyrometer %d\n",ret_val);
return 0;
}


/* call 4*/
int Accelero_readXaxis(int fd)
{
int ret_val;
char message[100];

ret_val=ioctl(fd, Acc_Xaxis,message);

if(ret_val<0)
{
printf("ioctl_ACCELERO_readXaxis failed: %d\n",ret_val);
exit(-1);
}

printf("Reading in X axis in accelerometer %d\n",ret_val);
return 0;
}

/* call 5*/
int Accelero_readYaxis(int fd)
{
int ret_val;
char message[100];
ret_val=ioctl(fd, Acc_Yaxis,message);

if(ret_val<0)
{
printf("ioctl_ACCELERO_readYaxis failed: %d\n",ret_val);
exit(-1);
}
printf("Reading in y axis in accelerometer %d\n",ret_val);
return 0;
}


/* call 6*/
int Accelero_readZaxis(int fd)
{
int ret_val;
char message[100];
ret_val=ioctl(fd, Acc_Zaxis,message);
if(ret_val<0)
{
printf("ioctl_ACCELERO_readZaxis failed: %d\n",ret_val);
exit(-1);
}
printf("Reading in Z axis in accelerometer %d\n",ret_val);
return 0;
}

/* call 7*/
int Magneto_readXaxis(int fd)
{
int ret_val;
char message[100];
ret_val=ioctl(fd, Magneto_Xaxis,message);
if(ret_val<0)
{
printf("ioctl_MAGNETO_readXaxis failed: %d\n",ret_val);
exit(-1);
}
printf("Reading in X axis in magnetometer %d\n",ret_val);
return 0;
}

/* call 8*/

int Magneto_readYaxis(int fd)
{
 int ret_val;
char message[100];
ret_val=ioctl(fd, Magneto_Yaxis,message);
if(ret_val<0)
{
printf("ioctl_MAGNETO_readYaxis failed: %d\n",ret_val);
exit(-1);
}
printf("Reading in Y axis in magnetometer %d\n",ret_val);
return 0;
}

/* call 9*/
int Magneto_readZaxis(int fd)
{
int ret_val;
char message[100];
ret_val=ioctl(fd, Magneto_Zaxis,message);
if(ret_val<0)
{
printf("ioctl_MAGNETO_readZaxis failed: %d\n",ret_val);
exit(-1);
}
printf("Reading in Z axis in magnetometer %d\n",ret_val);
return 0;
}

/* call 10*/
int barometer_readPressure(int fd,int req_val)
{
int ret_val;
char msg[100];
if (req_val==9)
ret_val=ioctl(fd, barometer, msg);
if(ret_val<0)
{
printf("barometer_readPressure failed with req val: %d %d\n",ret_val,req_val);
exit(-1);
}
printf("Reading in barometer %d\n",ret_val);
return 0;
}

int main()
{
int fd, ret_val;
char *msg="This is user space main program\n";

fd=open(DEVICE_FILE_NAME,O_RDONLY);
printf("%s returns %d\n",DEVICE_FILE_NAME,fd);
if (fd<0)
{
printf("Can't open device file %s\n", DEVICE_FILE_NAME);
exit(-1);
}

Gyro_readXaxis(fd);
Gyro_readYaxis(fd);
Gyro_readZaxis(fd);

Accelero_readXaxis(fd);
Accelero_readYaxis(fd);
Accelero_readZaxis(fd);

Magneto_readXaxis(fd);
Magneto_readYaxis(fd);
Magneto_readZaxis(fd);

Barometer_readPressure(fd,9);

close(fd);
return 0;
}

