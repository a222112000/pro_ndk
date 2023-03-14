#include <jni.h>
#include <string>
using namespace std;

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_firstndk_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL Java_com_example_firstndk_MainActivity_test(JNIEnv* env,jobject obj){
    string test = "This is a test";
    return env->NewStringUTF(test.c_str());
}

extern "C" JNIEXPORT jint JNICALL Java_com_example_firstndk_MainActivity_textInt(
        JNIEnv* env, jobject
        ){
   const int test = 3;
    int num = 5;
    int te = test + num;
    return te;
}

extern "C" JNIEXPORT jchar Java_com_example_firstndk_MainActivity_nameTest(
        JNIEnv* env,jobject
        ){
    string firstname = "sam";
    string lastname = " Alselwi";
    char fullname = firstname.append(lastname)[0];
    return fullname;
}

extern "C" jint Java_com_example_firstndk_MainActivity_mathTest(JNIEnv* env, jobject){
    int num1 = 5;
    int num2 = 9;
    return sqrt(num2);
}

extern "C" jboolean Java_com_example_firstndk_MainActivity_testBool(
        JNIEnv* env, jobject
        ){
    int x = 9;
    int y = 9;
    bool t;
    if(x > y){
        t = false;
    }else if(x < y){
        t = true;
    }else{
        t = 1;
    }
    return t;
}

extern "C" jstring Java_com_example_firstndk_MainActivity_switch1(
        JNIEnv* env, jobject
        ){
    int day = 2;
    string  nameofDay;
    switch (day) {
        case 1:
            nameofDay = "Monday";
            break;
        case 2:
            nameofDay = "Tuesday";
            break;
        case 3:
            nameofDay = "Wednesday";
            break;
        case 4:
            nameofDay = "Thursday";
            break;
        case 5:
            nameofDay = "Friday";
            break;
        case 6:
            nameofDay = "Saturday";
            break;
        default: nameofDay= "Sunday";
    }
    return env->NewStringUTF(nameofDay.c_str());
}

extern "C" jstring JNICALL Java_com_example_firstndk_MainActivity_loopOne(JNIEnv* env,jobject){
    string name = "kjhjkhcdjjzhhcjzbczxjbjzbzjbzjkjkchzkxjch";
    string thisTest;
    int i = 0;
    while(name.length()> i){
        thisTest = name+to_string(i+1);
       i++;
    }
    return env->NewStringUTF(thisTest.c_str());
}

extern "C" jint JNICALL Java_com_example_firstndk_MainActivity_whileloop(
        JNIEnv* env,jobject
        ){

    int x;
    for (int i = 0; i < 5; i++) {
        x = (int) (i + "\n");
    }
    return random();
}

extern "C" jint JNICALL Java_com_example_firstndk_MainActivity_numbersA(
        JNIEnv* env, jobject job
){
    int myNum[5] = {72,43,54,45,34};
    for (int x : myNum){
        return x ;
    }
}

extern "C" jstring JNICALL Java_com_example_firstndk_MainActivity_process(JNIEnv* env, jobject mainActivity){
    const jclass mainCls = env->GetObjectClass(mainActivity);
    const jmethodID jmethodId = env->GetMethodID(mainCls,"getName","()Ljava/lang/String;");
    if(jmethodId == nullptr){
        return env->NewStringUTF("");
    }
    const jobject result = env->CallObjectMethod(mainActivity,jmethodId);
    const string  java_msg = env->GetStringUTFChars((jstring)result,JNI_FALSE);
    const string c_msg = "Result from java => ";
    const string msg = c_msg + java_msg;
    return env->NewStringUTF(msg.c_str());
}


