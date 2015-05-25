#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	set<int> iset(nums.begin(), nums.end());

    	return (iset.size() != nums.size())?true:false;        
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int a[] = {2, 3, 5,4};
	std::vector<int> v(a, a + 4);
	bool test = s.containsDuplicate(v);
	cout << test << endl;
	return 0;
}