#include <bits/stdc++.h>
using namespace std;

vector<int> smallestRange(vector<vector<int>> nums)
{
}

/*
chatgpt code solution...

#include <queue>
#include <vector>

std::pair<int, int> smallestRange(std::vector<std::vector<int>>& nums) {
    struct compare {
        bool operator()(const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) {
            return std::get<2>(a) > std::get<2>(b);
        }
    };
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, compare> minHeap;
    int maxNum = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
        std::sort(nums[i].begin(), nums[i].end());
        maxNum = std::max(maxNum, nums[i][0]);
        minHeap.push(std::make_tuple(i, 0, nums[i][0]));
    }
    int range = INT_MAX;
    std::pair<int, int> res;
    while (true) {
        auto [i, j, num] = minHeap.top();
        minHeap.pop();
        if (maxNum - num < range) {
            range = maxNum - num;
            res = {num, maxNum};
        }
        if (j + 1 == nums[i].size()) {
            break;
        }
        minHeap.push(std::make_tuple(i, j + 1, nums[i][j + 1]));
        maxNum = std::max(maxNum, nums[i][j + 1]);
    }
    return res;
}

*/