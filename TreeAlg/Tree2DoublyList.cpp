#include "TreeNode.h"


class Solution
{
public:
	TreeNode * TreeToDoublyList(TreeNode * root)
	{
		if (!root) return root;
		
		dfs(root);

		head->left = pre;
		pre->right = head;

		return head;
	}

private:
	void dfs(TreeNode * cur)
	{
		if (!cur) return;
		
		dfs(cur->left);

		if (!pre)
		{
			head = cur;
		}
		else
		{
			pre->right = cur;
		}

		cur->left = pre;
		pre = cur;
		dfs(cur->right);
	}
private:
	TreeNode * pre;
	TreeNode * head;
};
