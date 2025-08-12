class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> need;
        
        int count=0;
        for(int i=0;i<n;++i)
        {
            if((arr[i]%k)!=0)
            {
                need.push_back(k-(arr[i]%k));
            }
            else count++;
        }
        int ans=0;
        if(count<(n+1)/2)
        {
            int rem=(n+1)/2-count;
            sort(need.begin(),need.end());
            while(rem)
            {
                ans+=need[rem-1];
                rem--;
            }
        }
        return ans;
    }
};