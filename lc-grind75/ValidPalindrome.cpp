#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string buildproper = "";
        for (int i = 0; i < s.size(); i++) 
            if (isalpha(s[i]) || isdigit(s[i]))
                buildproper.push_back(tolower(s[i]));

        for (int i = 0; i < buildproper.size()/2; i++) {
            if (buildproper[i] != buildproper[buildproper.size() - i - 1])
                return false;
        }
        return true;
    }
};

int main() {
    Solution solve; 
    cout << (solve.isPalindrome("0P") ? "yes" : "no");
}