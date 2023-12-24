#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node() {
         this->data = 0;
         this->prev= NULL;
         this->next = NULL;
        }
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        cout<<"deleting the Node "<<this->data<<endl;
        // Node* head;
        // while()
    }
};
void insertAtHead(Node* &head, Node* &tail, int data){
    if(head ==NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //create a node
    Node* newNode = new Node(data);
    //connect new node next to head 
    newNode->next = head;
    //head prev to newNode
    head->prev =newNode;
    //head will point to new node
    head = newNode;
    

}
int findLength(Node* &head){
    int len =0;
    Node* temp =head;
    while(temp!= NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
void insertAtTail(Node* &head, Node* &tail, int data){
    if(head ==NULL){
        Node* newNode =new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node *newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;

}
void printLL(Node* &head){
    Node* temp =head;
    while (temp!= NULL){
        cout<<temp->data<<" ";
        temp =temp->next;
    }
    return;
}
void insertAtMiddle(Node* &head, Node* &tail, int position ,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head =newNode;
        tail =newNode;
        return;
    }
    
    int i =1;
    Node* prevNode = head;
    while(i<position){
        prevNode = prevNode->next;
        i++;
    }
    Node *currNode = prevNode->next;
    Node* newNode =new Node(data);

    newNode->next =currNode;
    newNode->prev =prevNode;
    prevNode->next =newNode;
    currNode->prev =newNode;
}
void deleteFromHead(Node* &head, Node* &tail){
    if(head == NULL){
        cout<<"linked list is empty"<<endl;
    }
    Node* temp = head;
    head =head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
    return;
}
void deleteFromLast(Node* &head, Node* &tail,int position){
    if(head == NULL){
        cout<<"linkedlist is empty"<<endl;
    }
    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }
    int len=findLength(head);
    if(position==len){
    //     int i=1;
    //     Node *prevNode = head;
    //     while(i<position -1){
    //         prevNode =prevNode->next;
    //         i++;
    //     }
    //    Node* currNode = prevNode->next;
    Node* temp = tail;
    tail =tail->prev;
    temp->next =NULL;
    temp->prev =NULL;
    delete temp;
    return;

    }
}

void deleteFromMiddle(Node* &head,Node* &tail,int position){
    if(head == NULL){
        cout<<"linkedlist is empty"<<endl;
        return;
    }
      int i = 1;
        Node* left = head;
        while( i < position - 1) {
                left = left -> next;
                i++;
        }
        Node* curr = left -> next;
        Node* right = curr -> next;

        //step2:
        left -> next = right;
        //step3:
        right -> prev = left;
        //step4:
        curr -> next = NULL;
        curr ->prev = NULL;
        delete curr;
        return;
}
void deleteFromPos(Node* &head, Node* &tail, int position) {
        if(head == NULL) {
                cout << "Linked list is empty";
                return;
        }
        if(head -> next == NULL) {
                //single node
                Node* temp = head;
                head = NULL;
                tail = NULL;
                delete temp;
                return;
        }
        int len = findLength(head);
        if(position > len) {
                cout << "please enter a valid position " << endl;
                return;
        }

        if(position == 1) {
                //want to delete the first node
                Node* temp = head;
                head = head ->next;
                head -> prev = NULL;
                temp ->next = NULL;
                delete temp;
                return;
        }
        
        if(position == len) {
                //delete last node
                Node* temp = tail;
                tail = tail -> prev;
                temp ->prev = NULL;
                tail ->next = NULL;
                delete temp;
                return;
        }

        //delete from middle of linked list

        //step1: find left, curr, right
        int i = 1;
        Node* left = head;
        while( i < position - 1) {
                left = left -> next;
                i++;
        }
        Node* curr = left -> next;
        Node* right = curr -> next;

        //step2:
        left -> next = right;
        //step3:
        right -> prev = left;
        //step4:
        curr -> next = NULL;
        curr ->prev = NULL;
        delete curr;


}
int main(){
    Node *head =NULL;
    Node *tail = NULL;
    insertAtHead(head,tail,12);
    insertAtHead(head,tail,13);
    insertAtHead(head,tail,14);
    printLL(head);
    cout<<endl;
    insertAtTail(head,tail,40);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,50);
    printLL(head);
    cout<<endl;
    insertAtMiddle(head,tail,5,60);
    printLL(head);
    cout<<endl;
    // //deleteFromHead(head,tail);
    // printLL(head);
    // cout<<endl;
    // //deleteFromLast(head,tail,6);
    // printLL(head);
    // //deleteFromMiddle(head,tail,4);
    // printLL(head);
    deleteFromPos(head,tail,6);
    printLL(head);
    return 0;

}