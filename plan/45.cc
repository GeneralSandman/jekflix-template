#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>

#include <algorithm>
#include <cstring>
#include <climits>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class MedianFinder
{
  public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.size() == minHeap.size())
        {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else
        {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size() + 1)
            return maxHeap.top();
        else
            return (maxHeap.top() + minHeap.top()) / 2.0;
    }

  private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

int main()
{
    {
        MedianFinder finder;
        finder.addNum(1);
        cout << finder.findMedian() << endl;

        finder.addNum(2);
        cout << finder.findMedian() << endl;

        finder.addNum(3);
        cout << finder.findMedian() << endl;

        finder.addNum(4);
        cout << finder.findMedian() << endl;
    }
    return 0;
}