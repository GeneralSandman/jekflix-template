class Solution
{
  public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> tmp;
        for (auto t : words)
        {
            tmp[t]++;
        }
        typedef pair<string, int> key;
        auto comp = [](const key &a, const key &b) { return a.second == b.second ? a.first > b.first : a.second < b.second; };
        priority_queue<key, vector<key>, decltype(comp)> q(comp);

        for (auto t : tmp)
        {
            q.push(t);
        }

        vector<string> res;
        while (!q.empty() && k--)
        {
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    };

  private:
};
