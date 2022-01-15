#pragma once

template<class T> 
struct DNode
{
public:
	T val;
	DNode * prev;
	DNode * next;
public:
	DNode() {}
	DNode(T _val, DNode * _prev, DNode * _next)
	{
		val = _val;
		prev = _prev;
		next = _next;
	}
};

template<class T>
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	~DoubleLinkedList();
public:
	int size();
	bool is_empty();

	T GetVal(int index);
	T Getfrist();
	T Getlast();

	int Insert(int index,T val);
	int InsertFrist(T val);
	int AppendLast(T val);

	int Delete(int index);
	int DeleteFrist();
	int DeleteLast();

private:
	int count;
	DNode<T> *phead;
private:
	DNode<T> *GetNode(int index);
};



template<class T>
DoubleLinkedList<T>::DoubleLinkedList() :count(0)
{
	//头结点不算入链表的长度
	phead = new DNode<T>();
	phead->next = phead->prev = phead;
}

template<class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	DNode<T> *pTmpNode;
	DNode<T> *pNode = phead->next;
	while (pNode != phead)
	{
		pTmpNode = pNode->next;
		delete pNode;
		pNode = pTmpNode;
	}

	delete phead;
	phead = nullptr;
}

template<class T>
int DoubleLinkedList<T>::size()
{
	return count;
}

template<class T>
bool DoubleLinkedList<T>::is_empty()
{
	return count == 0;
}

template<class T>
DNode<T> * DoubleLinkedList<T>::GetNode(int index)
{
	if (index < 0 || index >= count)
	{
		return nullptr;
	}

	if (index < count / 2)
	{
		int i = 0;
		DNode<T> *pTmpNode = phead->next;
		while (i++ < index)
		{
			pTmpNode = pTmpNode->next;
		}
		return pTmpNode;
	}
	else
	{
		int j = 0;
		int rindex = count - index - 1;
		DNode<T> *pTmpNode = phead->prev;
		while (j++ < rindex)
		{
			pTmpNode = pTmpNode->prev;
		}
		return pTmpNode;
	}
}

template<class T>
T DoubleLinkedList<T>::GetVal(int index)
{
	DNode<T> *pNode = GetNode(index);
	if (pNode != nullptr)
	{
		return pNode->val;
	}
	else
	{
		return phead->val;
	}
}

template<class T>
T DoubleLinkedList<T>::Getfrist()
{
	return GetNode(0)->val;
}

template<class T>
T DoubleLinkedList<T>::Getlast()
{
	return GetNode(count - 1)->val;
}

template<class T>
int DoubleLinkedList<T>::Insert(int index, T val)
{
	if (index == 0)
	{
		InsertFrist(val);
		return 0;
	}

	if (index == count)
	{
		AppendLast(val);
		return 0;
	}

	DNode<T> * pBaseNode = GetNode(index);
	DNode<T> * pTmpNode = new DNode<T>(val, pBaseNode->prev, pBaseNode);
	pBaseNode->prev->next = pTmpNode;
	pBaseNode->prev = pTmpNode;
	count++;
	return 0;
}

template<class T>
int DoubleLinkedList<T>::InsertFrist(T val)
{
	DNode<T> * pTmpNode = new DNode<T>(val, phead, phead->next);
	phead->next->prev = pTmpNode;
	phead->next = pTmpNode;
	count++;
	return 0;
}
template<class T>
int DoubleLinkedList<T>::AppendLast(T val)
{
	DNode<T> * pTmpNode = new DNode<T>(val, phead->prev, phead);
	phead->prev->next = pTmpNode;
	phead->prev = pTmpNode;
	count++;
	return 0;
}

template<class T>
int DoubleLinkedList<T>::Delete(int index)
{
	DNode<T> * pNode = GetNode(index);
	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;
	delete pNode;
	pNode = nullptr;
	count--;
	return 0;
}
template<class T>
int DoubleLinkedList<T>::DeleteFrist()
{
	return Delete(0);
}
template<class T>
int DoubleLinkedList<T>::DeleteLast()
{
	return Delete(count - 1);
}
