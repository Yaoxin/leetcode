#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
    	string out;
    	if(s.length() == 0 || nRows == 0 )
    	{
    		return out;
    	}
    	if( nRows == 1)
    	{
    	   return s; 
    	}

    	bool exchanged = true;
    	for(int i = 0; i < nRows; i++)
    	{
    		exchanged = true;
    		for(int j = i; j  < s.length();)
    		{
    			out += s[j];
    			if(i == 0 || i == (nRows - 1))
    				j += 2 *(nRows - 1);
    			else
    			{
    				cout << "j fist" << j << endl;
    				j += (exchanged == true)?(2 *(nRows - 1 - i)):(2*i);
    				exchanged = (exchanged == true)?false:true;
    				cout << "j" << j << endl;
    			} 
    		}
    	}
    	return out;
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	string out = s.convert("ABCDE", 4);
	cout << out << endl;
	return 0;
}