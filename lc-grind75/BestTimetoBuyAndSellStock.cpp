#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxdif = 0;
        for (int i = 0; i < prices.size(); i++) 
            for (int j = i + 1; j < prices.size(); j++) 
                maxdif = maxdif < (prices[j] - prices[i]) ? (prices[j] - prices[i]) : maxdif;
        return maxdif;
    }
};

int main() {
    Solution solve;
    vector<int> s{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << solve.maxProfit(s);
    
    return 0;
}