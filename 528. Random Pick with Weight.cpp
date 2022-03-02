public:
Solution(vector<int> &w)
{
  sum = w;
  for (int i = 1; i < w.size(); ++i)
  {
    sum[i] += sum[i - 1];
  }
}

int pickIndex()
{
  int x = rand() % sum.back() + 1, l = 0, r = sum.size() - 1;
  while (l < r)
  {
    int mid = l + (r - l) / 2;
    if (sum[mid] < x)
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}

private:
vector<int> sum;