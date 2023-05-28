#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long v[n];
    // had to change the order of inputting stuff and incrementing the
    // counter, otherwise undefined behavior...
    for (int i = 0; i < n; cin >> v[i] && ++i)
        ;
    long long t = 0;
    for (int i = 1; i < n; ++i)
    {
        long long prev = v[i - 1];
        long long curr = v[i];
        // cout << prev << " " << curr << "\n";
        if (curr < prev)
        {
            t += prev - curr;
            v[i] = prev;
        }
    }
    cout << t;
}