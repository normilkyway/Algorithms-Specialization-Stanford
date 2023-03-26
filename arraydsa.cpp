#include <bits/stdc++.h>
// #include <array>
using namespace std;

void change(array<int, 4> &al, int i, int val) {
    al[i] = val;
}

int main() {

    array<int, 4> arr = {1, 2, 3, 4};
    change(arr, 0, 10);
    
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
        cout << arr[i] << " ";

    return 0;
}