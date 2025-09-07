/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
// Custom class for min heap
class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, Compare> pq;
    
        // Insert the head nodes of k lists 
        for (Node* head: arr) {
            if (head != nullptr) pq.push(head);
        }
        
        // Initialize a dummy head 
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        
        while (!pq.empty()) {
            
            // Pop the min node 
            Node* top = pq.top();
            pq.pop();
            
            // Append the node into list 
            tail->next = top;
            tail = top;
            
            // If top node has next node,
            // add it to the heap.
            if (top->next!=nullptr) {
                pq.push(top->next);
            }
        }
        
        return dummy->next;
    }
};