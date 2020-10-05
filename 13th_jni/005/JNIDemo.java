









public class JNIDemo
{
	static {
		System.out.println("static()start....");
		System.loadLibrary("native");//编译出一个libnative.so
		System.out.println("static()endl....");

	}
	public native int[] hello(int[] a);
	public static void main(String args[])
	{
		/** 1. load **/
		
		JNIDemo d=new JNIDemo();
		int[] a={1,2,3};
		int[] b=null;
		int i;
		/** 2. map java hello -->c c_hello **/
		
		/** 3. call  **/
		b=d.hello(a);
		for(i=0;i<b.length;i++){
			System.out.println(b[i]);			
		}
		
	}
}
































