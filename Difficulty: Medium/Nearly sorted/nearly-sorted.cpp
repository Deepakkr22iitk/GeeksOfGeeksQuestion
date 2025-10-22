class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n=arr.size();
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        // pushing first k elements in pq
        for (int i = 0; i < k; i++)
            pq.push(arr[i]);
    
        int i;
    
        for (i = k; i < n; i++) {
    
            pq.push(arr[i]);
    
            // size becomes k+1 so pop it
            // and add minimum element in (i-k) index
            arr[i - k] = pq.top();
            pq.pop();
        }
    
        // puting remaining elements in array
        while (!pq.empty()) {
            arr[i - k] = pq.top();
            pq.pop();
            i++;
        }
        
        return ;
    }
};