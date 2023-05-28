#include <iostream>

using namespace std;

/*
 If n is even, the algorithm divides it by two, and if n is odd,
 the algorithm multiplies it by three and adds one. The algorithm
 repeats this, until n is one. For example, the sequence for n=3 is:
 3 10 5 16 8 4 2 1
*/
int main()
{
    long long n;
    cin >> n;
    while (n != 1)
    {
        cout << n << " ";
        if (n % 2 == 0)
            n /= 2;
        else
        {
            n *= 3;
            ++n;
        }
    }
    cout << n;
}
