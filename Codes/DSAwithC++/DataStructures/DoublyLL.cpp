#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* prev;
		Node*next;

		Node(){
			this->prev=NULL;
			this->prev=NULL;
		}

		Node(int data){
			this->data = data;
			this->prev = NULL;
			this->next = NULL;
		}
};

void printLL(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int findLength(Node* head){
	Node* temp = head;
	int len = 0;

	while(temp!=NULL){
		len++;
		temp = temp->next;
	}

	return len;
}

void insertAtHead(Node* &head,Node* &tail,int data){
	Node* newNode = new Node(data);
	if(head==NULL){
		head = newNode;
		tail = newNode;
	}
	else{
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
	}
}

void insertAtTail(Node* &head,Node* &tail,int data){
	Node* newNode = new Node(data);
	if(head==NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

void insertAtPos(Node* &head,Node* &tail,int data,int pos){
	Node* newNode = new Node(data);
	int len = findLength(head);
	if(head==NULL){
		head = newNode;
		tail = newNode;
		return;
	}
	if(pos<=1){
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else if(pos<len){
		Node* previous = NULL;
		Node* curr = head;
		while(pos!=1){
			previous=curr;
			curr=curr->next;
			pos--;
		}
		previous->next=newNode;
		newNode->prev=previous;
		newNode->next=curr;
		curr->prev=newNode;
	}
	else{
		Node* previous = NULL;
		Node* curr = head;
		while(previous->next!=tail){
			previous=curr;
			curr=curr->next;
			pos--;
		}
		curr->next = newNode;
		newNode->prev=curr;
		tail=newNode;
	}
}

void deleteNode(Node* &head,Node* &tail,int pos){
	if(head==NULL){
		return;
	}
	if(head==tail){
		Node* temp = head;
		delete(temp);
		head=NULL;
		tail=NULL;
	}
	if (pos<=1){
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
		head->prev=NULL;
		delete(temp);
	}
	else if(pos<len){
		Node *curr = head;
		Node *previous = NULL;
		while(pos!=1){
			previous = curr;
			curr = curr->next;
			pos--;
		}
		Node *nextTocurr = curr->next;
		previous->next=curr->next;
		nextToCurr->prev = previous;
		curr->next=NULL;
		curr->prev=NULL;
		delete(curr);
	}
	else{
		Node* previous = tail->previous;
		previous->next = NULL;
		tail->prev = NULL;
		delete(tail);
		tail = previous;
	}
}

int main(){
	
	Node* head = new Node(10);

	return 0;
}