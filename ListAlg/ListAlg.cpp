#include "ListAlg.h"

// List Init 
ptrListNode Init()
{
	ListNode * ptrNode = (ptrListNode)malloc(sizeof(ListNode));
	ptrNode->val = -1;
	ptrNode->next = nullptr;
	return ptrNode;
}

ptrListNode InsertListBegin (ptrListNode head, int val)
{
	if (head == nullptr)
	{
		return nullptr;
	}

	ListNode * ptrNodeTmp = (ptrListNode)malloc(sizeof(ListNode));
	ptrNodeTmp->val = val;
	ptrNodeTmp->next = head;
	return ptrNodeTmp;
}


ptrListNode InsertlistEnd(ptrListNode head, int val)
{
	if (head == nullptr)
	{
		return nullptr;
	}

	ptrListNode orgnode = head;

	while (head->next != nullptr)
	{
		head = head->next;
	}

	ListNode * ptrNodeTmp = (ptrListNode)malloc(sizeof(ListNode));
	ptrNodeTmp->val = val;
	ptrNodeTmp->next = nullptr;
	head->next = ptrNodeTmp;
	return orgnode;
}


void ListPrint(ptrListNode head)
{
	ptrListNode node = head;
	while (node != nullptr)
	{
		printf("%d\n", node->val);
		node = node->next;
	}
	printf("\n");
}

void ListFree(ptrListNode head)
{
	ptrListNode p = head, tmp;
	while (p != nullptr)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
}