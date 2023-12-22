#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next =nullptr;
    }
};

class LinkedList{
    Node* head;
    Node *tail;

    public:
    LinkedList(){
       this->head = NULL;
       this->tail = NULL;
    }

    void insertAtHead(int data){
        if(head == NULL){
            Node *newNode =new Node(data);
            head = newNode;
            tail = newNode;
            return;
        }
        Node *newNode =new Node(data);
        newNode->next = head;
        head =newNode;
    }
    void insertAtTail(int data){
        if(head == NULL){
            Node *newNode= new Node(data);
            head == newNode;
            tail== newNode;
            return;
        }
        Node *newNode =new Node(data);
        tail->next =newNode;
        tail = newNode;
    }

    void removeAtFirst(int data){
        if(head == NULL)
           return;
        Node *temp = head;
        head =head->next;
        delete temp;

    }
    void printLL(){
        Node *temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp =temp->next;
        }
    }
};
int main(){
   
    LinkedList LL;
    LL.insertAtHead(20);
    LL.insertAtTail(40);
    LL.insertAtHead(50);
    LL.printLL();

 return 0;

}
