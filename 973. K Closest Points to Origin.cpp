 vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> res;
        
        for (int i = 0; i < points.size(); ++i) {
            pq.push(make_pair(pow(points[i][0], 2) + pow(points[i][1], 2), i));
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }