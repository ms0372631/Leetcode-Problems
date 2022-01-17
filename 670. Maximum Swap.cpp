

string s = to_string(num);
int res = num;

for (int i = 0; i < s.size(); ++i)
{
  for (int j = i + 1; j < s.size(); ++j)
  {
    swap(s[i], s[j]);
    if (stoi(s) > res)
      res = stoi(s);
    swap(s[i], s[j]);
  }
}
return res;