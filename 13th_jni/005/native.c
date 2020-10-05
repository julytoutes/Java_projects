#include <stdio.h>
#include <stdlib.h>
#include "jni.h"///usr/Java/jdk1.8.0_261/include
#if 0


typedef struct {

	char *name;
	char *signature;
	void *fnPtr;
}JNINativeMethod;


#endif

/**
jstring JNICALL c_hello(JNIEnv *env,jobject cls,jstring str)
{
	printf("Hello world! val = %d\n",m);
	return 100;
}

**/



/*
jstring c_hello(JNIEnv *env,jobject cls,jstring str)
{
	//printf("Hello world! val = %d\n",m);
	//return 100;

	char buf[128]={"Ret String from C str"};
	const jbyte *cstr;
	cstr=(*env)->GetStringUTFChars(env,str,NULL);
	if(cstr==NULL)
	{
		return NULL;
	}
	printf("Get String from java str:%s\n",cstr);
	(*env)->ReleaseStringUTFChars(env,str,cstr);
	

	return (*env)->NewStringUTF(env,buf);
	

}
*/

/**
jint c_hello(JNIEnv *env, jobject cls, jintArray array)
{
	jint *arr;
	jint i; 
	jint sum=0;
	arr=(*env)->GetIntArrayElements(env,array,NULL);
	if(arr==NULL)
	{
		return 0;
	}
	for(i=0;i<(*env)->GetArrayLength(env,array);i++)
	{
		sum+=arr[i];
	}

	(*env)->ReleaseIntArrayElements(env,array,arr,0);
	return sum;
	
}
**/

jintArray c_hello(JNIEnv *env, jobject cls, jintArray arr){

	jint *carr;
	jint *other_arr;
	jintArray rarr;
	int i;
	int n=0;
	carr=(*env)->GetIntArrayElements(env,arr,NULL);
	if(carr==NULL){
		return 0;
	}
	n=(*env)->GetArrayLength(env,arr);
	other_arr=(void *)malloc(sizeof(jint)*n);
	if(other_arr == NULL){
		(*env)->ReleaseIntArrayElements(env,arr,carr,0);
		return NULL;	
	}


	for(i=0;i<n;i++){
		other_arr[i]=carr[n-1-i];
	}

	(*env)->ReleaseIntArrayElements(env,arr,carr,0);

	//构造jintArray

	rarr=(*env)->NewIntArray(env,n);
	if(rarr==NULL){
		return 0;
	}


	(*env)->SetIntArrayRegion(env,rarr,0,n,other_arr);
	free(other_arr);
	return rarr;
	
}




static const JNINativeMethod methods[]={
	{"hello","([I)[I",(void*)c_hello}
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


































