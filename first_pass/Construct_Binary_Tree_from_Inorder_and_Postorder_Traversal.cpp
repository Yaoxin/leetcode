#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode * buildTree_help(vector<int> &inorder,int ino_start,int ino_end, vector<int> &postorder, int post_start, int post_end)
	{
		if(ino_end < ino_start || post_end < post_start)
			return NULL;
		TreeNode *root = new TreeNode(postorder[post_end]);
		int mid = 0;
		int i = 0;
		for(mid =ino_start; mid <= ino_end; mid++)
		{
			if(inorder[mid] == postorder[post_end])
			{
				break;
			}
			i++;
		}
		root->left = buildTree_help(inorder, ino_start, mid - 1 , postorder, post_start, post_start + i - 1);
		root->right = buildTree_help(inorder, mid + 1, ino_end, postorder, post_start + i, post_end - 1);

		return root;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	if(inorder.size() == 0 || postorder.size() == 0)
    		return NULL;
 		return buildTree_help(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() -1);
    }

    void TravelTreeNode(TreeNode *root)
    {
    	if(!root)
    		return;
    	
    	TravelTreeNode(root->left);
    	cout << root->val << endl;
    	TravelTreeNode(root->right);
    	

    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int a[] = {4,5,2,3,1};
	int b[] = {4, 2, 5, 1, 3};
	vector<int> ino(b, b + 5);
	vector<int> post(a, a + 5);
	TreeNode * root = s.buildTree(ino, post);
	s.TravelTreeNode(root);


	return 0;
}


