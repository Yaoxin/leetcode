#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	//every operator will be the last one
	//it will have a lot of same operator
    vector<int> diffWaysToCompute(string input) {
    	vector<int> result;
    	for (int i = 0; i < input.size(); ++i)
    	{
    		if(input[i] == '+' || input[i] == '-' || input[i] == '*')
    		{
    			vector<int> result1 = diffWaysToCompute(input.substr(0, i));
    			vector<int> result2 = diffWaysToCompute(input.substr(i + 1));
    			for(int j = 0; j < result1.size(); j++)
    			{
    				for(int k = 0; k < result2.size(); k++)
    				{
    					if(input[i] == '+')
    					{
    						result.push_back(result1[j] + result2[k]);
    					}
    					else if(input[i] == '-')
    					{
    						result.push_back(result1[j] - result2[k]);
    					}
    					else 
    					{
    						result.push_back(result1[j] * result2[k]);
    					}
    				}
    			}
    		}
    	}

    	if(result.size() == 0 && input.size() != 0)
    	{
    		result.push_back(atoi(input.c_str()));
    	}
    	return result;
    }

    //dp solution 
    vector<int> dp_helper(string input, map<string, vector<int> > &dp_map)
    {
    	if(dp_map.count(input) != 0)
    		return dp_map[input];

    	vector<int> result;	
    	for(int i = 0; i < input.size(); i++)
    	{
    		char cur = input[i];
    		if(cur == '+' || cur == '-' || cur == '*')
    		{
    			vector<int> result1 = dp_helper(input.substr(0, i), dp_map);
    			vector<int> result2 = dp_helper(input.substr(i + 1), dp_map);
    			for (int j = 0; j < result1.size(); ++j)
    			{
    				for(int k = 0; k < result2.size(); ++k)
    				{
    					if(cur == '+')
		    			{
		    				result.push_back(result1[j] + result2[k]);
		    			}
		    			else if(cur == '-')
		    			{
		    				result.push_back(result1[j] - result2[k]);
		    			}
		    			else
		    			{
		    				result.push_back(result1[j] * result2[k]);
		    			}
    				}
    			}
    		}
    	}

    	if(result.size() == 0 && input.size() != 0)
    	{
    		result.push_back(atoi(input.c_str()));
    	}
    	dp_map[input] = result;
    	return result;
    }

    //use a map to store the value 
    vector<int> diffWaysToCompute_dp(string input) {
    	std::map<string, vector<int> > dp_map;
    	return dp_helper(input, dp_map);
    }
};




int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<int> v;
	v = s.diffWaysToCompute_dp("2-1-1");
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}

	return 0;
}

