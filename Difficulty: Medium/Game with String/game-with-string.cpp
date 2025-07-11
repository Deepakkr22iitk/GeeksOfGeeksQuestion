class Solution {
  public:
    int minValue(string &s, int k) {
        vector<int> count(26,0);
        for(char i:s) count[i-'a']++;
        priority_queue<int> q;
        for(auto i:count) q.push(i);
        while(k!=0 && !q.empty()){
            int top = q.top();
            q.pop();
            top--;
            if(top>0) q.push(top);
            k--;
        }
        int ans=0;
        while(!q.empty()){
            ans+=q.top()*q.top();
            q.pop();
        }
        return ans;
    }
};