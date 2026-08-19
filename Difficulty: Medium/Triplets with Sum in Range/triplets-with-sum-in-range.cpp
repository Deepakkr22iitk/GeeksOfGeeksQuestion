class Solution {
  public:
    int countTripletsLessThan(vector<int> v,int tar)
    {
        int n=v.size();
      
        int ans=0;
        int j,k,sum;
      
        for(int i=0;i<n-1;++i)
        {
            j=i+1;
            k=n-1;
          
            while(j<k)
            {
                sum=v[i]+v[j]+v[k];
                if(sum>tar) k--;
              
                else
                {
                    ans += (k - j);
                    j++;
                }
            }
        }
        return ans;
    }
  int countTriplets(vector<int> &arr, int l, int r) {
        sort(arr.begin(),arr.end());
        
        int res=0;
        
        res+=countTripletsLessThan(arr,r);
        res-=countTripletsLessThan(arr,l-1);
        
        return res;
    }
};