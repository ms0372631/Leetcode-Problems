vector<vector<int>> threeSum(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  vector<vector<int>> res;

  for (int i = 0; i < nums.size(); ++i)
  {
    if (i && nums[i] == nums[i - 1])
      continue;
    int j = i + 1, k = nums.size() - 1;
    while (j < k)
    {
      if (nums[j] + nums[k] < -nums[i])
        ++j;
      else if (nums[j] + nums[k] > -nums[i])
        --k;
      else
      {
        res.push_back({nums[i], nums[j], nums[k]});
        while (j < k && nums[j] == nums[j + 1])
          ++j;
        while (j < k && nums[k] == nums[k - 1])
          --k;
        ++j;
        --k;
      }
    }
  }
  return res;
}
