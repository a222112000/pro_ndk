package com.example.firstndk;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.example.firstndk.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'firstndk' library on application startup.
    static {
        System.loadLibrary("firstndk");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        TextView tv1 = binding.sampleText1;
        TextView  tv2 = binding.sampleText2;
        tv.setText(String.valueOf(numbersA()));
        tv1.setText(loopOne());
        tv2.setText(process());

    }

    public String getName(){
        return "sam";
    }

    /**
     * A native method that is implemented by the 'firstndk' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native String test();
    public native int textInt();
    private native char nameTest();
    private native int mathTest();
    private native boolean testBool();
    private native String switch1();
    private native String loopOne();
    private native int whileloop();
    private native int numbersA();
    private native String process();
}
