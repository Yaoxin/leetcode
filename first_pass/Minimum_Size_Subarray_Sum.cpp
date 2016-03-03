#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int begin = 0, end = 0;
    	int min = nums.size() + 1;
    	int sum = 0;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		sum += nums[i];
    		while(sum >= s)
    		{
    			//printf("begin = %d, end = %d\n", begin, end);
    			min = (end - begin + 1) < min?(end - begin + 1):min;
    			sum -= nums[begin++];
    		}
			end++;
    	}

    	return min == (nums.size() + 1)?0:min;
    }
};

int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,5};
	std::vector<int> v(a, a + 5);
	Solution s;
	int test = s.minSubArrayLen(11, v);
	cout << test << endl;


	return 0;
}