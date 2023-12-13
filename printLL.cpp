// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
    Node(int data){
        this->data= data;
        this->next = next;
    }
};
void insertAtHead(Node* &head,Node* &tail,int data){
    if(head == NULL){
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
    }
    Node* newNode =new Node(data);
    newNode->next = head;
    head =newNode;
    
}
void printLL(Node* &head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp =temp->next;
    }
}
void insertAtTail(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newNode =new Node(data);
        head =newNode;
        tail =newNode;
        return;
    }
     Node* newNode =new Node(data);
     tail->next =newNode;
     newNode->next =NULL;
}

int main() {
    Node* head =NULL;
    Node* tail =NULL;
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,60);
    insertAtHead(head,tail,80);
    insertAtTail(head,tail,103);
    printLL(head);
        return 0;
}