#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	//这个解法很诡异，值得思考
    int singleNumber(vector<int>& nums) {
        int ones = 0, two = 0, three = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
        	two |= ones & nums[i];
        	ones ^=nums[i];

        	three = ones & two;
        	ones &= ~three;
        	two  &= ~three;
        }

        return ones;
    }
};