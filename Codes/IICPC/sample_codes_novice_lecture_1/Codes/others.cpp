#include <bits/stdc++.h>
using namespace std;
int main()
{
    // deque
    deque<int> dq;
    dq.push_back(1);  // [1]
    dq.push_back(2);  // [1,2]
    dq.push_front(3); // [3,1,2]
    dq.push_front(4); // [4,3,1,2]
    cout << "\nDeque: \n";
    for (auto x : dq)
    {
        cout << x << " ";
    }
    cout << "\n";
    dq.pop_back();  // [4,3,1]
    dq.pop_front(); // [3,1]

    // stack
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3); // [1,2,3]
    cout << "\nStack: \n";
    while (!s.empty())
    {
        cout << s.top() << " "; // s.top() returns the top element of the stack
        s.pop();                // s.pop() removes the top element of the stack
    }
    // Output: 3 2 1
    cout << "\n";

    // queue
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3); // [1,2,3]
    cout << "\nQueue: \n";
    while (!q.empty())
    {
        cout << q.front() << " "; // q.front() returns the front element of the queue
        q.pop();                  // q.pop() removes the front element of the queue
    }
    // Output: 1 2 3

    // priority queue
    priority_queue<int> pq;
    pq.push(3); // [3]
    pq.push(1); // [3,1]
    pq.push(5); // [5,3,1]
    pq.push(4); // [5,4,3,1]
    cout << "\nPriority Queue: \n";
    while (!pq.empty())
    {
        cout << pq.top() << " "; // pq.top() returns the top element of the priority queue
        pq.pop();                // pq.pop() removes the top element of the priority queue
    }
    // Output: 5 4 3 1
    cout << "\n";

    // priority queue with custom comparator
    priority_queue<int, vector<int>, greater<int>> pq1; // minumum element at the top
    pq1.push(3);                                        // [3]
    pq1.push(1);                                        // [1,3]
    pq1.push(5);                                        // [1,3,5]
    pq1.push(4);                                        // [1,3,4,5]
    cout << "\nPriority Queue with custom comparator: \n";
    while (!pq1.empty())
    {
        cout << pq1.top() << " "; // pq1.top() returns the top element of the priority queue
        pq1.pop();                // pq1.pop() removes the top element of the priority queue
    }
    // Output: 1 3 4 5
    cout << "\n";

    // Bitset
    bitset<5> b; // 5 bit bitset
    b[1] = 1;    // 00010
    b[2] = 1;    // 00110
    // indexing is from right to left
    cout << "\nBitset: \n";
    cout << b; // 00110
    cout << "\n";
    // bitset size is fixed at compile time
    // string to bitset
    string s1 = "10101";
    bitset<5> b1(s1);
    cout << b1; // 10101
    cout << "\n";
    // bitset to string
    cout << b1.to_string(); // 10101
    cout << "\n";
    // operations on bitset
    bitset<5> b2("10101");
    bitset<5> b3("01101");
    cout << "\nBitset operations: \n";
    cout << "b2 & b3 :" << (b2 & b3) << "\n"; // 00101
    cout << "b2 | b3 :" << (b2 | b3) << "\n"; // 11101
    cout << "b2 ^ b3 :" << (b2 ^ b3) << "\n"; // 11000
    cout << "b2 << 1 :" << (b2 << 1) << "\n"; // 01010
    cout << "b2 >> 2 :" << (b2 >> 2) << "\n"; // 00101
}