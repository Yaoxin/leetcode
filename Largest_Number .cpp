#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

/*
template <typename T>
void to_string(string &result , const T &t)
{
	ostringstream oss;
	oss << t;
	result = oss.str();
}
*/

int largest_compare(int a, int b)
{
	/*
	string str1, str2;
	to_string(str1, a);
	to_string(str2, boo);
	string temp = str1;
	str1 += str2;
	str2 += temp;
	return strcmp(str1.c_str(), str2.c_str());
	*/

	return to_string(a) + to_string(b) >= to_string(b) + to_string(a)?1:-1;
	
}



class Solution {
public:
	//n^2
	//发现用自己实现的to_string为117ms，而用系统实现的to_string为186ms,真是晕
	//想要提高速度，可以用内置的sort优化,网上大多数这种做法，时间复杂度nlogn
    string largestNumber(vector<int>& nums) {
    	std::vector<int> v;
    	std::vector<int>::iterator iter;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		for(iter = v.begin(); iter != v.end(); ++iter)
    		{
    			if(largest_compare(nums[i], *iter) >= 0)
    			{
    				break;
    			}
    		}
    		v.insert(iter, nums[i]);

    	}

    	string out;
    	string temp;
    	for (int i = 0; i < v.size(); ++i)
    	{
    		/*
    		to_string(temp, v[i]);
    		out += temp;
    		*/
    		out += to_string(v[i]);
    	}

    	if(out[0] == '0')
    	{
    		out = "0";
    	}

    	return out;
    }
};

int main(int argc, char const *argv[])
{
	//int a[] = {3, 30, 34, 5, 9};
	int a[] = {2, 1};
	std::vector<int> v(a, a + 2);
	Solution s;
	string out = s.largestNumber(v);
	cout << out << endl;
	return 0;
}