#include <iostream>
using namespace std;
#define ll long long

ll[][] gridify(ll layers)
{
    long long m = layers * layers;
    ll out[m][m];
    int[] dx = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}; //! move left OR right
    long long x = 0, y = 0, val = 1;
    bool left = true;
    // iteration --> 1, 3, 5, 7, 9

    for (long long i = 0; i < layers; ++i)
    {
        out[x][y] = val++; // iterate the value by 1 that way next value can be set correctly...
        for (long long k = 1; k <= 2 * i + 1; ++k)
        {
            x += dx[i % 4];
            y += dy[i % 4];
            out[x][y] = val++;
        }
    }

    return out;
}

int main()
{
    gridify(1);
    // ll n;
    // cin >> n;
    // ll maxx = 0, maxy = 0;
    // while (n-- > 0)
    // {
    //     ll x, y;
    //     cin >> y >> x;
    //     maxx = max(maxx, x);
    //     maxy = max(maxy, y);
    // }
    // //! find the max # of layers and then generate the grid
    // //! to solve...
    // ll g[m][m] = gridify(max(maxy, maxx));
}