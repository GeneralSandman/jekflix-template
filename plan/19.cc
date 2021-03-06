#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
    vector<string> hashTable;

  public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        hashTable = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                     "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

        unordered_set<std::string> table;

        for (auto t : words)
        {
            table.insert(convert(t));
        }

        return table.size();
    }

  private:
    string convert(const string &a)
    {
        string res;
        for (auto t : a)
            res += hashTable[t - 'a'];

        return res;
    }
};

int main()
{
    Solution a;
    vector<string> wordList = {"gin", "zen", "gig", "msg"};
    cout << a.uniqueMorseRepresentations(wordList) << endl;
    return 0;
}

