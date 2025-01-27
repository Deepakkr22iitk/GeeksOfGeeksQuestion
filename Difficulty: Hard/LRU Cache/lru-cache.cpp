//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way
struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int x, int y){
        key = x;
        val = y;
    }
};

class LRUCache {
  private:
        int capacity;
        Node* head;
        Node* tail;
        unordered_map<int, Node*> mp;
        int count;
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity = cap;
        count = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(Node* node){
        Node* previousNode = node->prev;
        Node* nextNode = node->next;
        previousNode->next = nextNode;
        nextNode->prev = previousNode;
        count--;
        return;
    }
    
    void addNode(Node* node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        count++;
        return;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if(mp.empty()){
            return -1;
        }
        if(mp.count(key)){
            Node* resNode = mp[key];
            int res = resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if(mp.empty() == false && mp.find(key) != mp.end()){
            Node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        if(count == capacity){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key] = head->next;
        return;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends