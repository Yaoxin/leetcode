#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	//DP
    vector<int> getRow(int rowIndex) {
    	std::vector<int> cur;
    	std::vector<int> pre;
        int numRows = rowIndex + 1;
    	while(numRows--)
    	{
    		cur.push_back(1);
    		for (int i = 1; i < pre.size(); ++i)
    		{
    			cur.push_back(pre[i - 1] + pre[i]);
    		}
    		if(pre.size() != 0)
    		{
    			cur.push_back(1);
    		}
    		pre = cur;
    		cur.clear();
    	}
        
        return pre;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v;
    v = s.getRow(3);
    cout << "[ ";
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "]"<<endl;
    return 0;
}