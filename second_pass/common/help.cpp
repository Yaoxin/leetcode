#include "help.h"

void print_vector(std::vector<int> v)
{
    cout << "Vector : ";
    for(std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}

ListNode * create_linklist(std::vector<int>v) {
    ListNode * head = new ListNode(-1);
    ListNode * cur = head;
    for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cur->next = new ListNode(*i);
        cur = cur->next;
    }
    return head->next;
}

void print_linklist(ListNode * head) {
    cout << "LinkList : ";
    while(head){
        cout << head->val<< " ";
        head = head->next;
    }
    cout << endl;
}
