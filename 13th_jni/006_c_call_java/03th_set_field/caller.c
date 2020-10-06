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
	jmethodID cid;
	jobject job;
	jstring jstr;

	jfieldID nameid;
	jfieldID ageid;
	
	int r;


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
		//获取
	
	cid=(*env)->GetMethodID(env,cls,"<init>","()V");
	if(cid==NULL){
		printf("(*env)->GetMethodID(env,cls,<init>,()V)");
		ret=-1;
		goto destroy;
	}

	job=(*env)->NewObject(env,cls,cid);
	if(job==NULL){

		printf("(*env)->Newobject(env,cls,cid)\n");
		ret=-1;
		goto destroy;
		
	}


	nameid=(*env)->GetFieldID(env,cls,"name","Ljava/lang/String;");
	if(nameid==NULL){
		printf("(*env)->GetFieldID(env,cls,name,Ljava/lang/String;)\n");
		ret=-1;
		goto destroy;
	}
	
	jstr=(*env)->NewStringUTF(env,"bill");
	(*env)->SetObjectField(env,job,nameid,jstr);

	ageid=(*env)->GetFieldID(env,cls,"age","I");
	if(ageid==NULL){
		printf("(*env)->GetFieldID(env,cls,name,Ljava/lang/String;)\n");
		ret=-1;
		goto destroy;
	}
	(*env)->SetIntField(env,job,ageid,10);





	

	//4.调用方法
	mid =(*env)->GetMethodID(env,cls,"sayhello_to","(Ljava/lang/String;)I");
	if(mid==NULL){
		ret=-1;	
		printf("can not get method\n");
		goto destroy;
	}
	
	jstr=(*env)->NewStringUTF(env,"febhouxr");
	r=(*env)->CallIntMethod(env,job,mid,jstr);
	printf("ret:%d\n",r);

	
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




































