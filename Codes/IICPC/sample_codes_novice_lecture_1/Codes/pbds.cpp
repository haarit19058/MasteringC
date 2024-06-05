#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main()
{
    indexed_set s;
    //same as set<int> s; but with some extra features like finding by order and order of key
    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.insert(8);
    s.insert(16);
    // s = {1, 2, 4, 8, 16}
    cout << *s.find_by_order(1) << endl; // 2
    cout << *s.find_by_order(2) << endl; // 4
    cout << *s.find_by_order(4) << endl; // 16
    
    cout << s.order_of_key(10) << endl; // 4
    cout << s.order_of_key(5) << endl; // 3
    cout << s.order_of_key(17) << endl; // 5
}