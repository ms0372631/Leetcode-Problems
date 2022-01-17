public:
int largestIsland(vector<vector<int>> &grid)
{
  g = &grid;
  m = grid.size();
  n = grid[0].size();
  color = 1;
  unordered_map<int, int> areas;
  int res = 0;

  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (grid[i][j] == 1)
      {
        ++color;
        areas[color] = getArea(i, j);
        res = max(res, areas[color]);
      }
    }
  }

  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (grid[i][j] == 0)
      {
        int sum = 1;
        for (int color : set<int>{getColor(i - 1, j), getColor(i + 1, j), getColor(i, j - 1), getColor(i, j + 1)})
        {
          sum += areas[color];
          res = max(res, sum);
        }
      }
    }
  }
  return res;
}

int getColor(int x, int y)
{
  return (x < 0 || x >= m || y < 0 || y >= n) ? 0 : (*g)[x][y];
}

int getArea(int x, int y)
{
  if (x < 0 || x >= m || y < 0 || y >= n || (*g)[x][y] != 1)
    return 0;
  (*g)[x][y] = color;
  return 1 + getArea(x - 1, y) + getArea(x + 1, y) + getArea(x, y - 1) + getArea(x, y + 1);
}

private:
int m;
int n;
int color;
vector<vector<int>> *g;
}
;