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

    TreeNode * createAVLNode(vector<int> &nums, int start, int end)
    {
       if(start >= end)
            return NULL;
       if(start == (end - 1))
            return new TreeNode(nums[start]);
       int mid = (start + end) / 2;
       //cout << mid <<endl;
       TreeNode *root = new TreeNode(nums[mid]);
       root->left = createAVLNode(nums, start, mid);
       root->right = createAVLNode(nums, mid + 1, end);
       return root;

    }

	
	//因为是升序的数组，不需要构造AVL树。
    //暗示了一种思路，先排序后插入
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createAVLNode(nums, 0, nums.size());
    }

    void TravlTree(TreeNode *root)
    {
    	if(root != NULL)
    	{
    		TravlTree(root->left);
    		cout << root->val << " ";
    		TravlTree(root->right);
    	}
    }
};

int main(int argc, char const *argv[])
{

	int a[] = {3, 7, 9 ,11, 12, 13};
	std::vector<int> v(a, a + 6);
	Solution s;
	TreeNode *root = s.sortedArrayToBST(v);
	cout << "[ ";
	s.TravlTree(root);
	cout << "]"<<endl;

	return 0;
}