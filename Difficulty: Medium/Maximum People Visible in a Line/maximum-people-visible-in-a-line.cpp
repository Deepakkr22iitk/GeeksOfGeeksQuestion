class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        int n = arr.size();
        
        if (n==1) return 1;
        
        vector<int> res(n, 0);
        
        stack<int> stk;
        stk.push(0);
        
        for (int i=1; i<n; i++) {
            while (!stk.empty() && arr[stk.top()]<arr[i]) stk.pop();
            if (stk.size()) res[i] += i-stk.top()-1;
            else res[i] += i;
            stk.push(i);
        }
        
        stack<int> clear;
        stk.swap(clear);
        
        stk.push(n-1);
        
        for (int i=n-2; i>=0; i--) {
            while (!stk.empty() && arr[stk.top()]<arr[i]) stk.pop();
            if (stk.size()) res[i] += stk.top()-i-1;
            else res[i] += n-i-1;
            stk.push(i);
        }
        
        int ans = INT_MIN;
        
        for (int x:res) {
            ans = max(ans, x+1);
        }
        
        return ans;
    }
};