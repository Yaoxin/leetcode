#include <iostream>
#include <vector>
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

  typedef struct _SNode
  {
  	TreeNode *n;
  	bool	visited;
  }SNode;


class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
    	std::vector<int> v;
    	if(root == NULL)
    	{
    		return v;
    	}
    	SNode r;
    	r.n = root;
    	r.visited = false;

    	std::stack<SNode>st;
    	st.push(r);
    	SNode cur;
    	SNode temp;

    	while(!st.empty())
    	{
    		cur = st.top();
    		st.pop();
    		if(cur.visited == true)
    		{
    			v.push_back(cur.n->val);
    		}
    		else
    		{
    			cur.visited = true;
    			st.push(cur);
    			if(cur.n->right != NULL)
    			{
    				temp.n = cur.n->right;
    				temp.visited = false;
    				st.push(temp);
    			}
    			if(cur.n->left != NULL)
    			{
    				temp.n = cur.n->left;
    				temp.visited = false;
    				st.push(temp);
    			}
    		}
    	}

    	return v;
        
    }
};

