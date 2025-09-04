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
class Solution {
  public:
    Node* rev(Node* head){
        Node* prev=NULL;
        while(head){
            Node* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    Node *reverseKGroup(Node *head, int k) {
        Node* curr=head;
        Node* prev=head;
        Node* temp=new Node(-1);
        Node* d=temp;
        while(curr){
            int ori=k;
            while(ori-->1 && curr->next!=NULL){
                curr=curr->next;
            }
            Node* next=curr->next;
            curr->next=NULL;
            d->next=rev(prev);
            while(d->next){
                d=d->next;
            }
            prev=next;
            curr=next;
        }
        return temp->next;
    }
};