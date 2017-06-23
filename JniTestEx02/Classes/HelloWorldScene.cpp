#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"

#ifdef __cplusplus
extern "C"{
#endif

	jint Java_org_cocos2dx_cpp_AppActivity_cppSum(JNIEnv *env, jobject obj, jint a, jint b)
	{
		return a + b;
	}

#ifdef __cplusplus
}
#endif

#endif

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
	MenuItemFont::setFontName("fonts/Marker Felt.ttf");
	auto pMenuItem1 = MenuItemFont::create(
		"Java Method Call",
		CC_CALLBACK_1(HelloWorld::callJavaMethod, this));
	pMenuItem1->setColor(Color3B::WHITE);

	// �޴� ����
	auto pMenu = Menu::create(pMenuItem1, nullptr);

	// ���̾ �޴� ��ü �߰�
	this->addChild(pMenu);

    return true;
}


void HelloWorld::callJavaMethod(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo t;
	/**
	JniHelper�� ���� org/cocos2dx/cpp/�� �ִ�
	AppActivity class�� JniTestFunc�Լ� ������ �����´�.
	*/
	if (JniHelper::getStaticMethodInfo(t
		, "org.cocos2dx.cpp.AppActivity"
		, "JniTestFunc"
		, "()V"))
	{
		// �Լ� ȣ��
		t.env->CallStaticVoidMethod(t.classID, t.methodID);

		// Release
		t.env->DeleteLocalRef(t.classID);
	}
#endif
}