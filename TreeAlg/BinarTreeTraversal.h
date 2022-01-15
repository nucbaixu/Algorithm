#pragma once
//�ֱ�ʵ�ֵݹ顢ջ��Morris�Ķ�����������
#include "TreeNode.h"
#include <vector>
#include <stack>
class TreeTraversal
{
public:
	TreeTraversal();
	~TreeTraversal();
public:
	//ǰ�����
	std::vector<int> preorderTraversal(TreeNode *root);
	std::vector<int> preorderTraversalByStack(TreeNode *root);
	std::vector<int> preorderTraversalByMorrisAlg(TreeNode *root);
public:
	//�������
	std::vector<int> inorderTraversalByStack(TreeNode *root);
public:
	//�������
	std::vector<int> postorderTraversalByStack(TreeNode *root);

public:
	//�������

private:

};

