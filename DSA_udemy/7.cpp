#include <bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess)
{
    int A = 0, B = 0;
    for (int i = secret.size() - 1; i >= 0; --i) // set A
    {
        if (secret[i] == guess[i])
        {
            ++A;
            secret.erase(i, 1);
            guess.erase(i, 1);
        }
    }

    map<char, int> mS, mG;
    for (auto const &i : secret)
        mS[i] += 1;
    for (auto const &i : guess)
        mG[i] += 1;

    for (auto i : mS)
        B += min(i.second, mG[i.first]);

    stringstream sstream;
    sstream << A << "A" << B << "B";
    return sstream.str();
}

int main()
{
    cout << getHint("1123", "0111");
}