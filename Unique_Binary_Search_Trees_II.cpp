#include <iostream>
#include <vector>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
	vector<TreeNode *>generateTrees(int start, int end)
	{
		vector<TreeNode *> out;
		if(start > end)
		{
			out.push_back(NULL);
			return out;
		}

		vector<TreeNode *> left;
		vector<TreeNode *> right;
		for (int i = start; i <= end; ++i)
		{
			left = generateTrees(start, i - 1);
			right = generateTrees(i + 1, end);

			for(int j = 0; j < left.size(); j++)
			{
				for(int k = 0; k < right.size(); k++)
				{
					TreeNode * root = new TreeNode(i);
					root->left = left[j];
					root->right = right[k];
					out.push_back(root);
				}
			}
		}

		return out;

	}
    vector<TreeNode*> generateTrees(int n) {
    	return generateTrees(1, n);
        
    }
};