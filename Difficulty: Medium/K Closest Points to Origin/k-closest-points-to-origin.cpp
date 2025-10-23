class Solution {
  public:
    // Function to calculate squared distance from the origin
    int squaredDis(vector<int>& point) {
        return point[0] * point[0] + 
          point[1] * point[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap to store points with their 
        // squared distances
        priority_queue<pair<int, vector<int>>> maxHeap;
    
        // Iterate through each point
        for (int i = 0; i < points.size(); i++) {
            int dist = squaredDis(points[i]);
    
            if (maxHeap.size() < k) 
            {
                
                // If the heap size is less than k, 
                // insert the point
                maxHeap.push({dist, points[i]});
            } 
            else
            {
                
                // If the heap size is k, compare with
                // the top element
                if (dist < maxHeap.top().first) {
                    
                    // Replace the top element if the
                    // current point is closer
                    maxHeap.pop();
                    maxHeap.push({dist, points[i]});
                }
            }
        }
        
        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
    
        return res;
    }
};