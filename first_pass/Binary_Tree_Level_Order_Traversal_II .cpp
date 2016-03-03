#include <iostream>
#include <deque>
#include <vector>

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

//create a tree on OJ
TreeNode *create_tree_oj(int a[], int len)
{
	TreeNode * head = (TreeNode *)new char[sizeof(struct TreeNode)];
	if(head == NULL)
	{
		return head;
	}

	head->val = a[0];
	head->left = head->right = NULL;
	deque<TreeNode *>tn_deque;
	tn_deque.push_back(head);
	int index = 0;
	TreeNode *cur = NULL;
	TreeNode *temp = NULL;

	while(!tn_deque.empty() && index < len)
	{
		cur = tn_deque.front();
		if(++index && index < len && a[index] != -1)
		{
			temp = (TreeNode *)new char[sizeof(struct TreeNode)];
			temp->val = a[index];
			temp->left = temp->right = NULL;
			cur->left = temp;
			tn_deque.push_back(temp);
		}

		if(++index && index < len && a[index] != -1)
		{
			temp = (TreeNode *)new char[sizeof(struct TreeNode)];
			temp->val = a[index];
			temp->left = temp->right = NULL;
			cur->right = temp;
			tn_deque.push_back(temp);
		}
		tn_deque.pop_front();
	}

	return head;
}


class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
    		vector<vector<int> >rtn_vc;
    		if(root == NULL)
    			return rtn_vc;
    		deque<TreeNode *>tn_deque;
    		vector<int> temp;
    		int now = 1;
    		int next = 0;
    		TreeNode *cur = NULL;
    		tn_deque.push_back(root);

    		while(!tn_deque.empty())
    		{
    			cur = tn_deque.front();
    			if(cur->left != NULL)
    			{
    				tn_deque.push_back(cur->left);
    				next++;
    			}

    			if(cur->right != NULL)
    			{
    				tn_deque.push_back(cur->right);
    				next++;
    			}
    			//temp.insert(temp.begin(), cur->val);
    			temp.push_back(cur->val);


    			if(--now == 0)
    			{
    				//rtn_vc.push_back(temp);
    				rtn_vc.insert(rtn_vc.begin(), temp);
    				temp.clear();
    				now = next;
    				next = 0;
    			}
    			tn_deque.pop_front();
    		}

    		return rtn_vc;
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	int a[] = {3,9,20,-1,-1,15,7};
	vector<vector<int> > out;
	TreeNode * T = create_tree_oj(a, 7);
	out = s.levelOrderBottom(T);

	for(int i = 0; i < out.size(); i++)
	{
		for(int j = 0; j < out[i].size(); j++)
		{
			cout << " "<< out[i][j]; 
		}
		cout << endl;
	}
	return 0;
}