priority_queue<pair<int, int>> pq;
unordered_map<int, int> freq;
vector<int> res;

for (int num : nums)
  ++freq[num];

for (auto a : freq)
{
  pq.push(make_pair(-a.second, a.first));
  if (pq.size() > k)
    pq.pop();
}

while (!pq.empty()){
  res.push_back(pq.top().second);
  pq.pop();
}
return res;
