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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *headOdd = nullptr;
        ListNode *headEven = nullptr;

        getAddandEven(head, headOdd, headEven);

        ListNode *tmp = headOdd;
        while (tmp->next != nullptr)
            tmp = tmp->next;
        tmp->next = headEven;
        return headOdd;
    }

  private:
    void getAddandEven(ListNode *head, ListNode *&odd, ListNode *&even)
    {
        if (head == nullptr)
        {
            odd = nullptr;
            even = nullptr;
            return;
        }
        else if (head->next == nullptr)
        {
            odd = head;
            even = nullptr;
            return;
        }
        else
        {
            odd = head;
            even = head->next;

            getAddandEven(head->next->next, odd->next, even->next);
        }
    }
};

int main()
{
    return 0;
}