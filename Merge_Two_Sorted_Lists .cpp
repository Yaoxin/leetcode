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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *out = new ListNode(0);
        ListNode * head = out;
        ListNode * temp = NULL;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                temp = new ListNode(l1->val);
                out->next = temp;
                l1 = l1->next;
            }
            else
            {
                temp = new ListNode(l2->val);
                out->next = temp;
                l2 = l2->next;
            }
            out = out->next;
        }
        while(l1 != NULL)
        {
            temp = new ListNode(l1->val);
            out->next = temp;
            out = out->next;
            l1 = l1->next;
        }

        while( l2 != NULL)
        {
            temp = new ListNode(l2->val);
            out->next = temp;
            out = out->next;
            l2 = l2->next;
        }

        return head->next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode a(1);
    ListNode b(2);
    Solution s;
    ListNode * test =  s.mergeTwoLists(&a, &b);

    cout << "hello world" << endl;
    while(test != NULL)
    {
        cout << test->val << endl;
        test = test->next;
    }

    return 0;
}





