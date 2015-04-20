/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <deque>
#include <algorithm>


using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	//层序遍历，记录具体层次
    int minDepth_bak(TreeNode *root) {
    	int min = 0;
    	deque<TreeNode *> tn_deque;
    	TreeNode *Cur = NULL;
    	int m = 0, n = 0;
    	if(root != NULL)
    	{	
    		m = 1;
    		min = 1;
    		tn_deque.push_back(root);
    	}

    	while(!tn_deque.empty())
    	{
    		Cur = tn_deque.front();
    		tn_deque.pop_front();
    		if(Cur->left == NULL && Cur->right == NULL)
    		{
    			break;
    		}

    		if(Cur->left != NULL)
    		{
    			n++;
    			tn_deque.push_back(Cur->left);
    		}
    		if(Cur->right != NULL )
    		{
    			n++;
    			tn_deque.push_back(Cur->right);
    		}
    		if(--m == 0 )
    		{
    			m = n;
    			n = 0;
    			min += 1;
    		}
    	} 

    	return min;
    }
    //递归
    int minDepth(TreeNode *root) {
    	if(root == NULL)
    	{
    		return 0;
    	}
    	if(root->left == NULL && root->right == NULL)
    	{
    		return 1;
    	}
    	
    	int leftDepth = minDepth(root->left);
    	int rightDepth = minDepth(root->right);
    	if(leftDepth == 0)
    		return rightDepth + 1;
    	if(rightDepth == 0)
    	{
    		return leftDepth + 1;
    	}

    	return min(leftDepth, rightDepth) + 1;
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	TreeNode * root = NULL;

	int n = s.minDepth(root);
	cout << n << endl;

	return 0;
}