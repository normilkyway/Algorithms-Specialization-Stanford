#include <iostream>
#include <unordered_set>

using namespace std;

/*
 */
int main()
{
    long long n;
    cin >> n;
    unordered_set<long long> m;
    for (long long i = 1; i <= n; i++)
        m.emplace(i);
    for (long long i = 0; i < n - 1; i++)
    {
        long long v;
        cin >> v;
        m.erase(v);
    }
    cout << *m.begin();
}
