#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 }; 

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode *pre = NULL;
        ListNode *cur = &dummy;
        while(head && head->next)
        {
            if(head->val != head->next->val)
            {
                if((pre && pre->val != head->val) || !pre)
                {
                    cur->next = head;
                    cur = cur->next;
                }
            }
            pre = head;
            head = head->next;
        }
        if(head)
        {
            if((pre && pre->val != head->val) || !pre)
            {
                cur->next = head;
                cur = cur->next;
            }
        }
        cur->next = NULL;

        return dummy.next;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	ListNode a(1);
	ListNode b(2);
	ListNode c(2);
	//ListNode d(2);
	//ListNode e(3);
	a.next = &b;
	b.next = &c;
	//c.next = &d;
	//d.next = &e;
	ListNode *head = NULL;
	head = s.deleteDuplicates(&a);
    cout << "hello"<< endl;
	while(head)
	{
		cout << head->val << endl;
		head = head->next;
	}

	return 0;
}