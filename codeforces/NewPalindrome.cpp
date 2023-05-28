#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    long long t;
    cin >> t;

    while (t-- > 0)
    {
        string s;
        cin >> s;
        bool valid = true;
        set<char> chars;
        for (int i = 0; i < s.length() / 2; i++)
        {
            if (s.at(i) != s.at(s.length() - 1 - i))
            {
                valid = false;
                break;
            }
            else
            {
                chars.insert(s.at(i));
            }
        }
        cout << (valid && (chars.size() > 1) ? "YES" : "NO") << "\n";
    }
}