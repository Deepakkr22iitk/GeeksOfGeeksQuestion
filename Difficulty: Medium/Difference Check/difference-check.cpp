class Solution {
  public:
    // int check(vector<string> arr)
    // {
    //     int h1,m1,s1,h2,m2,s2;
    //     h1=arr[0][0]*10+arr[0][1];
    //     m1=arr[0][3]*10+arr[0][4];
    //     s1=arr[0][6]*10+arr[0][7];
        
    //     h2=arr[1][0]*10+arr[1][1];
    //     m2=arr[1][3]*10+arr[1][4];
    //     s2=arr[1][6]*10+arr[1][7];
        
    //     int time1=h1*3600+m1*60+s1;
    //     int time2=h2*3600+m2*60+s2;
        
    //     if(time1<time2) swap(time1,time2);
    //     int ans=(time1-time2);
    //     return min(ans,3600*24-ans);
    // }
    int minDifference(vector<string> &arr) {
        int n=arr.size();
        
        int ans=INT_MAX;
        vector<int> times;
        for(int i=0;i<n;++i)
        {
            int h=arr[i][0]*10+arr[i][1];
            int m=arr[i][3]*10+arr[i][4];
            int s=arr[i][6]*10+arr[i][7];
            int time=h*3600+m*60+s;
            times.push_back(time);
        }
        
        sort(times.begin(),times.end());
        for(int i=0;i<n-1;++i)
        {
            ans=min(ans,times[i+1]-times[i]);
        }
        ans=min(ans,min((times[n-1]-times[0]),3600*24-(times[n-1]-times[0])));
        
        // int h1,m1,s1,h2,m2,s2;
        // h1=arr[0][0]*10+arr[0][1];
        // m1=arr[0][3]*10+arr[0][4];
        // s1=arr[0][6]*10+arr[0][7];
        
        // h2=arr[1][0]*10+arr[1][1];
        // m2=arr[1][3]*10+arr[1][4];
        // s2=arr[1][6]*10+arr[1][7];
        
        // int time1=h1*3600+m1*60+s1;
        // int time2=h2*3600+m2*60+s2;
        
        // if(time1<time2) swap(time1,time2);
        // int ans=(time1-time2);
        return ans;
    }
};
