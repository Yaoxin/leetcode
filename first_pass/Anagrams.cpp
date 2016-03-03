#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
    	map<string, vector<string> >my_map;
    	for (int i = 0; i < strs.size(); ++i)
    	{
    		string temp(strs[i]);
    		sort(temp.begin(), temp.end());
    		my_map[temp].push_back(strs[i]);
    	}

    	vector<string> out;
    	for(map<string, vector<string> >::iterator iter = my_map.begin(); iter != my_map.end(); iter++)
    	{
    		if(iter->second.size() > 1)
    		{
    			for(int i = 0; i < iter->second.size(); i++)
    			{
    				out.push_back(iter->second[i]);
    			}
    		}
    	}

    	return out; 
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<string> strs;
	strs.push_back("");
	strs.push_back("");
	strs.push_back("");
	vector<string> out = s.anagrams(strs);
	for (int i = 0; i < out.size(); ++i)
	{
		cout << "1" << out[i] << endl;
	}
	return 0;
}