#include <iostream>
#include <string>
#include <map>


using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
    		if(s.size() != t.size())
    			return false;

    	std::map<char, char> hash;
    	std::map<char, char>::iterator iter;

    	for (int i = 0; i < s.size(); ++i)
    	{
    		iter = hash.find(s[i]);
    		if(iter != hash.end())
    		{
    			if(iter->second != t[i])
    			{
    				return false;
    			}
    		}
    		else
    		{
    			for(iter = hash.begin(); iter != hash.end(); iter++)
    			{
    				if(iter->second == t[i])
    				{
    					return false;
    				}
    			}
    			hash[s[i]] = t[i];
    		}
    	}

    	return true;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	bool test = s.isIsomorphic("ab", "ca");
	cout << test  << endl;
	return 0;
}