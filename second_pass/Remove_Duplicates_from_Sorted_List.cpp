#include "common/help.h"


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * cur = head;
        ListNode * pre = NULL;
        while(cur != NULL) {
            if(pre && pre->val == cur->val) {
                pre->next = cur->next;
            } else {
                pre = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {1, 1, 2, 3, 3};
    std::vector<int> v(a, a + 5); 
    ListNode * head =  create_linklist(v);
    Solution s;
    print_linklist(s.deleteDuplicates(head));
    return 0;
}