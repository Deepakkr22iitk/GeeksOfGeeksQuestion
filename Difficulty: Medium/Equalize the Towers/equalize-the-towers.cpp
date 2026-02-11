class Solution {
  public:
    vector<int> costing(int f,auto h,auto c)
    {
        int n=h.size();
        int mid=0,below=0,above=0;
        vector<int> ans;
        for(int i=0;i<n;++i)
        {
            mid+=(abs(h[i]-f)*c[i]);
            below+=(abs(h[i]-(f-1))*c[i]);
            above+=(abs(h[i]-(f+1))*c[i]);
        }
        return ans={below,mid,above};
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n=heights.size();
        int low=*min_element(heights.begin(),heights.end());
        int high=*max_element(heights.begin(),heights.end());
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            vector<int> making=costing(mid,heights,cost);
            if(making[1]<=making[0] && making[1]<=making[2]) return making[1];
            if(making[1]<=making[2] && making[0]<making[1]) high=mid-1;
            else low=mid+1;
        }
    }
};
