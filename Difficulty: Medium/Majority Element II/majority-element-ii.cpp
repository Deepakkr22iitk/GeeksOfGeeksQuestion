//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // int n=arr.size();
        // map<int,int> freq;
        
        // set<int> done;
        // vector<int> ans;
        // for(int i=0;i<n;i++)
        // {
        //     // if(freq[arr[i]]==n/3)
        //     // {
        //     //     ans.push_back(arr[i]);
        //     //     done.insert(arr[i]);
        //     // }
        //     freq[arr[i]]++;
        // }
        
        // for(auto &it : freq)
        // {
        //     if(it.second>n/3) ans.push_back(it.first);
        // }
        
        // if(ans.size()==0) ans.push_back(-1);
        // sort(ans.begin(),ans.end());
        // // else if(ans.size()==2)
        // // {
        // //     int first=-1;
        // //     int flag=0;
        // //     int idx=0;
        // //     while(flag==0)
        // //     {
        // //         if(arr[idx]==ans[0])
        // //         {
        // //             first=1;
        // //             flag=1;
        // //             // break;
        // //         }
        // //         else if(arr[idx]==ans[1])
        // //         {
        // //             first=2;
        // //             flag=1;
        // //             // break;
        // //         }
        // //         idx++;
        // //     }
            
        // //     if(flag==2)
        // //     {
        // //         int temp=ans[0];
        // //         ans[0]=ans[1];
        // //         ans[1]=ans[0];
        // //     }
        // // }
        
        // return ans;
        
        int count1 = 0,count2 = 0;
        int major1 = arr[0],major2 = arr[0];
        int n = arr.size();
        
        for(int i=0;i<arr.size();i++){
            if(major1 == arr[i]){
                count1++;
            }
            else if(major2 == arr[i]){
                count2++;
            }
            else if(count1 == 0){
                major1 = arr[i];
                count1 = 1;
            }
            else if(count2 == 0){
                major2 = arr[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        vector<int> ans;
        int freq1 = 0,freq2 = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] == major1){
                freq1++;
            }
            else if(arr[i] == major2){
                freq2++;
            }
        }
        
        if(freq1 > n/3){
            ans.push_back(major1);
        }
        if(freq2 > n/3){
            ans.push_back(major2);
        }
        
        // if(ans.size() == 0){
        //     return {-1};
        // }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends