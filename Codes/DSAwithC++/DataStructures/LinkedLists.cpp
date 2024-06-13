#include <bits/stdc++.h>
#include <algorithm>
//#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(){
            // cout<<"Default Constructor Called"<<endl;
            this->data=0;
            this->next=NULL;
        }

        Node(int data){
            // cout<<"Parameterized Constructor Called"<<endl;
            this->data=data;
            this->next=NULL;
        }

        ~Node(){
            // cout<<"Destructor called for"<<this->data<<endl;
        }
};

void printLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int findLength(Node* head){
    int len=0;
    Node* temp = head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;

    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

}

void insertAtTail(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(Node* &head,Node* &tail,int data,int position){
    int len = findLength(head);
    if(position==1){
        insertAtHead(head,tail,data);
        return;
    }
    else if(position > len) {
                insertAtTail(head, tail, data);
                return;
        }
    else {
        Node* newNode = new Node(data);
        
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1) {
            position--;
            prev = curr;
            curr = curr->next;
        }
        
        //step3:
        newNode -> next = curr;

        //step4:
        prev -> next = newNode;
    }
}

void deleteNode(Node* &head, Node* &tail, int position) {
  //empty list
  if(head == NULL) {
    cout << "Cannot delete, coz LL is empty" << endl;
    return;
  }

  if(head == tail) {
    //single element
    Node* temp = head;
    delete temp;
    head = NULL;
    tail = NULL;
    return;
  }

  int len = findLength(head);

  //delete from head
  if(position == 1) {
    //first node ko delete kardo
    Node* temp = head;
    head = head->next;
    //head = temp->next;
    temp->next = NULL;
    delete temp;
  }
  else if(position == len) {
    //last node ko delete krdo\

    //find prev
    Node* prev = head;
    while(prev -> next != tail ){
      prev = prev -> next;
    }

    //prev node ka link null karo
    prev -> next = NULL;

    //node delete kro
    delete tail;

    //update tail
    tail = prev;

  }
  else {
    //middle me koi node ko delete krna h 

    //step1: set prev/curr pointers
    Node* prev = NULL;
    Node* curr = head;
    while(position != 1) {
      position--;
      prev = curr;
      curr = curr->next;
    }

    //step2: prev -> next me curr ka next node add kro
    prev->next = curr->next;

    //step3: node isolate krdo
    curr->next = NULL;
    //step4: delte node
    delete curr;

  }

}

void reverseLL(Node* &head, Node* &tail) {
    tail = head;
    Node* currNode = head;
    Node* prevNode = NULL;
    Node* nextNode = NULL;

    while (currNode != NULL) {
        nextNode = currNode->next;  // Save the next node
        currNode->next = prevNode;  // Reverse the link
        prevNode = currNode;        // Move prevNode to currNode
        currNode = nextNode;        // Move currNode to nextNode
    }

    head = prevNode;  // Update head to the new front of the list
}

// Node* reverseLLRec(Node* &head,Node* &tail){
//     Node* curr = head;
//     Node* prev = NULL;
//     Node* newNode = curr->next;
//     if (curr==NULL){
//         return prev;
//     }
//     // cout<<curr->data<<endl;
//     curr->next = prev;
//     prev = curr;
//     curr = newNode;
//     head = reverseLLRec(curr,tail);
// }


Node* middleLL(Node* &head,Node* &tail){
    int len = findLength(head)/2 + 1;
    Node* ans = head;
    while(len!=1){
        ans = ans->next;
        len--;
    }
    return ans;
}

//Tortoise Algo or slow and fast algo
// slow wala ek hi step age badhega agar 
// fast wala two steps ja sakta ho
// dry run karke dekhlo
Node* tortoiseLL(Node* &head,Node* &tail){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}


void palindromeLL(Node* head,Node* tail){

}

void checkCycleinLL(Node* head){
    map <Node*, bool> table;

    Node* temp = head;
    while(temp != NULL){
        if(table[temp] == false){
            table[temp] = true;
        }
        else{
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

void hasCycleTortoise(){
    //Slow and Fast always meet in cyclic lists
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,80);
    insertAtHead(head,tail,70);
    insertAtHead(head,tail,60);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,40);

    printLL(head);
    Node* ans = tortoiseLL(head,tail);
    cout<<ans->data<<endl;
    printLL(head);

    return 0;
}