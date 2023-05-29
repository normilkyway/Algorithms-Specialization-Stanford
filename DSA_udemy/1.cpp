#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s)
{
    map<char, pair<int, int>> m; // char, <first index, frequency>
    for (int i = 0; i < s.size(); ++i)
    {
        if (m.count(s[i]) == 0) // doesn't exist yet, therefore in the first index
            m[s[i]] = make_pair(i, 1);
        else
            m[s[i]].second += 1; // increment the second value by 1
    }
    int firstUniqueIndex = -1;
    for (auto const &pair : m)
    { // the map will not be sorted in insertion order
        if (pair.second.second == 1 && ((firstUniqueIndex == -1) || (pair.second.first < firstUniqueIndex)))
            firstUniqueIndex = pair.second.first;
    }
    return firstUniqueIndex;
}

int main()
{
    string s = "aabbbcc";
    cout << firstUniqChar(s);
}