

unordered_map<string, vector<string>> m;
vector<vector<string>> res;

for (string s : strings) {
  char pivot = s[0];
  string key;
  for (char c : s[i]) 
    key += (c - pivot - 'a' + 26) % 26 + 'a';
  m[key].push_back(s);
}

for (auto a : m) {
  res.push_back(a.second);
}

return res;