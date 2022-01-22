int l = 0, r = nums.size() - 1;

while (l < r)
{
  int mid = l + (r - l) / 2;
  int cnt = 0;
  for (auto num : nums)
  {
    if (num <= mid)
      ++cnt;
  }
  if (cnt <= mid)
    l = mid + 1;
  else
    r = mid;
    
}
return l;