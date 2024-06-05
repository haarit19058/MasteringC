#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ordered set
    // set is a container in c++ STL which stores the elements in sorted order
    // set is implemented using balanced binary search tree
    // set is used to store unique elements
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3); // this will not be inserted as set stores unique elements
    // insertion takes O(logn) time
    // s = {1, 2, 3}
    cout << "Set elements are: ";
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << "\n";

    cout << "\nChecking if 2,4 are present in the set: \n";
    cout << "4: " << s.count(4) << endl; // returns 0 as 4 is not present in the set
    cout << "2: " << s.count(2) << endl; // returns 1 as 2 is present in the set
    // count takes O(logn) time

    cout << "\nErasing 2 from the set: \n";
    s.erase(2);
    // s = {1, 3}
    // erasing an element also takes O(logn) time
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << "\n";

    // elements of set cannot be accessed using the index operator []
    //  cout << s[0] << endl; // this will give an error

    // unordered set
    // it is similar to set but it stores the elements in an unordered manner
    // unordered set is implemented using hashing
    unordered_set<int> us;
    us.insert(4);
    us.insert(2);
    us.insert(3);
    us.insert(3); // this will not be inserted as unordered set stores unique elements
    us.insert(5);
    us.insert(1);
    // insertion takes O(1) time
    // us = {4, 2, 3, 5, 1};
    cout << "\nUnordered set elements are: ";
    for (auto x : us)
    {
        cout << x << " ";
    }
    cout << "\n";

    // checking if an element is present in the unordered set
    cout << "\nChecking if 2,4 are present in the unordered set: \n";
    cout << "4: " << us.count(4) << endl; // returns 1 as 4 is present in the unordered set
    cout << "2: " << us.count(2) << endl; // returns 1 as 2 is present in the unordered set
    // count takes O(1) time

    // erasing an element from the unordered set
    cout << "\nErasing 2 from the unordered set: \n";
    us.erase(2);
    // erasing an element takes O(1) time
    // us = {4, 3, 5, 1}

    for (auto x : us)
    {
        cout << x << " ";
    }

    // multiset
    // multiset is similar to set but it can store duplicate elements
    multiset<int> ms;
    ms.insert(4);
    ms.insert(2);
    ms.insert(3);
    ms.insert(3); // this will be inserted as multiset stores duplicate elements
    ms.insert(5);
    ms.insert(5);
    // ms = {2, 3, 3, 4, 5, 5}
    //  insertion takes O(logn) time

    // checking if an element is present in the multiset
    cout << "\nChecking if 2,3 are present in the multiset: \n";
    cout << "3: " << ms.count(3) << endl; // returns 2 as 3 is present twice in the multiset
    cout << "2: " << ms.count(2) << endl; // returns 1 as 2 is present once in the multiset

    // erasing an element from the multiset
    cout << "\nErasing 3 from the multiset: \n";
    ms.erase(3); // this will erase all the occurrences of 3
    // erasing an element takes O(logn) time
    // ms = {2, 4, 5, 5}

    // to erase only one occurrence of an element from the multiset
    cout << "\nErasing only one occurrence of 5 from the multiset: \n";
    ms.erase(ms.find(5)); // this will erase only one occurrence of 5
    // ms = {2, 4, 5}

    // similarly we have unordered_multiset
    //  unordered_multiset is similar to multiset but it stores the elements in an unordered manner

    // set_iterator
    //  set iterator is used to iterate through the set because we can't access the elements of the set using the index operator []
    set<int> s1;
    s1 = {21, 12, 33, 24, 15};
    set<int>::iterator it = s.begin();
    cout << "\n\nFirst Element : " << *it << endl; // 12
    cout << "elements of the set using the iterator: \n";
    // iterator can be incremented using ++ operator or it can be decremented using -- operator
    // iterator can be dereferenced using * operator
    // printing the elements of the set using the iterator
    for (auto it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }

    // find function is used to find an element in the set
    // find function returns an iterator to the element if it is present in the set otherwise it returns the iterator to the end of the set
    cout << "\n\nFinding 33 in the set: \n";
    auto it1 = s1.find(33);
    if (it1 != s1.end())
    {
        cout << "33 is present in the set\n";
    }
    else
    {
        cout << "33 is not present in the set\n";
    }

    // lower_bound function returns an iterator to the element if it is present in the set otherwise it returns an iterator to the smallest element greater than the given element
    cout << "\nFinding the lower bound of 25 in the set: \n";
    auto it2 = s1.lower_bound(24);
    cout << *it2 << endl; // 24

    // upper_bound function returns an iterator to the smallest element greater than the given element
    cout << "\nFinding the upper bound of 25 in the set: \n";
    auto it3 = s1.upper_bound(24);
    cout << *it3 << endl; // 33

    // lower_bound and upper_bound functions take O(logn) time
    // These functions are for ordered set only
    // They don't work for unordered set
}