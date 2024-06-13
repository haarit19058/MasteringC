#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &st,int& pos,int ans){
	if (pos == 1){
		ans = st.top();
	return;
	}

	pos--;
	int temp = st.top();
	st.pop();
	solve(st,pos,ans);
	st.push(temp);
}

void insertAtBottom(stack<int> &st,int val){
	if(st.empty()){
		st.push(val);
		return;
	}

	int temp = st.top();

	st.pop();

	insertAtBottom(st,val);

	st.push(temp);

}

int getMid(stack<int> &st){
	int size = st.size();
	if(st.empty()){
		return -1;
	}
	else{
		int pos = 0;
		if(size & 1){
			pos = size/2+1;
		}
		else{
			pos = size/2;
		}
		int ans = -1;
		solve(st,pos,ans);
		return ans;
	}
}

void reverse(stack<int> &st){
	if(st.empty()){
		return;
	}

	int temp = st.top();
	st.pop();
	reverse(st);
	insertAtBottom(st,temp);

}

int main(){

// 	//creation
// 	stack<int> st;

// 	//insertion
// 	st.push(10);
// 	st.push(20);
// 	st.push(30);

// 	//size check
// 	cout<<"Size of stack is "<<st.size()<<endl;

// 	//remove
// 	st.pop();

// 	//check empty

// 	if(st.empty()){
// 		cout<<"Stack is Empty"<<endl;
// 	}
// 	else{
// 		cout<< "Stack is Not Empty"<<endl;
// 	}

// 	//Check element at the top
// 	cout<<st.top()<<endl;




stack<int> st;
st.push(10);
st.push(20);
st.push(30);
st.push(40);
st.push(50);
st.push(60);
st.push(70);

// while(!st.empty()){
// 	cout<<st.top()<<" ";
// 	st.pop();
// }


reverse(st);

while(!st.empty()){
	cout<<st.top()<<" ";
	st.pop();
}

cout<<endl;
	return 0;
}







// implementing stack 

// #include <iostream>
// using namespace std;



// class Stack{
// 	public:
// 		int* arr;
// 		int size;
// 		int top;

// 		Stack(int size){
// 			arr = new int[size];
// 			this->size = size;
// 			this->top = -1;
// 		}

// 		void push(int data){
// 			if(top == size-1){
// 				cout<<"Stack Overflow"<<endl;
// 			}
// 			else{
// 			top++;
// 			arr[top] = data;
// 			}
// 		}	

// 		void pop(){
// 			if (top == -1){
// 				cout<< "Stack Underflow" << endl;
// 			}
// 			else{
// 				top--;
// 			}
// 		}

// 		bool isEmpty(){
// 			if(top == -1){
// 				return true;
// 			}
// 			else{
// 				return false;
// 			}
// 		}

// 		int getSize(){
// 			return top+1;
// 		}

// 		int getTop(){
// 			if(top == -1){
// 				cout<<"stack is empty"<<endl;
// 				return 0;
// 			}
// 			else{
// 				return arr[top];
// 			}
// 		}


// 		void print(){
// 			cout<<"Top Element"<<getTop()<<endl;
// 			cout<<"Stack: ";
// 			for(int i = 0;i<getSize();i++){
// 				cout<<arr[i]<<" ";
// 			}
// 			cout<<endl;
// 		}
// };

// int main(){
	

// 	Stack st(10);

// 	st.print();

// 	st.push(10);
// 	st.push(20);
// 	st.push(30);
// 	st.print();
// 	st.push(40);
// 	st.push(50);

// 	st.print();


// 	return 0;
// }




