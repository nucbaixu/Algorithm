#include "TreeNode.h"
#include <unordered_map>
using namespace std;

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		dfs(root, p, q);
		return ans;
	}
private:
	bool dfs(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (root == nullptr) return false;

		bool lson = dfs(root->left, p, q);
		bool rson = dfs(root->right,p, q);

		if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
			ans = root;
		}

		return lson || rson || (root->val == p->val || root->val == q->val);
	}
private:
	TreeNode *ans = nullptr;
};

/******************************************************
 @ function : 	从根节点开始遍历整棵二叉树，用哈希表记录每个节点的父节点指针。
从 p 节点开始不断往它的祖先移动，并用数据结构记录已经访问过的祖先节点。
同样，我们再从 q 节点开始不断往它的祖先移动，如果有祖先已经被访问过，即意味着这是 p 和 q 的深度最深的公共祖先，即 LCA 节点。

 @ Access 	:	
 @ Parameter:	
 @ Returns  :	
 @ Remarks 	:   
 @ author   :   
******************************************************/
class Solution2 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		fa[root->val] = nullptr;
		dfs(root);
		while (p != nullptr) {
			vis[p->val] = true;
			p = fa[p->val];
		}
		while (q != nullptr) {
			if (vis[q->val]) return q;
			q = fa[q->val];
		}
		return nullptr;
	}
private:
	void dfs(TreeNode* root) {
		if (root->left != nullptr) {
			fa[root->left->val] = root;
			dfs(root->left);
		}
		if (root->right != nullptr) {
			fa[root->right->val] = root;
			dfs(root->right);
		}
	}
	
private:
	unordered_map<int, TreeNode*> fa;
	unordered_map<int, bool> vis;
};