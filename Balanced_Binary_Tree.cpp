#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Definition for binary tree
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

 int Height(TreeNode *root)
 {
 	if(root == NULL)
 		return 0;
 	if(root->left == NULL && root->right == NULL)
 		return 1;
 	return max(Height(root->left), Height(root->left)) + 1;
 }

class Solution {
public:
	//nlogn
    bool isBalanced_bak(TreeNode *root) {
    	if(root == NULL)
    		return true;
    	return abs(Height(root->left) - Height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    //dfs
    bool isBalanced(TreeNode *root)
    {
    	if(root == NULL )
    		return true;
    	std::map<TreeNode *, int>::iterator iter;
    	int h1, h2;
    	if(isBalanced(root->left) && isBalanced(root->right))
    	{
    		h1 = 0;
    		h2 = 0;
    		iter = 	height.find(root->left);
    		if(iter != height.end())
    		{
    			h1 = iter->second;
    		}

    		iter = height.find(root->right);
    		if(iter != height.end())
    		{
    			h2 = iter->second;
    		}
    		if(abs(h1 - h2) > 1)
    			return false;
    		else
    		{
    			height.insert(std::map<TreeNode *, int>::value_type(root, max(h1, h2) + 1));
    			return true;
    		}
    	}
    	else 
    	{
    		return false;
    	}
    }

private:
	map<TreeNode *, int> height;
};


int main(int argc, char const *argv[])
{
	struct TreeNode s(3);
	struct TreeNode s1(4);
	struct TreeNode s2(5);
	s.right = &s1;
	s1.right = &s2;
	//s.right = &s2;
	Solution test;
	cout << test.isBalanced(&s) << endl;
	return 0;
}