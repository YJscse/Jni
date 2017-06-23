#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
	//////////////////////////////

	auto pMenuItem1 = MenuItemFont::create(
		"자바 메서드 호출",
		CC_CALLBACK_1(HelloWorld::callJavaMethod, this));
	pMenuItem1->setColor(Color3B::WHITE);

	// 메뉴 생성
	auto pMenu = Menu::create(pMenuItem1, nullptr);

	// 레이어에 메뉴 객체 추가
	this->addChild(pMenu);
    
    return true;
}


void HelloWorld::callJavaMethod(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo t;
	/**
	JniHelper를 통해 org/cocos2dx/cpp/에 있는
	AppActivity class의 JniTestFunc함수 정보를 가져온다.
	*/
	if (JniHelper::getStaticMethodInfo(t
		, "org.cocos2dx.cpp.AppActivity"
		, "JniTestFunc"
		, "()V"))
	{
		// 함수 호출
		t.env->CallStaticVoidMethod(t.classID, t.methodID);

		// Release
		t.env->DeleteLocalRef(t.classID);
	}
#endif
}

