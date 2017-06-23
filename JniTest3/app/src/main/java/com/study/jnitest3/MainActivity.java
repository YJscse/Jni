package com.study.jnitest3;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends Activity {

    long start_time;
    long end_time ;
    int ret;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_activity);

        start_time = System.currentTimeMillis();
        ret = java_calc();
        end_time = System.currentTimeMillis();

        Log.d("study", "Java : " + (end_time - start_time) + "\n" +
                "Result : " + ret);


        start_time = System.currentTimeMillis();
        MyNdkTest ndk = new MyNdkTest();
        ret = ndk.nativeCalc();
        end_time = System.currentTimeMillis();

        Log.d("study", "Native : " + (end_time - start_time) + "\n" +
                "Result : " + ret);
    }

     public int java_calc() {
    int count = 3;
    int i = 0;
    for (i = 0; i < 10000000; i++) {
        count = count * 2 / 3 + 5 - 1;
    }
    return count;

}
}

