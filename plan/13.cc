#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stdio.h>
#include <cmath>
#include <stack>
#include <climits>

using namespace std;

class Solution
{
    vector<vector<long long>> graph;
    vector<long long> timesFromK;
    vector<bool> visited;

  public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {
        vector<long long> line(N, -1);
        graph.resize(N, line);
        timesFromK.resize(N, LONG_MAX);

        for (auto t : times)
            graph[t[0] - 1][t[1] - 1] = t[2];

        for (auto t : graph)
        {
            for (auto i : t)
                cout << i << " ";
            cout << endl;
        }

        Dijkstra(K - 1, N);
        long long res = -1;
        for (auto t : timesFromK)
        {
            if (t == LONG_MAX)
                return -1;
            else
                res = max(res, t);
        }
        return res;
    }

  private:
    void Dijkstra(int begin,
                  int N)
    {
        visited.resize(N, false);

        timesFromK[begin] = 0;
        visited[begin] = true;

        while (true)
        {

            for (int i = 0; i < N; i++)
            {
                if (graph[begin][i] != -1)
                    if (timesFromK[i] > timesFromK[begin] + graph[begin][i])
                    {
                        timesFromK[i] = timesFromK[begin] + graph[begin][i];
                    }
            }

            long long minNum = LONG_MAX;
            int minIndex = -1;
            for (int i = 0; i < N; i++)
            {
                if (!visited[i] && timesFromK[i] < minNum)
                {
                    minIndex = i;
                    minNum = timesFromK[i];
                }
            }

            if (minIndex == -1)
                break;
            if (minIndex == begin)
                break;
            begin = minIndex;
            visited[begin] = true;
        }
    }
};

int main()
{

    Solution a;

    vector<vector<int>> times;
    times.push_back({1, 2, 10});
    times.push_back({1, 3, 3});
    times.push_back({2, 5, 10});
    times.push_back({3, 4, 3});
    times.push_back({4, 6, 4});
    times.push_back({6, 7, 5});

    cout << a.networkDelayTime(times, 7, 1) << endl; //20

    Solution b;
    vector<vector<int>> times2;
    times2.push_back({1, 2, 1});
    times2.push_back({2, 1, 3});
    cout << b.networkDelayTime(times2, 2, 2) << endl; //3

    return 0;
}

