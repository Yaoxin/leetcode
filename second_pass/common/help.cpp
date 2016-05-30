#include "help.h"

void print_vector(string msg, std::vector<int> v)
{
    cout << msg << " ";
    for(std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}



int main(int argc, char const *argv[])
{
    std::vector<int> v(10, 1);
    print_vector("test", v);
    return 0;
}