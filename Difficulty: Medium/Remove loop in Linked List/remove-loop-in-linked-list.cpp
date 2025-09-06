/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        
        set<Node*> st;

        while(curr != NULL)
        {
            if(st.find(curr) != st.end())
            {
                prev->next = NULL;
                return ;
            }
            
            st.insert(curr);
            
            prev = curr;
            curr = curr->next;
        }
        return ;
    }
};