#include     <stdio.h>      /*标准输入输出定义*/
#include     <unistd.h>     /*Unix标准函数定义*/
#include     <sys/types.h>  /**/
#include     <sys/stat.h>   /**/
#include     <fcntl.h>      /*文件控制定义*/
#include     <termios.h>    /*PPSIX终端控制定义*/
#include     <errno.h>      /*错误号定义*/
#include     <sys/ioctl.h>
#include     <ctype.h>
#include     <string.h>
#include	 <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/un.h>

#include <jni.h>
#include <linux/netlink.h>
#include <android/log.h>
#include <dirent.h>
#include "../include/utils.h"
#include "serial.h"

#define MAX_BUFF 2048

/**
 * 事件的入口函数，静态函数只能在本文件中调用
 */
 int kkserial_event(HKKP env,HKKP obj,int code,char *pszFormat,...)
{
	char pszDest[MAX_BUFF];
	va_list args;

	va_start(args, pszFormat);
	vsnprintf(pszDest, sizeof(pszDest), pszFormat, args);
	va_end(args);
	//只有设置了事件回调函数，此函数才会调用事件，否则什么也不做

    return 0;
}

/**
 * 打开串口
 * @param arg 串口参数字符串，字符串格式为:	com=/dev/ttyUSB0(串口设备字符串),s=9600(波特率),p=N(奇偶校验),b=1(停止位),d=8(数据位数)
 */
int kkserial_open(HKKP env,HKKP obj,char *arg)
{
	int fd = com_open(arg);
	if(fd > 0){
		return fd;
	}else{
		return NULL;
	}
}

/**
 *关闭串口
 */
void kkserial_close(HKKP env,HKKP obj,int fd)
{
	if(fd >0){
		com_close(fd);
	}
}

int kkserial_write(HKKP env,HKKP obj,int fd,char *data,int len)
{
	if(fd <= 0 )return FALSE;
	int r = com_write(fd, data, len);
	return r;
}

int kkserial_read(HKKP env,HKKP obj,int fd, int length, char *buf,int timeout)
{
	if(fd <= 0 )return FALSE;
	int r = 0;
	r =  com_recive(fd,buf,length,timeout);
	return r;
}

int kkserial_select(HKKP env,HKKP obj,int fd,int usec)
{
	if(fd <= 0 )return FALSE;
	int r = 0;
	r = com_select(fd,usec);
	return r;
}








