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
		"�ڹ� �޼��� ȣ��",
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

