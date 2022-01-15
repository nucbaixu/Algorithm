/******************************************************
 @ function : 	序列化二叉树和反序列化
 @ Access 	:	
 @ Parameter:	
 @ Returns  :	
 @ Remarks 	:   
 @ author   :   
******************************************************/
#pragma once
#include <string>
#include <list>
#include "TreeNode.h"
using namespace std;

class Codec 
{
public:

	
	// Encodes a tree to a single string.
	string serialize(TreeNode* root)
	{
		string ret;
		rserialize(root, ret);
		return ret;

	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data)
	{
		list<string> dataArray;
		
		string str;
		for (auto& ch : data) {
			if (ch == ',') {
				dataArray.push_back(str);
				str.clear();
			}
			else {
				str.push_back(ch);
			}
		}
		if (!str.empty()) {
			dataArray.push_back(str);
			str.clear();
		}
		return rdeserialize(dataArray);
	}
private:
	void rserialize(TreeNode* root, string &res)
	{
		if (root == nullptr)
			res += "NULL,";
		else
		{
			res += std::to_string(root->val) + ",";

			rserialize(root->left, res);
			rserialize(root->right, res);
		}
	}
private:
	TreeNode * rdeserialize(list<string>& dataArray)
	{
		if (dataArray.front() == "None") {
			dataArray.erase(dataArray.begin());
			return nullptr;
		}

		TreeNode * node = new TreeNode(stoi(dataArray.front()),NULL,NULL);
		dataArray.erase(dataArray.begin());
		node->left = rdeserialize(dataArray);
		node->right = rdeserialize(dataArray);

		return node;
	}
};
