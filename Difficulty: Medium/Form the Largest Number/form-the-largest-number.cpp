class Solution {
  public:
    bool static comp(int &a,int &b)
    {
        
        string first=to_string(a);
	    string second=to_string(b);
	    if((first+second) > (second+first)) //order is right don't do anything
	       return true;
	    else  return false;            //order is wrong do swap
    }
    string findLargest(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> nums(10);
    
        for (int i = 0; i < n; ++i) {
            int val = arr[i]; // promote to long long
            if (val < 0) val = -val; // safe negate
            int firstDigit = val;
            while (firstDigit >= 10) firstDigit /= 10;
            nums[firstDigit].push_back(arr[i]);
        }
    
        for(int i=0;i<10;++i)
        {
            sort(nums[i].begin(),nums[i].end(),comp);
        }
        
        string ans="";
        for(int i=9;i>=0;--i)
        {
            for(int j=0;j<nums[i].size();++j)
            {
                ans+=to_string(nums[i][j]);
            }
        }
        if(ans[0]=='0') ans="0";
        
        return ans;
    }
};