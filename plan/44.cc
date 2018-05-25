#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <cstring>
#include <climits>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Solution
{
  public:
    bool wordPattern(string pattern, string str)
    {
        vector<string> words;
        getWord(str, words);

        if (words.size() != pattern.size())
            return false;
        unordered_map<char, string> hashTable1;
        unordered_map<string, char> hashTable2;

        for (int i = 0; i < words.size(); i++)
        {
            if (hashTable1.find(pattern[i]) == hashTable1.end())
                hashTable1[pattern[i]] = words[i];
            else if (hashTable1[pattern[i]] != words[i])
                return false;

            if (hashTable2.find(words[i]) == hashTable2.end())
                hashTable2[words[i]] = pattern[i];
            else if (hashTable2[words[i]] != pattern[i])
                return false;
        }
        return true;
    }

  private:
    void getWord(const string &str, vector<string> &res)
    {
        string tmp;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != ' ')
                tmp += str[i];
            else
            {
                if (!tmp.empty())
                {
                    res.push_back(tmp);
                }
                tmp = "";
            }
        }

        if (!tmp.empty())
            res.push_back(tmp);
    }
};

int main()
{
    {
        Solution s;
        bool res = s.wordPattern("aaaa", "dog dog dog dog");
        if (res)
            cout << "can\n";
    }
    {
        Solution s;
        bool res = s.wordPattern("abba", "dog cat cat fish");
        if (res)
            cout << "can\n";
    }
    {
        Solution s;
        bool res = s.wordPattern("abca", "dog cat cat dog");
        if (res)
            cout << "can\n";
    }
    return 0;
}