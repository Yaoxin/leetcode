#include <iostream>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
    	map<char, int> my_map;
    	for (int i = 0; i < s.size(); ++i)
    	{
    		if(my_map.count(s[i]))
    		{
    			my_map[s[i]] += 1;
    		}
    		else
    		{
    			my_map[s[i]] = 1;
    		}
    	}

    	for(int i = 0; i < t.size(); ++i)
    	{
    		if(!my_map.count(t[i]))
    			return false;
    		my_map[t[i]] -= 1;
    		if(my_map[t[i]] == 0)
    		{
    			my_map.erase(t[i]);
    		}
    	}

    	if(my_map.size())
    		return false;
    	return true;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	bool out = s.isAnagram("anagram", "nagaram");
	cout << out << endl;
	return 0;
}