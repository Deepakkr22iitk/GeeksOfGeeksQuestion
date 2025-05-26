/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node *newNode = new Node(data);
        
        // for that headache case, even I too handled this after a look into comment section
        if(!head){
            newNode->next = newNode;
            return newNode;
        }
       
       unordered_set<Node*> st; // since it is circle to avoid infinite loop
       Node *prev = nullptr, *ans = head;
       bool found = false;
       
       if(data < head->data){  // case when we found pos at first itself
           found = true;
           newNode->next = head;
       }
          
       while(head)
       {
           if(data < head->data && !found){ // place to insert at middle
               newNode->next = head;
               prev->next = newNode;
               return ans;
           }
           if(st.find(head) != st.end()) break; // time to avoid inf loop
           st.insert(head);
           prev = head;
           head = head->next;
       }
       
       if(!found){   // pos of inserting at last
           prev->next = newNode;
           newNode->next = ans;
           return ans;
       }
       else{   // inserted at first, but link the last and first one to make it circle list again
           prev->next = newNode;
           return newNode;
       }
    }
};