class Solution {
  public:
    int cal_cost(int h,vector<int>&heights,vector<int>&cost){
        int sum=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            sum+=cost[i]*abs(heights[i]-h);
        }
        return sum;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int n=heights.size();
        int l=*min_element(heights.begin(),heights.end());
        int r=*max_element(heights.begin(),heights.end());
        int ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            // we cant do partition based on height
            // we have to do partition based on total cost of that height
            int h1=mid;
            int h2=mid+1;
            int c1=cal_cost(h1,heights,cost);
            int c2=cal_cost(h2,heights,cost);
            if(c1>=c2){
                // so on increasing height cost decreases so we try higher h
                ans=c2;
                l=mid+1;
            }
            else{
                ans=c1;
                r=mid-1;
            }
        }
        return ans;
    }
};
