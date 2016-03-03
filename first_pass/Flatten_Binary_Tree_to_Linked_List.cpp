#include <iostream>

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
    void flatten(TreeNode* root) {
    	if(root == NULL)
    		return;
    	flatten(root->left);
    	flatten(root->right);
    	TreeNode *Temp = root->right;
    	if(root->left)
    	{
    		root->right = root->left;
    		root->left = NULL;
    		TreeNode *Item = root;
	    	while(Item->right)
	    	{
	    		Item = Item->right;
	    	}
	    	Item->right = Temp;
    	}
    }

    void Print(TreeNode *root)
    {
    	cout << root->val << endl;
    	if(root->left)
    	{
    		Print(root->left);
    	}
    	if(root->right)
    	{
    		Print(root->right);
    	}
    }
};



int main(int argc, char const *argv[])
{
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	a->left = b;
	a->right = c;
	
	Solution s;
	cout << "before: "<<endl;
	s.Print(a);
	s.flatten(a);
	cout << "After: "<<endl;
	s.Print(a);

	delete a;
	delete b;
	delete c;

	return 0;
}