#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	vector<vector<int> > out;
    	std::vector<int> v;
    	out.push_back(v);
    	int n = 0;
    	int len = 0;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		n = nums[i];
    		len = out.size();
    		for(int j = 0; j < len; j++)
    		{
    			v = out[j];
    			v.push_back(n);
    			out.push_back(v);
    		}

    	}

    	return out;
    }
};


int main(int argc, char const *argv[])
{
	std::vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	Solution s;
	std::vector<std::vector<int> > a;
	a = s.subsets(v);
	std::vector<int> b;
	for(int i = 0; i < a.size(); i++)
	{
		b = a[i];
		cout << "[ ";
		for(int j = 0; j < b.size(); j++)
		{
			cout << " " << b[j];
		}
		cout << " ]";
		cout << endl;
	}
	return 0;
}


