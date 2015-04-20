#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


//前序非递归遍历
bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
	stack<struct TreeNode *> tn_stack1;
	stack<struct TreeNode *> tn_stack2;
	struct TreeNode * m = NULL;
	struct TreeNode * n = NULL;
	bool ret = false;

	tn_stack1.push(p);
	tn_stack2.push(q);

	while(!tn_stack1.empty() && !tn_stack2.empty())
	{
		m = tn_stack1.top();
		n = tn_stack2.top();
		tn_stack1.pop();
		tn_stack2.pop();
		if(m != NULL && n != NULL)
		{
			if(m->val != n->val)
			{
				ret = false;
				break;
			}
			tn_stack1.push(m->right);
			tn_stack1.push(m->left);
			tn_stack2.push(n->right);
			tn_stack2.push(n->left);
		}
		else if ( m == NULL && n == NULL)
		{
			ret = true;
		}
		else
		{
			ret = false;
			break;
		}
	}

	return ret;  
}


