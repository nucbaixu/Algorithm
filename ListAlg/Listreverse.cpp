#include "Listreverse.h"

ListNode * ListReverse::reverseList(ListNode * head)
{
	//����λ�շ��ؿ�ָ��,//����ֻ��һ���ڵ㣬���ص�ǰ�ڵ�
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}

	ListNode *p1 = head;
	ListNode *p2 = p1->next;
	head->next = nullptr;
	ListNode *pTmp = nullptr;

	while (p2)
	{
		pTmp = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = pTmp;
	}

	return p1;
}
