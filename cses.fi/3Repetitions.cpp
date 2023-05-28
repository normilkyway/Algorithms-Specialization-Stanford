#include <iostream>
#include <string>

using namespace std;

int main()
{
    string in;
    cin >> in;
    int l = 1;
    for (int i = 1; i < in.size(); i++)
    {
        char prev = in[i - 1];
        int t = 1;
        while (in[i] == prev)
        {
            ++t;
            ++i;
        }
        l = max(l, t);
    }
    cout << l;
}