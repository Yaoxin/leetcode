#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	//采用贪心
	//正确性证明
	//命题 :第k步，能到达的最远距离是n
	//归纳基础 第一步明显正确
	//归纳步骤 若第K步，能达到的距离是n，则第K + 1步，max(n, k + 1 + A[k])
	//也是最远距离
	//如果存在一个n' 是第K + 1的最远距离,则n' != k + 1 + A[k] 且 n' != n
	//则可推第k步的最远距离是n'，与n的最优性矛盾。
    bool canJump(vector<int>& nums) {
    	if(nums.size() == 0)
    		return false;
    	int reach = 1;
    	for (int i = 0; i < reach && reach < nums.size(); ++i)
    	{
    		reach = max(reach, i + 1 + nums[i]);
    	}

    	return reach >= nums.size();
    }
};
