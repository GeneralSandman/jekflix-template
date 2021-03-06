class Solution
{
  private:
    static bool comp(const int &a, const int &b)
    {
        string tmpa, tmpb;
        tmpa = to_string(a);
        tmpb = to_string(b);
        return (tmpa + tmpb) > (tmpb + tmpa);
    }

  public:
    string largestNumber(vector<int> &nums)
    {
        string res;
        sort(nums.begin(), nums.end(), comp);
        for (auto t : nums)
            res += to_string(t);

        int i = 0;
        for (; i < res.size(); i++)
            if (res[i] != '0')
                break;
                
        if (i == res.size())
            return "0";
        string tmp(res.c_str() + i);
        return tmp;
    }
};

