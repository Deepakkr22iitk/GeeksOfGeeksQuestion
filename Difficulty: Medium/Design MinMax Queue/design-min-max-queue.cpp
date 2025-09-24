class SpecialQueue {

  public:

    deque<int> dq;
    int maxi=-1;
    int mini=INT_MAX;
    void enqueue(int x) {
        // Insert element into the queue
        dq.push_back(x);
        maxi=max(maxi,x);
        mini=min(mini,x);
    }

    void dequeue() {
        // Remove element from the queue
        dq.pop_front();
        maxi=-1;
        mini=INT_MAX;
        for(auto it = dq.begin();it!=dq.end();it++)
        {
            maxi=max(maxi,*it);
            mini=min(mini,*it);
        }
        
    }

    int getFront() {
        // Get front element
        return dq.front();
    }

    int getMin() {
        // Get minimum element
        return mini;
    }

    int getMax() {
        // Get maximum element
        return maxi;
    }
};