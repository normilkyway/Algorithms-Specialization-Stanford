#include <bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int> candies)
{
    set<int> set(candies.begin(), candies.end());
    return min(set.size(), candies.size() / 2);
}