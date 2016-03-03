#include <iostream>
#include <cmath>

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
	int getleftHeight(TreeNode *root)
	{
		int height = 0;
		while(root != NULL)
		{
			height++;
			root = root->left;
		}
		return height;
	}
	int getrightHeight(TreeNode *root)
	{
		int height = 0;
		while(root != NULL)
		{
			height++;
			root = root->right;
		}
		return height;
	}
    int countNodes(TreeNode* root) {
 			if(root == NULL)
 				return 0;
 			float lh = getleftHeight(root);
 			float rh = getrightHeight(root);

 			if(lh == rh)
 			{
 				return pow(2, lh) - 1;
 			}

 			return countNodes(root->left) + countNodes(root->right) + 1;   
    }
};

int main(int argc, char const *argv[])
{
	//Solution s;

	//int num = s.countNodes(root);
	//cout << num << endl;


	return 0;
}