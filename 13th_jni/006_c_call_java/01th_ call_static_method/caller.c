#include <stdio.h>
#include <jni.h>



JNIEnv create_vm(JavaVM** jvm,JNIEnv** env){

	//JavaVM* jvm;
	//JNIEnv* env;

	JavaVMInitArgs args;
	JavaVMOption options[1];

	args.version=JNI_VERSION_1_4;
	args.nOptions=1;

	options[0].optionString = "-Djava.class.path=./";

	args.options=options;
	args.ignoreUnrecognized = JNI_FALSE;
	return JNI_CreateJavaVM(jvm,(void**)env,&args);



}




int main(int argc,char *argv[])
{


	JavaVM* jvm;
	JNIEnv* env;

	jclass cls;
	int ret=0;

	jmethodID mid;


	//1.创建虚拟机

	if(create_vm(&jvm,&env)){
		printf("cant not create jvm\n");
		return -1;
	}
	

	//2.属于那个类
	cls=(*env)->FindClass(env,"hello");
	if(cls==NULL){
		printf("cant not find hello class\n");
		ret=-1;
		goto destroy;
	}
	


	
	//3.创建一个类

	//4.调用方法
	mid =(*env)->GetStaticMethodID(env,cls,"main","([Ljava/lang/String;)V");
	if(mid==NULL){
		ret=-1;	
		printf("can not get method\n");
		goto destroy;
	}

	(*env)->CallStaticVoidMethod(env,cls,mid,NULL);

	
/**

	1.创建虚拟机
	2.属于那个类
	3.创建一个类
	4.调用方法
		4-1获得方法
		4-2创建参数
		4-3调用方法

**/
destroy:
	(*jvm)->DestroyJavaVM(jvm);
	return ret;
}




































