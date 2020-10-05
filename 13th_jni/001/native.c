#include <stdio.h>
#include "jni.h"///usr/Java/jdk1.8.0_261/include
#if 0


typedef struct {

	char *name;
	char *signature;
	void *fnPtr;
}JNINativeMethod;


#endif

void c_hello(JNIEnv *env,jobject cls)
{
	printf("Hello world\n");
}


static const JNINativeMethod methods[]={
	{"hello","()V",(void*)c_hello}
	{}
};





JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *jvm,void *reserved) /* System.loadLibrary */
{
	JNIEnv *env;
	jclass cls;

	if((*jvm)->GetEnv(jvm,(void **)&env,JNI_VERSION_1_4))
	{
		return JNI_ERR;
	}
	cls=(*env)->FindClass(env,"JNIDemo");
	if(cls==NULL)
	{
		return JNI_ERR;
	}
	
	/** 2. map java hello -->c c_hello **/

	if((*env)->RegisterNatives(env,cls,methods,1) < 0)
	{
		return JNI_ERR;		
	}

	
	return JNI_VERSION_1_4;
	
}


































