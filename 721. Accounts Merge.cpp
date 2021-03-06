vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
  unordered_map<string, set<string>> m;
  unordered_map<string, string> owner, root;
  vector<vector<string>> res;

  for (auto account : accounts)
  {
    for (int i = 1; i < account.size(); ++i)
    {
      root[account[i]] = account[i];
      owner[account[i]] = account[0];
    }
  }

  for (auto account : accounts)
  {
    string p = find(account[1], root);
    for (int i = 2; i < account.size(); ++i)
    {
      root[find(account[i], root)] = p;
    }
  }

  for (auto account : accounts)
  {
    for (int i = 1; i < account.size(); ++i)
    {
      m[find(account[i], root)].insert(account[i]);
    }
  }

  for (auto a : m)
  {
    vector<string> v(a.second.begin(), a.second.end());
    v.insert(v.begin(), owner[a.first]);
    res.push_back(v);
  }

  return res;
}
string find(string &s, unordered_map<string, string> &root)
{
  return s == root[s] ? s : find(root[s], root);
}