#include <iostream>
#include <map>
#include <string>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int EndStringBegin = 0, EndStringEnd = 0;
    	//int SubStringBegin = 0, SubStringEnd = 0;
    	map<char , int > my_map;
    	int maxlen = 0;

    	for (int i = 0; i < s.size(); ++i)
		{
		 	if(my_map.count(s[i]) != 0)
		 	{
		 		for(int j = my_map[s[i]] - 1; j >= EndStringBegin; j--)
		 		{
		 			my_map.erase(s[j]);
		 		}
		 		EndStringBegin = my_map[s[i]] + 1;
		 		EndStringEnd = i;
		 		cout << EndStringBegin << " " << EndStringEnd << endl;
		 		my_map[s[i]] = i;
		 	}
		 	else
		 	{
		 		EndStringEnd = i;
		 		my_map[s[i]] = i;

		 	}

		 	if(EndStringEnd - EndStringBegin  + 1 > maxlen)
		 	{
		 		maxlen = EndStringEnd - EndStringBegin + 1;
		 		//SubStringBegin = EndStringBegin;
		 		//SubStringEnd = EndStringEnd;
		 	}
		}

		return maxlen; 
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	int out  = s.lengthOfLongestSubstring("vqblqcb");
	cout << out << endl;
	return 0;
}