









public class JNIDemo
{
	static {
		System.out.println("static()start....");
		System.loadLibrary("native");//编译出一个libnative.so
		System.out.println("static()endl....");

	}
	public native String hello(String str);
	public static void main(String args[])
	{
		/** 1. load **/
		
		JNIDemo d=new JNIDemo();
		
		/** 2. map java hello -->c c_hello **/
		
		/** 3. call  **/
		System.out.println(d.hello("this is java"));
	}
}
































