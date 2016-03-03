#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> preorderTraversal(TreeNode* root) {
    	std::vector<int> v;
    	if(root == NULL)
    		return v;
    	stack<TreeNode *> st;
    	st.push(root);
    	TreeNode *temp = NULL;

    	while(!st.empty())
    	{
    		temp = st.top();
            st.pop();
    		v.push_back(temp->val);
    		if(temp->right)
    		{
    			st.push(temp->right);
    		}
    		if(temp->left)
    		{
    			st.push(temp->left);
    		}
    	}

    	return v;
    }
};


int main(int argc, char const *argv[])
{
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.left = &b;
	b.right = &c;
	Solution s;
	std::vector<int> v;
	v = s.preorderTraversal(&a);
	for (int i = 0; i < v.size(); ++i)
	{
		cout << " " << v[i] ;
	}
	cout << endl;
	return 0;
}
