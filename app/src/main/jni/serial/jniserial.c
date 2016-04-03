#include <jni.h>
#include <stdio.h>      /*标准输入输出定义*/
#include <stdlib.h>
#include <android/log.h>
#include "com_androidex_plugins_serial.h"
#include "serial.h"

jint Serial_OnLoad(JavaVM* vm, void* reserved)
{
	return JNI_VERSION_1_4;
}

void Serial_OnUnload(JavaVM* vm, void* reserved)
{
}

JNIEXPORT jint JNICALL Java_com_androidex_plugins_kkserial_open
(JNIEnv *env, jobject this, jstring strarg)
{
    int fd = 0;
    char *charg = (char *)(*env)->GetStringUTFChars(env, strarg, 0);

    fd = kkserial_open(env,this,charg);
    (*env)->ReleaseStringUTFChars(env, strarg, charg);
    return fd;
}

/*
 * Class:     com_eztor_plugins_serial
 * Method:    serial_select
 * Signature: (III)I
 */
JNIEXPORT jint JNICALL Java_com_eztor_plugins_kkserial_select
        (JNIEnv *env, jobject this, jint fd, jint usec)
{
    int r = kkserial_select(env,this,fd,usec);
    return r;
}

JNIEXPORT jbyteArray JNICALL Java_com_androidex_plugins_kkserial_read
        (JNIEnv *env, jobject this, jint fd, jint length, jint timeout)
{
    char *buf;

    if(length <= 0 || length > MAX_READLEN)
        length = MAX_READLEN;
    buf = malloc(length);
    if(buf){
        memset(buf,0,sizeof(buf));
        int len = kkserial_read(env,this,fd, length, buf,timeout);
        if(len > 0){
            jbyte* byte = (jbyte*)buf;
            jbyteArray jarray = (*env)->NewByteArray(env,len);
            (*env)->SetByteArrayRegion(env,jarray, 0, len, byte);
            return jarray;
        }
        free(buf);
    }
    return NULL;
}

JNIEXPORT jint JNICALL Java_com_androidex_plugins_kkserial_write
        (JNIEnv *env, jobject this, jint fd, jbyteArray data,jint len)
{
    jbyte * arrayBody = (*env)->GetByteArrayElements(env,data,0);
    char* szdata = (char*)arrayBody;

    int r = kkserial_write(env,this,fd,szdata,len);
    (*env)->ReleaseByteArrayElements(env,data, arrayBody,0);
    return r;
}

JNIEXPORT jint JNICALL Java_com_androidex_plugins_kkserial_close
    (JNIEnv *env, jobject this,jint fd)
{
    kkserial_close(env,this,fd);
	return 0;
}

