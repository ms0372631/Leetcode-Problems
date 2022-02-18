class Solution
{
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    vector<int> res;
    graph_ = vector<vector<int>>(numCourses);
    vector<int> v(numCourses, 0);
    for (auto p : prerequisites)
    {
      graph_[p[1]].push_back(p[0]);
    }
    for (int i = 0; i < numCourses; ++i)
    {
      if (dfs(i, v, res))
        return {};
    }
    reverse(res.begin(), res.end());
    return res;
  }

private:
  vector<vector<int>> graph_;
  bool dfs(int cur, vector<int> &v, vector<int> &res)
  {
    if (v[cur] == 2)
      return false;

    if (v[cur] == 1)
      return true;

    v[cur] = 1;

    for (auto a : graph_[cur])
    {
      if (dfs(a, v, res))
        return true;
    }
    res.push_back(cur);
    v[cur] = 2;

    return false;
  }
};