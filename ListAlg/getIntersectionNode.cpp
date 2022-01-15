/******************************************************
 @ function : 	��ָ Offer 52. ��������ĵ�һ�������ڵ�
 @ Access 	:	
 @ Parameter:	
 @ Returns  :	
 @ Remarks 	:   
 @ author   :   
******************************************************/

#pragma once
#include <set>
#include "ListAlg.h"
using namespace std;

class Solution2
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
	{
		if (headA == nullptr || headB == nullptr)
		{
			return nullptr;
		}

		while (headA)
		{
			nodeset.insert(headA);
			headA->next;
		}

		while (headB)
		{
			if (nodeset.find(headB) != nodeset.end())
			{
				return headB;
			}
			headB = headB->next;
		}

		return nullptr;
	}
private:
	set<ListNode *> nodeset;
};


//ʹ��˫ָ�뷨
class Solution2
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		if (headA == nullptr || headB == nullptr)
		{
			return nullptr;
		}

		ListNode *node1 = headA;
		ListNode *node2 = headB;

		while (node1 != node2) {
			node1 = node1 != NULL ? node1->next : headB;
			node2 = node2 != NULL ? node2->next : headA;
		}
		return node1;
	}
private:
	
};
