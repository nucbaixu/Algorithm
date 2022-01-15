#ifndef _TREENODE_H_
#define _TREENODE_H_

//tree node define
struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;

	TreeNode(int _val, TreeNode *_left, TreeNode *_right) :val(_val), left(nullptr), right(nullptr)
	{
	}
};
#endif // !_TREENODE_H_
