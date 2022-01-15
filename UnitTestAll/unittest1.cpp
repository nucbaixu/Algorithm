#include "stdafx.h"
#include "CppUnitTest.h"
#include "../StackAndQueAlg/LongestValidParentheses.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestAll
{		
	//测试队列和栈的算法
	TEST_CLASS(UnitTestStackAndQue)
	{
	public:
		
		Slution slu;

		TEST_METHOD(TestMethod1)
		{
			std::string Test = ")((()))()())))";
			int expectval = 10;

			Assert::AreEqual(expectval,slu.longestValidParentheses(Test));
			// TODO: 在此输入测试代码
		}

		TEST_METHOD(TestMethod2)
		{
			std::string Test = ")(";
			int expectval = 0;

			Assert::AreEqual(expectval, slu.longestValidParentheses(Test));
			// TODO: 在此输入测试代码
		}


		TEST_METHOD(TestMethod3)
		{
			std::string Test = "";
			int expectval = 0;

			Assert::AreEqual(expectval, slu.longestValidParentheses(Test));
			// TODO: 在此输入测试代码
		}


		TEST_METHOD(TestMethod4)
		{
			std::string Test = "()()()";
			int expectval = 6;

			Assert::AreEqual(expectval, slu.longestValidParentheses(Test));
			// TODO: 在此输入测试代码
		}
	};
}