class kQueues {
    int ctr, N;
    vector<queue<int>> arr;

  public:
    kQueues(int n, int k) {
        // Initialize your data members
        ctr=0;
        N=n;
        arr.resize(k);
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        arr[i].push(x);
        ctr++;
    }

    int dequeue(int i) {
        // dequeue element from queue i
        if (arr[i].empty()) return -1;
        int res = arr[i].front();
        arr[i].pop();
        ctr--;
        return res;
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        return arr[i].empty();
    }

    bool isFull() {
        // check if array is full
        return ctr==N;
    }
};
