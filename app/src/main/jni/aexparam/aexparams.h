#ifndef __HAEXPARAM__
#define __HAEXPARAM__

#define MAX_READLEN         2048

typedef long                LONG;
typedef unsigned short      WORD;
typedef unsigned long       DWORD;

typedef void* HKKP;

#define aexp_flag0           "/sys/class/androidex_parameters/androidex/flag0"
#define aexp_flag1           "/sys/class/androidex_parameters/androidex/flag1"
#define aexp_uuid            "/sys/class/androidex_parameters/androidex/uuid"
#define aexp_password        "/sys/class/androidex_parameters/androidex/password"
#define aexp_certsn          "/sys/class/androidex_parameters/androidex/certsn"
#define aexp_p7cert          "/sys/class/androidex_parameters/androidex/p7cert"
#define aexp_notafter        "/sys/class/androidex_parameters/androidex/notafter"
#define aexp_notbefore       "/sys/class/androidex_parameters/androidex/notbefore"
#define aexp_state           "/sys/class/androidex_parameters/androidex/state"
#define aexp_userinfo        "/sys/class/androidex_parameters/androidex/userinfo"

int getAndroidExParam(HKKP env,HKKP obj,const char *addr,char *value,int vsize);
int setAndroidExParam(HKKP env,HKKP obj,const char *addr,const char *value,int vsize);
int getUUID(HKKP env,HKKP obj,char *value,int vsize);
int getPass(HKKP env,HKKP obj,char *value,int vsize);
int setPass(HKKP env,HKKP obj,const char *value,int vsize);
int getCertsn(HKKP env,HKKP obj,char *value,int vsize);
int setCertsn(HKKP env,HKKP obj,const char *value,int vsize);
int getP7cert(HKKP env,HKKP obj,char *value,int vsize);
int setP7cert(HKKP env,HKKP obj,const char *value,int vsize);
int getNoafter(HKKP env,HKKP obj,char *value,int vsize);
int getNobefore(HKKP env,HKKP obj,char *value,int vsize);
int getState(HKKP env,HKKP obj,char *value,int vsize);
int getUserinfo(HKKP env,HKKP obj,char *value,int vsize);
int setUserinfo(HKKP env,HKKP obj,const char *value,int vsize);

#endif
