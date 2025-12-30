/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
    Node * reverse(Node *head){
        Node * prev = NULL;
        Node * curr = head;
        while(curr && curr->data == 0){
            curr = curr->next;
        }
        while(curr){
            Node * n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }
    
    Node * reverseRes(Node *head){
        Node * prev = NULL;
        Node * curr = head;
        
        while(curr){
            Node * n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }
  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        if(!head1) return head2;
        if(!head2) return head1;
        if(!head1 && !head2) return NULL;
        
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        int carry = 0;
        Node * res = new Node(0);
        Node * temp = res;
        
        while(head1 || head2){
            int n1 = head1==NULL ? 0 : head1->data;
            int n2 = head2==NULL ? 0 : head2->data;
            int sum = n1 + n2 + carry;
            
            int currSum = sum;
            sum = currSum%10;
            carry = currSum/10;
            
            Node * newNode = new Node(sum);
            temp->next = newNode;
            
            temp = temp->next;
            if(head1)
                head1 = head1->next;
            if(head2)
                head2 = head2->next;
        }
        
        if(carry > 0){
            Node * newNode = new Node(carry);
            temp->next = newNode;
        }
        
        return !res->next ? res : reverseRes(res->next);
    }
};