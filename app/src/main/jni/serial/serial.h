#ifndef __HSERIAL__
#define __HSERIAL__

#define MAX_READLEN         2048

typedef long                LONG;
typedef unsigned short      WORD;
typedef unsigned long       DWORD;

typedef void* HKKP;

/**
 * 打开，返回句柄
 * @param arg 串口参数字符串，字符串格式为:	com=/dev/ttyUSB0(串口设备字符串),s=9600(波特率),p=N(奇偶校验),b=1(停止位),d=8(数据位数)
 */
int kkserial_open(HKKP env,HKKP obj,char *arg);
void kkserial_close(HKKP env,HKKP obj,int fd);
int kkserial_read(HKKP env,HKKP obj,int fd,int length, char *buf, int timeout);
int kkserial_write(HKKP env,HKKP obj,int fd,char *data,int len);
int kkserial_select(HKKP env,HKKP obj,int fd, int usec);

#endif
