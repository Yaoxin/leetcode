#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	//DP
    vector<vector<int> > generate(int numRows) {
    	std::vector<vector<int> > out;
    	std::vector<int> cur;
    	std::vector<int> pre;
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
    		out.push_back(cur);
    		pre = cur;
    		cur.clear();
    	}
        
        return out;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<vector<int> > v;
	v = s.generate(5);

	cout << "["<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout << "	"<<"[ ";
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout <<v[i][j]<<" ";
		}
		cout <<"]"<<endl;
	}
	cout << "]"<<endl;

	return 0;
}