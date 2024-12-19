//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        printf("%d ", num);
    printf("\n");
}


// } Driver Code Ends
class Solution {
  public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high)
    {
        //base case
        if(low>=high)
        {
            return;
        }
        // partition 
        int p = partition(arr,low , high);
        // sort left part
        quickSort( arr,low,p-1);
        // sort rght part
        quickSort( arr,p+1,high);
    }
    
    public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) 
    {
        int pivot = arr[low];
        int count =0;
        for(int i =low+1; i<=high; i++)
        {
            if(arr[i] <=pivot)
            {
                count++;
            }
        }
        //   right place for pivot = low+count
        int pivotIdx = low +count;
        //  swapping element at right place 
        swap(arr[pivotIdx],arr[low]);
        // now managing right and left part
        int i =low,j=high;
        while(i<pivotIdx && j>pivotIdx)
        {
            while(arr[i]<=pivot)i++;
            while(arr[j]>pivot)j--;
            if(i<pivotIdx && j>pivotIdx)
            {
                swap(arr[i++],arr[j--]);
            }
        }
        return pivotIdx;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    scanf("%d", &T);
    getchar(); // to consume newline after T

    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.quickSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }

    return 0;
}

// } Driver Code Ends