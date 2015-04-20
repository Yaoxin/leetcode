#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
	//18ms
    void reverseWords_bak(string &s) {
    	string output;
    	string temp;
    	int k = 0;

    	while(s[k] == ' ')
    		k++;
    	for(int i = k; i < s.size(); )
    	{
    		if(s[i] != ' ')
    		{
    			temp += s[i++];
    		}
    		else
    		{
    			while(s[i] == ' ')
    				i++;
    			if(i == s.size())
    				break;
    			output = ' ' + temp + output;	
    			temp = "";
    		}
       	}

       	s = temp + output;
    }


//10ms
    void reverseWords(string &s)
    {
    	string output;
    	string temp;
    	int position = 0;
    	int start = 0;
        bool tag = false;

    	position =  s.find_first_not_of(' ');
    	if(position != string::npos)
    	{
    		start = position;
    		while((position = s.find(' ' , position)) != string::npos)
    		{
    			temp = s.substr(start, position - start);
    			while(s[position] == ' ')
    			    position++;
    			if(position == s.size())
    			    break;
    			start = position;
    			output = ' ' + temp + output;
    		}
    		temp = s.substr(start);
    		position = temp.find_last_not_of(' ');
    		temp.erase(position + 1);
    		output = temp + output;
    	}
    	s = output;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string test = "hello world good fyliu";
	s.reverseWords(test);
	cout << "first *"<<test << endl;
	s.reverseWords_bak(test);
	cout << "second *" << test << endl;

	return 0;
}

