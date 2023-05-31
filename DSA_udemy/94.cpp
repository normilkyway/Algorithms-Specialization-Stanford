#include <bits/stdc++.h>
using namespace std;

int check(string x, string y)
{
    int out = 0;
    for (int i = 0; i < min(x.size(), y.size()); ++i)
        if (x[i] != y[i])
            out += 1;
    return out + (max(x.size(), y.size()) - min(x.size(), y.size()));
}

int ladderLength(string beginWord, string endWord, vector<string> wordList)
{
    map<string, map<string, bool>> m;
    /**
     * logic:
     * 1. initialize a graph based on the wordList
     * based on strings (figure out a way to find the difference between strings --> diff characters )
     *      if off by 1 character you can add it to the list (bidirectionally, therefore undirected graph)
     *
     * 2. find the shortest path from the beginning word to the next word (basically paths are equally weighted, therefore we can use bfs)
     */
    bool used = false;
    for (auto s : wordList)
        if (s == beginWord)
        {
            used = true;
            break;
        }
    if (!used)
        wordList.push_back(beginWord);
    for (int i = 0; i < wordList.size(); ++i)
    {
        for (int j = 0; j < wordList.size(); ++j)
        {
            if (i == j)
                continue;
            if (check(wordList[i], wordList[j]) <= 1)
            {
                m[wordList[i]][wordList[j]] = true;
                m[wordList[j]][wordList[i]] = true;
            }
        }
    }
    // bfs
    queue<string> q;
    unordered_map<string, int> visited;
    q.push(beginWord);
    visited[beginWord] = 1;
    while (!q.empty())
    {
        string c = q.front();
        q.pop();
        if (c == endWord)
            return visited[c];
        for (auto n : m[c])
        {
            if (visited.count(n.first) == 0)
            {
                visited[n.first] = visited[c] + 1;
                q.push(n.first);
            }
        }
    }
    return 0;
}