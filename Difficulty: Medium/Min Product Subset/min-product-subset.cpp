class Solution {
  public:
    int minProd(vector<int>& arr) {
        int n=arr.size();
        int neg=0,zero=0;
        int minPos=INT_MAX;
        int maxNeg=INT_MIN;
        long prod=1;
        for(auto x:arr)
        {
            if(x==0) 
            {
                zero++;
                continue;
            }
            if(x<0)
            {
                neg++;
                maxNeg=max(maxNeg,x);
            }
            if(x>0)
            {
                minPos=min(minPos,x);
            }
            prod*=x;
        }
        if(zero==n) return 0;
        if(neg==0)
        {
            if(zero>0) return 0;
            return minPos;
        }
        
        // if(neg%2==1) prod/=maxNeg;
        // return (int)prod;
        
        
        if(neg%2==1) return (int)prod;
        prod/=maxNeg;
        return (int)prod;
    }
};