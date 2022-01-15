#ifndef __LISTALG_H__
#define __LISTALG_H__

#include "stdlib.h"
#include "stdio.h"

typedef struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
} *ptrListNode;

ptrListNode Init();
ptrListNode InsertlistEnd(ptrListNode head, int val);
ptrListNode InsertListBegin(ptrListNode head, int val);
void ListPrint(ptrListNode head);
void ListFree(ptrListNode head);

#endif // !__LISTALG_H__

