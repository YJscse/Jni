package com.study.jnitest3;

public class MyNdkTest {

    // Speed 차이를 알아보기 위한 예제
    static {
        System.loadLibrary("MyNdkTest");
    }

    // 네이티브 메서드는 이름에 "_"를 사용하면 안된다.
    public native int nativeCalc();
}
