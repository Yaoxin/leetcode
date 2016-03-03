#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    	std::vector<int> out;
    	if(nums.size() == 0)
    		return out;
    	int num1 = -1, num2 = -1;
    	int count1 = 0, count2 = 0;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if(count1 == 0 )
    			num1 = nums[i];
    		if(count2 == 0 && nums[i] != num1)
    			num2 = nums[i];
    		if(nums[i] == num1)
    			++count1;
    		else if(nums[i] == num2)
    			++count2;
    		else 
    		{
    			--count1;
    			--count2;
    		}

    		cout << i<< " "<< count1 << " " << count2 << endl;
    	}

    	int count = 0;
    	for (int i = 0; i < nums.size() && count1 > 0; ++i)
    	{
    		if(num1 == nums[i])
    			count++;
    	}
    	if(count > nums.size()/3)
    		out.push_back(num1);

    	count = 0;
    	for (int i = 0; i < nums.size() && count2 >0 && num2 != num1; ++i)
    	{
    		if(num2 == nums[i])
    			count++;	
    	}
    	if(count > nums.size()/3)
    		out.push_back(num2);

    	return out;
    }
};

int main(int argc, char const *argv[])
{
	int a[] = {-1,1,1,1,2,1};
	std::vector<int> v(a, a + 6);
	Solution s;
	std::vector<int> out;
	out = s.majorityElement(v);
	for (int i = 0; i < out.size(); ++i)
	{
		cout << out[i] << endl;
	}
	return 0;
}