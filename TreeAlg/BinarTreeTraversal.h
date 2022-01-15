#pragma once
//分别实现递归、栈、Morris的二叉树树遍历
#include "TreeNode.h"
#include <vector>
#include <stack>
class TreeTraversal
{
public:
	TreeTraversal();
	~TreeTraversal();
public:
	//前序遍历
	std::vector<int> preorderTraversal(TreeNode *root);
	std::vector<int> preorderTraversalByStack(TreeNode *root);
	std::vector<int> preorderTraversalByMorrisAlg(TreeNode *root);
public:
	//中序遍历
	std::vector<int> inorderTraversalByStack(TreeNode *root);
public:
	//后序遍历
	std::vector<int> postorderTraversalByStack(TreeNode *root);

public:
	//层序遍历

private:

};

