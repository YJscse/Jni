#include "JniTest2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

JNIEXPORT void JNICALL Java_com_gikimi_jni2_JniTest2_show1 (JNIEnv *env, jobject obj)
{
	printf("show1 \n");
}

JNIEXPORT void JNICALL Java_com_gikimi_jni2_JniTest2_show2 (JNIEnv * env, jobject obj, jint a)
{
	printf("show2 %d \n", a);
}

JNIEXPORT void JNICALL Java_com_gikimi_jni2_JniTest2_show3 (JNIEnv *env, jobject obj, jintArray a)
{
	jint* A =NULL;
	A = (*env)->GetIntArrayElements(env, a, NULL);
	if(A == NULL)
	{
		printf("error1 \n");
	}

	printf("show3 : %d %d %d \n", A[0], A[1], A[2]);
}


JNIEXPORT void JNICALL Java_com_gikimi_jni2_JniTest2_show4 (JNIEnv *env, jobject obj, jchar a)
{
	printf("show4 : %c \n", a);
}


JNIEXPORT void JNICALL Java_com_gikimi_jni2_JniTest2_show5 (JNIEnv *env, jobject obj, jcharArray a)
{
	jchar * A = NULL;
	A = (*env)->GetCharArrayElements(env, a, NULL);
	if(A == NULL)
	{
		printf("error2 \n");
	}

	printf("show5 : %c %c %c \n", A[0], A[1], A[2]);
}


JNIEXPORT void JNICALL Java_com_gikimi_jni2_JniTest2_show6__Ljava_lang_String_2 (JNIEnv *env,
jobject obj, jstring a)
{
	char strbuf[128];
	const char * sz = (*env)->GetStringUTFChars(env, a, 0);
	strcpy(strbuf, sz);

	printf("show6 : %s \n", strbuf);

	(*env)->ReleaseStringUTFChars(env, a, sz);
}

JNIEXPORT void JNICALL Java_com_gikimi_jni2_JniTest2_show6__(JNIEnv *env, jobject obj)
{
	jclass cls = (*env)->GetObjectClass(env, obj);

	jmethodID funcM =(*env)->GetMethodID(env, cls, "myFunction", "()V");

	if(funcM == 0)
	{
		printf("Method Call Fail. \n");
	}
	else
	{
		printf("Method Call Success. \n");

		(*env)->CallVoidMethod(env, obj, funcM);
	}

}

