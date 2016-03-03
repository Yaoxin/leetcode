#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	string out;
        if(strs.size() == 0)
            return out;
    	string str = strs[0];
    	int i = 0, j = 0;
    	int end = -1;
        bool flag = false;
    	for(i = 0; i < str.size(); i++)
    	{
    		for(j = 1; j < strs.size(); ++j)
    		{
    			if(strs[j][i] != strs[0][i])
                {
                    cout << i << endl;
                    flag = true;
                    break;
                }
    		}
    		if(flag == true)
    		{
    			break;
    		}
    		else
    		{
    			end = i;
    		}
    	}

    	if(end == -1)
    		return out;
    	out = strs[0].substr(0, end + 1);
        return out;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<string> v;
    v.push_back("aa");
    v.push_back("ab");
    Solution s;
    string out;
    out  = s.longestCommonPrefix(v);
    cout << out << endl;
    return 0;
}