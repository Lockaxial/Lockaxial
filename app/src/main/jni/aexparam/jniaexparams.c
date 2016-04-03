#include <jni.h>
#include <stdio.h>      /*标准输入输出定义*/
#include <stdlib.h>
#include <android/log.h>
#include "com_androidex_plugins_kkaexparams.h"
#include "aexparams.h"

/*
 * Class:     com_androidex_plugins_kkaexparams
 * Method:    getAndroidExParam
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_androidex_plugins_kkaexparams_getAndroidExParam
        (JNIEnv *env, jobject this, jstring addr)
{
    char buf[MAX_READLEN];
    int r = 0;
    char *straddr;

    straddr = (char *)(*env)->GetStringUTFChars(env, addr, 0);
    r = getAndroidExParam(env,this,straddr,buf,sizeof(buf));

    (*env)->ReleaseStringUTFChars(env, addr, straddr);
    if(r > 0){
        jchar * pbuf = (jchar *)buf;
        jstring result = (*env)->NewCharArray(env,r);

        (*env)->SetCharArrayRegion(env,result,0,r,pbuf);
        return result; //成功返回读取的字符串
    }
    return NULL;    //失败返回空
}

/*
 * Class:     com_androidex_plugins_kkaexparams
 * Method:    setAndroidExParam
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_androidex_plugins_kkaexparams_setAndroidExParam
        (JNIEnv *env, jobject this , jstring addr, jstring value)
{
    char buf[MAX_READLEN];
    int r = 0;
    char *straddr,*strvalue;

    straddr = (char *)(*env)->GetStringUTFChars(env, addr, 0);
    strvalue = (char *)(*env)->GetStringUTFChars(env, value, 0);
    r = setAndroidExParam(env,this,straddr,strvalue,strlen(strvalue));

    (*env)->ReleaseStringUTFChars(env, addr, straddr);
    (*env)->ReleaseStringUTFChars(env, value, strvalue);
    return r;
}

/*
 * Class:     com_androidex_plugins_kkaexparams
 * Method:    getUUID
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_androidex_plugins_kkaexparams_getUUID
        (JNIEnv *env, jobject this)
{
    char buf[MAX_READLEN];
    int r = 0;

    r = getUUID(env,this,buf,sizeof(buf));

    if(r > 0){
        jchar * pbuf = (jchar *)buf;
        jstring result = (*env)->NewCharArray(env,r);

        (*env)->SetCharArrayRegion(env,result,0,r,pbuf);
        return result; //成功返回读取的字符串
    }
    return NULL;    //失败返回空
}

/*
 * Class:     com_androidex_plugins_kkaexparams
 * Method:    getPass
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_androidex_plugins_kkaexparams_getPass
        (JNIEnv *env, jobject this)
{
    char buf[MAX_READLEN];
    int r = 0;

    r = getPass(env,this,buf,sizeof(buf));

    if(r > 0){
        jchar * pbuf = (jchar *)buf;
        jstring result = (*env)->NewCharArray(env,r);

        (*env)->SetCharArrayRegion(env,result,0,r,pbuf);
        return result; //成功返回读取的字符串
    }
    return NULL;    //失败返回空
}

/*
 * Class:     com_androidex_plugins_kkaexparams
 * Method:    setPass
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_androidex_plugins_kkaexparams_setPass
        (JNIEnv *env, jobject this, jstring value)
{
    char buf[MAX_READLEN];
    int r = 0;
    char *strvalue;

    strvalue = (char *)(*env)->GetStringUTFChars(env, value, 0);
    r = setPass(env,this,strvalue,strlen(strvalue));

    (*env)->ReleaseStringUTFChars(env, value, strvalue);
    return r;
}

/*
 * Class:     com_androidex_plugins_kkaexparams
 * Method:    getCertsn
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_androidex_plugins_kkaexparams_getCertsn
        (JNIEnv *env, jobject this)
{
    char buf[MAX_READLEN];
    int r = 0;

    r = getCertsn(env,this,buf,sizeof(buf));

    if(r > 0){
        jchar * pbuf = (jchar *)buf;
        jstring result = (*env)->NewCharArray(env,r);

        (*env)->SetCharArrayRegion(env,result,0,r,pbuf);
        return result; //成功返回读取的字符串
    }
    return NULL;    //失败返回空
}

/*
 * Class:     com_androidex_plugins_kkaexparams
 * Method:    setCertsn
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_androidex_plugins_kkaexparams_setCertsn
        (JNIEnv *env, jobject this, jstring value)
{
    char buf[MAX_READLEN];
    int r = 0;
    char *strvalue;

    strvalue = (char *)(*env)->GetStringUTFChars(env, value, 0);
    r = setCertsn(env,this,strvalue,strlen(strvalue));

    (*env)->ReleaseStringUTFChars(env, value, strvalue);
    return r;
}

/*
 * Class:     com_androidex_plugins_kkaexparams
 * Method:    getP7cert
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_androidex_plugins_kkaexparams_getP7cert
        (JNIEnv *env, jobject this)
{
    char buf[MAX_READLEN];
    int r = 0;

    r = getP7cert(env,this,buf,sizeof(buf));

    if(r > 0){
        jchar * pbuf = (jchar *)buf;
        jstring result = (*env)->NewCharArray(env,r);

        (*env)->SetCharArrayRegion(env,result,0,r,pbuf);
        return result; //成功返回读取的字符串
    }
    return NULL;    //失败返回空
}

/*
 * Class:     com_androidex_plugins_kkaexparams
 * Method:    setP7cert
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_androidex_plugins_kkaexparams_setP7cert
        (JNIEnv *env, jobject this, jstring value)
{
    char buf[MAX_READLEN];
    int r = 0;
    char *strvalue;

    strvalue = (char *)(*env)->GetStringUTFChars(env, value, 0);
    r = setP7cert(env,this,strvalue,strlen(strvalue));

    (*env)->ReleaseStringUTFChars(env, value, strvalue);
    return r;
}

/*
 * Class:     com_androidex_plugins_kkaexparams
 * Method:    getNoafter
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_androidex_plugins_kkaexparams_getNoafter
        (JNIEnv *env, jobject this)
{
    char buf[MAX_READLEN];
    int r = 0;

    r = getNoafter(env,this,buf,sizeof(buf));

    if(r > 0){
        jchar * pbuf = (jchar *)buf;
        jstring result = (*env)->NewCharArray(env,r);

        (*env)->SetCharArrayRegion(env,result,0,r,pbuf);
        return result; //成功返回读取的字符串
    }
    return NULL;    //失败返回空
}

/*
 * Class:     com_androidex_plugins_kkaexparams
 * Method:    getNobefore
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_androidex_plugins_kkaexparams_getNobefore
        (JNIEnv *env, jobject this)
{
    char buf[MAX_READLEN];
    int r = 0;

    r = getNobefore(env,this,buf,sizeof(buf));

    if(r > 0){
        jchar * pbuf = (jchar *)buf;
        jstring result = (*env)->NewCharArray(env,r);

        (*env)->SetCharArrayRegion(env,result,0,r,pbuf);
        return result; //成功返回读取的字符串
    }
    return NULL;    //失败返回空
}

/*
 * Class:     com_androidex_plugins_kkaexparams
 * Method:    getState
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_androidex_plugins_kkaexparams_getState
        (JNIEnv *env, jobject this)
{
    char buf[MAX_READLEN];
    int r = 0;

    r = getState(env,this,buf,sizeof(buf));

    if(r > 0){
        jchar * pbuf = (jchar *)buf;
        jstring result = (*env)->NewCharArray(env,r);

        (*env)->SetCharArrayRegion(env,result,0,r,pbuf);
        return result; //成功返回读取的字符串
    }
    return NULL;    //失败返回空
}

/*
 * Class:     com_androidex_plugins_kkaexparams
 * Method:    getUserinfo
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_androidex_plugins_kkaexparams_getUserinfo
        (JNIEnv *env, jobject this)
{
    char buf[MAX_READLEN];
    int r = 0;

    r = getUserinfo(env,this,buf,sizeof(buf));

    if(r > 0){
        jchar * pbuf = (jchar *)buf;
        jstring result = (*env)->NewCharArray(env,r);

        (*env)->SetCharArrayRegion(env,result,0,r,pbuf);
        return result; //成功返回读取的字符串
    }
    return NULL;    //失败返回空
}

/*
 * Class:     com_androidex_plugins_kkaexparams
 * Method:    setUserinfo
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_androidex_plugins_kkaexparams_setUserinfo
        (JNIEnv *env, jobject this, jstring value)
{
    char buf[MAX_READLEN];
    int r = 0;
    char *strvalue;

    strvalue = (char *)(*env)->GetStringUTFChars(env, value, 0);
    r = setUserinfo(env,this,strvalue,strlen(strvalue));

    (*env)->ReleaseStringUTFChars(env, value, strvalue);
    return r;
}

