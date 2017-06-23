class JniTest1
{
	static
	{
		System.loadLibrary("JniTest1");
	}

	public static void main(String[] args)
	{
		JniTest1 jni = new JniTest1();

		jni.printHello();
	}

	public native void printHello();
}