package com.gikimi.jni2;

public class JniTest2
{
	static
	{
		System.loadLibrary("JniTest2");
	}

	public static void main(String args[])
	{
	
	JniTest2 jni = new JniTest2();

	String a = "ABC";
	int[] b = {1, 2, 3};
	char[] c = {'a', 'b', 'c'};

	System.out.println("Java : " + a);

	jni.show1();
	jni.show2(9);
	jni.show3(b);
	jni.show4('d');
	jni.show5(c);
	jni.show6(a);
	jni.show6();
	
	}

	public void myFunction()
	{
		System.out.println("This is a my function.");
	}

	public native void show1();
	public native void show2(int i);
	public native void show3(int i[]);
	public native void show4(char c);
	public native void show5(char c[]);
	public native void show6(String s);
	public native void show6();
}