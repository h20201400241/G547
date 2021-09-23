#ifndef CHARDEV_H
#define CHARDEV_H

#include <linux/ioctl.h>

#define Major_Numberber 249


#define Gyro_Xaxis _IOR(Major_Number, 0, int)
#define Gyro_Yaxis _IOR(Major_Number,1,int)
#define Gyro_Zaxis _IOR(Major_Number,2,int)

#define Acc_Xaxis _IOR(Major_Number,3,int)
#define Acc_Yaxis _IOR(Major_Number,4,int)
#define Acc_Zaxis _IOR(Major_Number,5,int)

#define Magneto_Xaxis _IOR(Major_Number,6,int)
#define Magneto_Yaxis _IOR(Major_Number,7,int)
#define Magneto_Zaxis _IOR(Major_Number,8,int)

#define barometer _IOR(Major_Number,9,int)

#define DEVICE_FILE_NAME "/dev/imu_char"
#endif
