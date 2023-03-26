#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size()%2 == 1) return false;
        unordered_map<char, char> map;
        map[')'] = '(';
        map['('] = ')';
        map[']'] = '[';
        map['['] = ']';
        map['{'] = '}';
        map['}'] = '{';
        stack<char> stacklefts, stackrights;
        bool lastadded; // false if left, true if right
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c=='(' || c=='[' || c=='{') {
                stacklefts.push(c); 
                lastadded = false;
            }
            else {
                stackrights.push(c); 
                lastadded = true;
            }

            if (!stacklefts.empty() && !stackrights.empty() && lastadded)
                if (map[stacklefts.top()] == stackrights.top()) {
                    stacklefts.pop();
                    stackrights.pop();
                }
        }
        return stacklefts.empty() && stackrights.empty();
    }
};

int main() {
    Solution solve;
    cout << (solve.isValid("(){}}{") ? "yes" : "no");
}