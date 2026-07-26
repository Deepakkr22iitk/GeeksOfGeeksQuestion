class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        int N=arr.size();
        vector<vector<int>> ans;
        queue<int> q;
        q.push(0);
          
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            while(n--){
                int ind = q.front();
                q.pop();
                  
                temp.push_back(arr[ind]);
                  
                if((2*ind+1) < N)
                    q.push((2*ind+1));
                if((2*ind+2) < N)
                    q.push((2*ind+2));
            }
              
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};
