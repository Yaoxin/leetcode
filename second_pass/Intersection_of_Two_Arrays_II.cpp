#include "common/help.h"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> iv;
        std::map<int, int> m_cnt;

        if (nums1.size() == 0 || nums2.size() == 0)
        {
            return iv;
        }

        for (int i = 0; i < nums1.size(); ++i)
        {
            m_cnt[nums1[i]] += 1;
        }

        for (int i = 0; i < nums2.size(); ++i)
        {
            if (m_cnt.find(nums2[i]) != m_cnt.end() && m_cnt[nums2[i]] != 0)
            {
                m_cnt[nums2[i]] -= 1;
                iv.push_back(nums2[i]);
            }
        }
        return iv;
    }
};

int main(int argc, char const *argv[])
{
    int a1[] = {1, 2, 2, 1};
    int a2[] = {2, 2};
    std::vector<int> v1(a1, a1 + 4);
    std::vector<int> v2(a2, a2 + 2);
    Solution s;
    print_vector(s.intersect(v1, v2));

    return 0;
}