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
 @ function : 	�Ӹ��ڵ㿪ʼ�������ö��������ù�ϣ���¼ÿ���ڵ�ĸ��ڵ�ָ�롣
�� p �ڵ㿪ʼ���������������ƶ����������ݽṹ��¼�Ѿ����ʹ������Ƚڵ㡣
ͬ���������ٴ� q �ڵ㿪ʼ���������������ƶ�������������Ѿ������ʹ�������ζ������ p �� q ���������Ĺ������ȣ��� LCA �ڵ㡣

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