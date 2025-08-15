class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        vector<vector<int>> ans;
        int n=intervals.size();
        int ind=0;
        while(ind< n && intervals[ind][1] < newInterval[0])
        {
            ans.push_back(intervals[ind]);
            ind++;
        }
        if(ind==n) ans.push_back(newInterval);
        else
        {
            int start = min(intervals[ind][0],newInterval[0]),end=0;
            while(ind<n && intervals[ind][1]<newInterval[1])
            {
                ind++;
            }
            if(ind==n)
            {
                end=newInterval[1];
            }
            else
            {
                if(intervals[ind][0]>newInterval[1])
                {
                    // end=max(intervals[ind][1],newInterval[1])
                    ind--;
                }
                end=max(intervals[ind][1],newInterval[1]);
            }
            ans.push_back({start,end});
            ind++;
        }
        while(ind<n)
        {
            ans.push_back(intervals[ind]);
            ind++;
        }
        return ans;
    }
};