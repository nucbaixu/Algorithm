#include "stdafx.h"
#include "stdio.h"
/******************************************************
 @ function : 虚函数切割问题	
 @ Access 	:	
 @ Parameter:	
 @ Returns  :	
 @ Remarks 	:   
 @ author   :   
******************************************************/
class A
{
public:
	virtual void Test()
	{
		printf("A test \n");
	}
private:

};

class B :public A
{
public:

	void func()
	{
		Test();
	}
	virtual void Test()
	{
		printf("B test \n");
	}
private:

};

class C :public B
{
public:
	virtual void Test()
	{
		printf("C test \n");
	}

};



//我们知道，派生类通常会比基类大，因为派生类不仅有基类的成员还有派生类本身的成员，经过向上转换（派生类对象强制转换为基类对象）,就会造成对象内容被切割(object slicing).
int main(int argc, char *argv[])
{

	C c;
	B* pb = &c;
	pb->func();

	B cc = c;
	((B*)(&c))->func();
	(B(c)).func();


	return 0;
}
