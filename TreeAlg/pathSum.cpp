/******************************************************
 @ function : 	��ָ Offer 34. �������к�Ϊĳһֵ��·��
 @ Access 	:	
 @ Parameter:	
 @ Returns  :	
 @ Remarks 	:   
 @ author   :   
******************************************************/

#pragma once
#include <string>
#include <vector>
#include "TreeNode.h"
using namespace std;
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int target) 
	{
		if (root == nullptr) return {};
		dfs(root, target);
		return ret;
	}
private:
	void dfs(TreeNode * root,int target)
	{
		if (root == nullptr) return;
		path.push_back(root->val);
		target -= root->val;

		if (target == 0 && (root->left == nullptr && root->right == nullptr))
		{
			ret.push_back(path);
		}

		dfs(root->left, target );
		dfs(root->right, target );
		path.pop_back();
	}

private:
	vector<vector<int>> ret;
	vector<int> path;
};