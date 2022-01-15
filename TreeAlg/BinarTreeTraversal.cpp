#include "stdafx.h"
#include "BinarTreeTraversal.h"
TreeTraversal::TreeTraversal()
{
}

TreeTraversal::~TreeTraversal()
{
}

std::vector<int> TreeTraversal::preorderTraversal(TreeNode * root)
{
	return std::vector<int>();
}

std::vector<int> TreeTraversal::preorderTraversalByStack(TreeNode * root)
{
	std::vector<int> result;
	const TreeNode * p;
	std::stack<const TreeNode *> s;

	p = root;
	if (p != nullptr)
	{
		s.push(p);
	}

	while (!s.empty())
	{
		p = s.top();
		s.pop();
		result.push_back(p->val);

		if (p->right != nullptr)
		{
			s.push(p->right);
		}

		if (p->left != nullptr)
		{
			s.push(p->left);
		}
	}

	return result;
}

std::vector<int> TreeTraversal::preorderTraversalByMorrisAlg(TreeNode * root)
{
	return std::vector<int>();
}

std::vector<int> TreeTraversal::inorderTraversalByStack(TreeNode * root)
{
	std::vector<int> result;
	std::stack<TreeNode * >s;
	TreeNode * p = root;

	while (p != nullptr  || !s.empty())
	{
		if (p != nullptr)
		{
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			s.pop();
			result.push_back(p->val);
			p = p->right;
		}
	}
	return result;
}

//
//ʹ��ջ�ķ�ʽʵ�ֺ����������̸��ӣ��߼�����
std::vector<int> TreeTraversal::postorderTraversalByStack(TreeNode * root)
{
	std::vector<int> result;
	std::stack<TreeNode * >s;
	TreeNode * p = root,*q;

	do
	{
		while (p != nullptr)
		{
			s.push(p);
			p = p->left;
		}

		q = nullptr;
		while (!s.empty())
		{
			p = s.top();
			s.pop();
			//�Һ��Ӳ����ڻ����Ѿ������ʣ�����
			if (p->right == q)
			{
				result.push_back(p->val);
				q = p;//����շ��ʹ��Ľڵ�
			}
			else
			{
				//��ǰ��㲻�ܷ��ʣ���Ҫ���ν�ջ
				s.push(p);
				//�ȴ���������
				p = p->right;
				break;
			}
		}

	} while (!s.empty());
	return result;
}
