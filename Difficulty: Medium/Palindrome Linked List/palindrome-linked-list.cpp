/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    Node* findMid(Node* head){
        Node* slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }
        return slow;
    }
    
    Node* reverseList(Node* head) {
    if (head == NULL) return NULL;
    Node* prev = NULL;Node* curr = head;Node* nexti = head->next;
    while (curr != NULL) {
        curr->next = prev;
        prev = curr;
        curr = nexti;
        if(nexti!=NULL)nexti=nexti->next;
    }
    
    return prev;
   }
  
    bool compareList(Node* head1, Node* head2){
        while(head1!=NULL && head2!=NULL){
            if(head1->data != head2->data) return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }

    bool isPalindrome(Node *head) {
        if(head==NULL || head->next==NULL) return true;
        Node* h=head;
        Node* mid = findMid(h);
        Node* h2=reverseList(mid);
        return compareList(head,h2);
    }
};