class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        int n=arr.size();
        map<long,long> freq;
        
        vector<int> rem;
        for(int i=0;i<n;++i)
        {
            rem.push_back(arr[i]%k);
        }
        freq[rem[0]]++;
        int ans=0;
        for(int i=1;i<n;++i)
        {
            int req=(k-rem[i])%k;
            if(freq.find(req)!=freq.end()) ans+=freq[req];
            freq[rem[i]]++;
        }
        return ans;
    }
};