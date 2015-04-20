#include <iostream>
#include <map>
#include <stack>

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

  int dfs(TreeNode *root, int sum, int curSum)
  {
    if(root == NULL)
    {
        return false;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return curSum + root->val == sum;
    }

    return dfs(root->left, sum, curSum + root->val) || dfs(root->right, sum, curSum + root->val);
  }

class Solution {
public:

    bool hasPathSum(TreeNode *root, int sum)
    {
        return dfs(root, sum, 0);
    }
    //前序遍历
    bool hasPathSum_bak(TreeNode *root, int sum) {
    	if(root == NULL )
    		return false;
    	stack<TreeNode *>st;
    	st.push(root);
    	TreeNode * Cur = NULL;
    	int value = 0;
    	node_sum.insert(std::map<TreeNode *, int>::value_type(root, root->val));

    	while(!st.empty())    	
    	{
       		Cur = st.top();
            st.pop();
    		if(Cur->right != NULL)
    		{
    			value = Cur->right->val + node_sum[Cur];
    			node_sum.insert(std::map<TreeNode *, int>::value_type(Cur->right, value));
    			st.push(Cur->right);
    		}
    		if(Cur->left != NULL)
    		{
    			value = Cur->left->val + node_sum[Cur];
       			node_sum.insert(std::map<TreeNode *, int>::value_type(Cur->left, value));
    			st.push(Cur->left);
    		}
      	}

    	for(std::map<TreeNode *, int>::iterator iter = node_sum.begin(); iter != node_sum.end(); iter++)
    	{
    		if(iter->second == sum && iter->first->left == NULL && iter->first->right == NULL)
    		{
    			return true;
    		} 
    	}

    	return false;
    }
 private:
 	map<TreeNode *, int>node_sum;
};

int main(int argc, char const *argv[])
{
	TreeNode s(-2);
	TreeNode s1(-3);
	s.right = &s1;
	Solution test;
	bool a = test.hasPathSum(&s, -5);
	cout << a << endl;

	return 0;
}