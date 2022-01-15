#include "ListAlg.h"
#include "stdio.h"
#include "Listreverse.h"
#include "DoubleLinkedList.h"

int ListReverseTest()
{
	ListNode* first = new ListNode(1);
	ListNode* second = new ListNode(2);
	ListNode* third = new ListNode(3);
	ListNode* forth = new ListNode(4);
	ListNode* fifth = new ListNode(5);
	first->next = second;
	second->next = third;
	third->next = forth;
	forth->next = fifth;
	fifth->next = NULL;

	ListReverse listReverseor;
	ListNode * pNewHead = listReverseor.reverseList(first);

	ListNode* NullNode = nullptr;
	pNewHead = listReverseor.reverseList(NullNode);

	ListNode* oneNode = new ListNode(1);
	pNewHead = listReverseor.reverseList(oneNode);

	return 0;
}


void TestDoubleLinList()
{
	struct stu
	{
		int id;
		char name[20];
	};

	stu arraystu[] = { {10,"A"},{20,"B"},{30,"C"},{40,"D"} };

	DoubleLinkedList<stu> *pList = new DoubleLinkedList<stu>();
	pList->Insert(0, arraystu[1]);
	pList->Insert(0, arraystu[0]);
	pList->Insert(0, arraystu[3]);
	pList->Insert(0, arraystu[2]);
	pList->Insert(1, arraystu[0]);
	pList->Insert(2, arraystu[3]);
	pList->Insert(3, arraystu[2]);
	pList->AppendLast(arraystu[0]);
	pList->InsertFrist(arraystu[2]);

	printf("size = %d\n", pList->size());

	int size = pList->size();
	stu p;
	for (int i = 0; i < size; i++)
	{
		p = pList->GetVal(i);
		printf("id = %d,name = %s\n", p.id, p.name);
	}
}

int main()
{
	TestDoubleLinList();

	ptrListNode  pNode = Init();

	for (int i = 0; i < 10; i++)
	{
		pNode = InsertListBegin(pNode, i);
	}

	ListPrint(pNode);

	ListFree(pNode);

	system("pause");
}