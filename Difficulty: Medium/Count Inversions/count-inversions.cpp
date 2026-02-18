class Solution {
  public:
    // Function to count inversions in the array.
    int merge(vector<int> &arr, int low, int mid, int high){
        
        int n1 = mid-low+1;
        int n2 = high-mid;
        
        int res = 0;
        
        int arr1[n1] = {0};
        int arr2[n2] = {0};
        
        for(int i=0;i<n1;i++){
            arr1[i] = arr[low + i];
        }
        for(int i=0;i<n2;i++){
            arr2[i] = arr[mid + 1 + i];
        }
        
        int i=0,j=0,idx = low;
        
        while(i < n1 && j < n2){
            
            if(arr1[i] <= arr2[j]){
                arr[idx++] = arr1[i++];
            }else{
                res += n1-i;
                arr[idx++] = arr2[j++];
            }
        }
        
        while(i < n1){
            arr[idx++] = arr1[i++];
        }
        
        while(j < n2){
            arr[idx++] = arr2[j++];
        }
        return res;
    }
    
    int mergeSort(vector<int> &arr,int low, int high){
        
        int res = 0;
        
        if(high > low){
            
            int mid = (low + high) >> 1;
            
            res += mergeSort(arr,low,mid);
            res += mergeSort(arr,mid+1,high);
            res += merge(arr,low,mid,high);
        }
        return res;
    }
    
    
    int inversionCount(vector<int> &arr) {
        
        int n = arr.size();
        int res = mergeSort(arr,0,n-1);
        
        return res;
    }
};