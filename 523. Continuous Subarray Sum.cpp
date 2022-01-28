unordered_set<int> s;
int sum = 0, pre = 0;

for (int i = 0; i < nums.size(); ++i)
{
  sum += nums[i];
  if (s.count(sum % k))
    return true;
  s.insert(pre);
  pre = sum % k;
}
return false;