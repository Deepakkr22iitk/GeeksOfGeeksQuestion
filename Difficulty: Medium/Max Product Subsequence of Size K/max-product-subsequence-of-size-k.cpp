class Solution {
  public:
    int solve(auto &v,int s,int e)
    {
        int ans=1;
        for(int i=s;i<=e;++i)
        {
            ans*=v[i];
        }
        return ans;
    }
    int maxProduct(vector<int> &arr, int k) {
        int n=arr.size();
        int mnPos=INT_MAX;
        int mxNeg=INT_MIN;
        int negCnt=0,zeroCnt=0;
        vector<int> pos,neg;
        for(auto it:arr)
        {
            if(it==0) zeroCnt++;
            else if(it<0)
            {
                negCnt++;
                mxNeg=min(mxNeg,it);
                neg.push_back(it);
            }
            else
            {
                mnPos=min(mnPos,it);
                pos.push_back(it);
            }
        }
        
        sort(arr.begin(),arr.end());
        sort(neg.begin(),neg.end());
        sort(pos.begin(),pos.end());
        int posCnt=(n-zeroCnt-negCnt);
        // if(k<=posCnt)
        // {
        //     return solve(arr,n-k,n-1);
        // }
        // int req=(k-posCnt);
        // if(req%2==1)
        // {
        //     if(zeroCnt>0) return 0;
        //     return solve(arr,n-k,n-1);
        // }
        // return solve(arr,n-posCnt,n-1)*solve(arr,0,req-1);
        
        int nonZero=(n-zeroCnt);
        if(k>nonZero) return 0;
        if(pos.size()==0)
        {
            if(k%2==1) return solve(neg,neg.size()-k,neg.size()-1);
            return solve(neg,0,k-1);
        }
        if(k==nonZero) 
        {
            if(neg.size()==1 && zeroCnt>0) return 0;
            return solve(neg,0,neg.size()-1)*solve(pos,0,pos.size()-1);
        }
        int taken=2;
        int ans=0;
        if(pos.size()>0)ans=max(ans,solve(pos,pos.size()-k,pos.size()-1));
        while(taken<=neg.size() && taken<=k)
        {
            ans=max(ans,solve(neg,0,taken-1)*solve(pos,pos.size()-(k-taken),pos.size()-1));
            taken+=2;
        }
        return ans;
    }
};