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
#include "aexparams.h"

/**
 * 获取参数值
 * @param addr : 参数存放的地址
 * @param value : 返回参数值
 * @param vsize : 参数值的大小
 * @return : 参数值的大小,小于等于0表示错误
 */
int getAndroidExParam(HKKP env,HKKP obj,const char *addr,char *value,int vsize)
{
    int r = 0;
    int fd = open(addr,O_RDONLY);

    memset(value,0,vsize);
    if(fd > 0){
        r = read(fd,value,vsize);
        close(fd);
    }
    return r;
}

/*
 * Method:    setAndroidExParam
 * @param addr : 参数存放的地址
 * @param value : 参数值
 * @param vsize : 参数值的长度
 */
int setAndroidExParam(HKKP env,HKKP obj,const char *addr,const char *value,int vsize)
{
    int r = 0;
    int fd = open(addr,O_RDWR);

    if(fd > 0){
        r = write(fd,value,vsize);
        close(fd);
    }
    return r;
}

/*
 * Method:    getUUID
 */
int getUUID(HKKP env,HKKP obj,char *value,int vsize)
{
    int r = 0;
    int fd = open(aexp_uuid,O_RDONLY);

    memset(value,0,vsize);
    if(fd > 0){
        r = read(fd,value,vsize);
        close(fd);
    }
    return r;

}

/*
 * Method:    getPass
 */
int getPass(HKKP env,HKKP obj,char *value,int vsize)
{
    int r = 0;
    int fd = open(aexp_password,O_RDONLY);

    memset(value,0,vsize);
    if(fd > 0){
        r = read(fd,value,vsize);
        close(fd);
    }
    return r;
}

/*
 * Method:    setPass
 */
int setPass(HKKP env,HKKP obj,const char *value,int vsize)
{
    int r = 0;
    int fd = open(aexp_password,O_RDWR);

    if(fd > 0){
        r = write(fd,value,vsize);
        close(fd);
    }
    return r;

}

/*
 * Method:    getCertsn
 */
int getCertsn(HKKP env,HKKP obj,char *value,int vsize)
{
    int r = 0;
    int fd = open(aexp_certsn,O_RDONLY);

    memset(value,0,vsize);
    if(fd > 0){
        r = read(fd,value,vsize);
        close(fd);
    }
    return r;
}

/*
 * Method:    setCertsn
 */
int setCertsn(HKKP env,HKKP obj,const char *value,int vsize)
{
    int r = 0;
    int fd = open(aexp_certsn,O_RDWR);

    if(fd > 0){
        r = write(fd,value,vsize);
        close(fd);
    }
    return r;
}

/*
 * Method:    getP7cert
 */
int getP7cert(HKKP env,HKKP obj,char *value,int vsize)
{
    int r = 0;
    int fd = open(aexp_p7cert,O_RDONLY);

    memset(value,0,vsize);
    if(fd > 0){
        r = read(fd,value,vsize);
        close(fd);
    }
    return r;
}

/*
 * Method:    setP7cert
 */
int setP7cert(HKKP env,HKKP obj,const char *value,int vsize)
{
    int r = 0;
    int fd = open(aexp_p7cert,O_RDWR);

    if(fd > 0){
        r = write(fd,value,vsize);
        close(fd);
    }
    return r;
}

/*
 * Method:    getNoafter
 */
int getNoafter(HKKP env,HKKP obj,char *value,int vsize)
{
    int r = 0;
    int fd = open(aexp_notafter,O_RDONLY);

    memset(value,0,vsize);
    if(fd > 0){
        r = read(fd,value,vsize);
        close(fd);
    }
    return r;
}

/*
 * Method:    getNobefore
 */
int getNobefore(HKKP env,HKKP obj,char *value,int vsize)
{
    int r = 0;
    int fd = open(aexp_notbefore,O_RDONLY);

    memset(value,0,vsize);
    if(fd > 0){
        r = read(fd,value,vsize);
        close(fd);
    }
    return r;
}

/*
 * Method:    getState
 */
int getState(HKKP env,HKKP obj,char *value,int vsize)
{
    int r = 0;
    int fd = open(aexp_state,O_RDONLY);

    memset(value,0,vsize);
    if(fd > 0){
        r = read(fd,value,vsize);
        close(fd);
    }
    return r;
}

/*
 * Method:    getUserinfo
 */
int getUserinfo(HKKP env,HKKP obj,char *value,int vsize)
{
    int r = 0;
    int fd = open(aexp_userinfo,O_RDONLY);

    memset(value,0,vsize);
    if(fd > 0){
        r = read(fd,value,vsize);
        close(fd);
    }
    return r;
}

/*
 * Method:    setUserinfo
 */
int setUserinfo(HKKP env,HKKP obj,const char *value,int vsize)
{
    int r = 0;
    int fd = open(aexp_userinfo,O_RDWR);

    if(fd > 0){
        r = write(fd,value,vsize);
        close(fd);
    }
    return r;
}









