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
    ~Node() {
        cout<<"deleting the Node "<<this->data<<endl;
         if (next != nullptr) {
       delete next;
       next = nullptr;
   }
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
int findLength(Node* &head) {
  int len=0;
  Node* temp = head;
  while(temp!=NULL){
    temp=temp->next;
    len++;
  }
  return len;
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
void deleteNodeFromMiddle(Node* &head, Node* &tail,int position) {
  if(head == NULL) {
    cout<<"List is empty"<<endl;
  }
  //int length =findLength(head);
  int i=1;
  Node *prev = head;
  while(i<position-1){
    prev =prev->next;
    i++;
  }
  Node *curr =prev->next;
  prev->next =curr->next;
  curr->next =NULL;
  delete curr;
  return;
}

void deleteNodeFromHead(Node* &head, Node* &tail) {
  if(head == NULL) {
    cout<<"List is empty"<<endl;
    return;
  }
  Node* temp = head;
  head =head->next;
  temp->next =NULL;
  delete temp;
  }
  void deleteNodeFromTail(Node* &head, Node* &tail,int position) {
  if(head == NULL) {
    cout<<"List is empty"<<endl;
    return;
  }
  int len =findLength(head);
  //delete last node
  if(position ==len){
    int i=1;
    Node* prev = head;
    while(i<position-1)
      {
        prev = prev->next;
        i++;
      }
    prev->next =NULL;
    Node *temp =tail;
    tail =prev;
    delete temp;
    return;
    
  }
  
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
    cout<<"length"<<endl;
    int length =findLength(head);
    cout<<length<<endl;
    //deleteNodeFromHead(head,tail);
    printLL(head);
    cout<<endl;
    //delete head;
    //deleteNodeFromTail(head,tail,3);
    printLL(head);
    cout<<"delete from middle"<<endl;
    deleteNodeFromMiddle(head,tail,3);
    printLL(head);
    return 0;
}