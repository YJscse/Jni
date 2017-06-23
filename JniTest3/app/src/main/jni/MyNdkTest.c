#include "MyNdkTest.h"
 
jint Java_com_study_jnitest3_MyNdkTest_nativeCalc (JNIEnv * env, jobject obj)
{
    int count = 3;
    int i = 0;
    for (i=0; i<10000000; i++) {
        count = count * 2 / 3 + 5 - 1;
    }
    return count;
}
