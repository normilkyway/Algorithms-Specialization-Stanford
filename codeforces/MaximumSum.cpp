#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t-- > 0)
    {
        long long n, k; //! "n" elements, "k" operations
        cin >> n >> k;
        vector<long long> v(n);
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
            sum += v[i];
        }
        sort(v.begin(), v.end());
        //! 0, 1, 2, 3, 4, 4, 4, 5

        int a = 0, b = 1, e = v.size() - 1;
        long long rm = 0;
        if (k == 1)
        {
            while (k-- > 0)
            {
                if (v[a] + v[b] <= v[e])
                {
                    rm += v[a] + v[b];
                    a += 2;
                    b += 2;
                }
                else
                {
                    rm += v[e];
                    e -= 1;
                }
            }
            cout << (sum - rm) << "\n";
        }
        else
        {
            long long start, end;
            for (int i = 0; i < n && b <= e; ++i, a += 2, b += 2, e -= 1)
            {
                start += (v[a] + v[b]);
                end += v[e];

                cout << v[a] << " " << v[b] << " " << v[e] << "\n";
                cout << "start: " << start << " end: " << end << "\n";
            }
            cout << max(start, end) << "\n";
        }
    }
}

/*
6
5 1
2 5 1 10 6
5 2
2 5 1 10 6
3 1
1 2 3
6 1
15 22 12 10 13 11
6 2
15 22 12 10 13 11
5 1
999999996 999999999 999999997 999999998 999999995
*/