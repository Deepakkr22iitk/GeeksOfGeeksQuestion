class Solution {
  public:
    int romanToDecimal(string &s) {
        unordered_map<char,int> mpp = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
        
        int sum=0;
        int n=s.size()-1;
        for(int i=0;i<n;i++)
        {
            if(mpp[s[i]] < mpp[s[i+1]])
            {
                sum-=mpp[s[i]];
            }
            else{
                sum+=mpp[s[i]];
            }
        }
        sum+=mpp[s[n]];
        return sum;
    }
};