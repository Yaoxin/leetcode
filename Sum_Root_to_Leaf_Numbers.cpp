#include <iostream>
#include <stack>
#include <string>

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

typedef struct 
{
	TreeNode * node;
	int val;
}_Node;


class Solution {
public:
	//
    int sumNumbers(TreeNode* root) {
    	if(root == NULL)
    		return 0;
    	int sum = 0;
    	stack<_Node> st;
    	_Node temp, mep;
    	temp.node = root;
    	temp.val = root->val;
    	st.push(temp);

    	string text;
    	while(!st.empty())
    	{
    		temp = st.top();
    		st.pop();
    		if(temp.node->left)
    		{
    			mep.node = temp.node->left;
    			if(temp.val == 0)
    				mep.val = temp.node->left->val;
    			else
    			{
    				text = to_string(temp.val) + to_string(temp.node->left->val);
    				mep.val = atoi(text.c_str());
    			}
    			st.push(mep);
    		}
    		if(temp.node->right)
    		{
    			mep.node = temp.node->right;
    			if(temp.val == 0)
    				mep.val = temp.node->right->val;
    			else
    			{
    				text = to_string(temp.val) + to_string(temp.node->right->val);
    				mep.val = atoi(text.c_str());
    			}
    			st.push(mep);
    		}

    		if(temp.node->left == NULL && temp.node->right == NULL)
    		{
    			sum += temp.val;
    		}
    	}

    	return sum;
    }

    //也可以用DFS玩。
};