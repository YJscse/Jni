#include "JniTest1.h"

JNIEXPORT void JNICALL Java_JniTest1_printHello (JNIEnv * env, jobject obj)
{
	printf("Hello World (JNI) !!!\n");
}