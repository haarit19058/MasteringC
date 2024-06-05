#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    v = {9, 3, 6, 1, 2, 5, 8, 7, 4};

    cout << "Sorting the vector: \n";
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        cout << x << " ";
    }

    cout << "\n\nSorting the vector in descending order: \n";
    sort(v.begin(), v.end(), greater<int>());
    for (auto x : v)
    {
        cout << x << " ";
    }

    random_shuffle(v.begin(), v.end());
    cout << "\n\nSorting the vector in descending order using rbegin and rend: \n";
    // rbegin and rend are reverse iterators
    // rbegin points to the last element of the vector and rend points to the element before the first element of the vector
    sort(v.rbegin(), v.rend());
    for (auto x : v)
    {
        cout << x << " ";
    }

    cout << "\n\nShuffling the vector: \n";
    random_shuffle(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    cout << "\n\nReversing the vector: \n";
    reverse(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    // accumulate function is used to find the sum of all the elements in the vector
    //  time complexity of accumulate is O(n)
    cout << "\n\nSum of all the elements in the vector: " << accumulate(v.begin(), v.end(), 0);
    // syntax of accumulate function is accumulate(starting iterator, ending iterator, initial value)

    // how to define an iterator?
    vector<int>::iterator it;

    cout << "\n\nErasing an element from the vector at index 2: \n";
    v.erase(v.begin() + 2);
    for (auto x : v)
    {
        cout << x << " ";
    }

    cout << "\n\nErasing a range of elements from the vector from index 2 to 4: \n";
    v.erase(v.begin() + 2, v.begin() + 5); // first is inclusive, second is exclusive
    for (auto x : v)
    {
        cout << x << " ";
    }

    // time complexity of insert is O(n)
    cout << "\n\nInserting an element 10 at index 2: \n";
    v.insert(v.begin() + 2, 10);
    for (auto x : v)
    {
        cout << x << " ";
    }

    cout << "\n\nInserting 3 elements 11 at index 2: \n";
    v.insert(v.begin() + 2, 3, 11); // 3 is the number of elements to be inserted and 11 is the element to be inserted
    for (auto x : v)
    {
        cout << x << " ";
    }

    cout << "\n\nInserting elements from another vector at index 2: \n";
    vector<int> v2 = {12, 13, 14};
    v.insert(v.begin() + 2, v2.begin(), v2.end()); // v2.begin() is the starting iterator and v2.end() is the ending iterator
    for (auto x : v)
    {
        cout << x << " ";
    }

    // max element and min element of vector
    // time complexity of max_element and min_element is O(n)
    cout << "\n\nMax element of the vector: " << *max_element(v.begin(), v.end());
    cout << "\nMin element of the vector: " << *min_element(v.begin(), v.end());

    // time complexity of resize is O(n)
    cout << "\n\nResizing the vector to 10 elements: \n";
    v.resize(10);
    for (auto x : v)
    {
        cout << x << " ";
    }

    // time complexity of unique is O(n)
    // unique function removes all the duplicate elements from the vector
    // unique function only works if the vector is sorted
    cout << "\n\nGetting unique elements from the vector: \n";
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (auto x : v)
    {
        cout << x << " ";
    }

    // rotate function rotates the vector by the number of elements specified
    // time complexity of rotate is O(n)
    cout << "\n\nRotating the vector by 3 elements: \n";
    rotate(v.begin(), v.begin() + 3, v.end());
    for (auto x : v)
    {
        cout << x << " ";
    }

    // time complexity of swap is O(1)
    cout << "\n\nSwapping the vector with another vector: \n";
    vector<int> v1 = {1, 2, 3, 4, 5};
    v.swap(v1);
    for (auto x : v)
    {
        cout << x << " ";
    }

    // time complexity of clear is O(n)
    cout << "\n\nClearing the vector \n";
    v.clear();
    cout << "Size of the vector: " << v.size();
}