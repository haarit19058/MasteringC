#include <bits/stdc++.h>
using namespace std;
int main()
{
    // The following code creates an empty vector and adds three elements to it:
    vector<int> v;
    v.push_back(3); // [3]
    v.push_back(2); // [3,2]
    v.push_back(5); // [3,2,5]

    // After this, the elements can be accessed like in an ordinary array:
    cout << v[0] << " "; // 3
    cout << v[1] << " "; // 2
    cout << v[2] << " "; // 5

    v[0] = 7; // [7,2,5]

    cout << "\n";
    // The function size returns the number of elements in the vector. The following code iterates through the vector and prints all elements in it:
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";

    // A shorter way to iterate through a vector is as follows:
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << "\n";

    // The function back returns the last element in the vector, and the function pop_back removes the last element:
    vector<int> v1;
    v1.push_back(5);
    v1.push_back(2);           // v1 = [5,2]
    cout << v1.back() << "\n"; // 2
    v1.pop_back();   // v1 = [5]
    cout << v.back() << "\n"; // 5

    // The following code creates a vector with five elements:
    vector<int> v2 = {2, 4, 2, 5, 1};

    // Another way to create a vector is to give the number of elements and the initial value for each element:

    // size 10, initial value 0
    vector<int> v3(10);

    // size 10, initial value 5
    vector<int> v4(10, 5);
}