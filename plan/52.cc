#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <unordered_map>

#include <algorithm>
#include <cstring>
#include <climits>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class NumMatrix
{
  private:
    vector<vector<int>> sum;

  public:
    NumMatrix(vector<vector<int>> matrix)
    {
        int rows = matrix.size();
        if (rows == 0)
            return;
        int cols = matrix[0].size();
        if (cols == 0)
            return;

        vector<int> tmp(cols + 1, 0);
        sum.resize(rows + 1, tmp);

        for (int i = 1; i <= rows; i++)
        {
            for (int j = 1; j <= cols; j++)
            {
                sum[i][j] = matrix[i-1][j-1] + 
                             sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] ;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return sum[row2 + 1][col2 + 1] - sum[row2 + 1][col1] - sum[row1][col2 + 1] + sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

int main()
{
    {
        vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
                                      {5, 6, 3, 2, 1},
                                      {1, 2, 0, 1, 5},
                                      {4, 1, 0, 1, 7},
                                      {1, 0, 3, 0, 5}};

        NumMatrix m(matrix);
        cout << m.sumRegion(2, 1, 4, 3) << endl;
        cout << m.sumRegion(1, 1, 2, 2) << endl;
        cout << m.sumRegion(1, 2, 2, 4) << endl;
    }
    return 0;
}
