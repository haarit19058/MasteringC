#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> m;
    m["Ayush"] = 21;
    m["Punya"] = 23;
    m["Abhi"] = 31;
    m["Aditya"] = 45;
    m["Harsh"] = 15;
    // the map will be sorted according to the keys
    // all operations are O(logn) in map
    cout << m["Ayush"] << endl; // 21

    // to check if a key is present in the map
    cout << "Count of Ankit : " << m.count("Ankit") << endl; // 0

    // if a key is not present in the map, it will be inserted with a default value 0
    cout << "Default value : " << m["Ankit"] << endl; // 0

    // printing the map
    cout << "\nPrinting the map: \n";
    for (auto x : m)
    {
        cout << x.first << " " << x.second << endl;
    }

    // erasing a key from the map
    cout << "\nErasing Ayush key from the map: \n";
    m.erase("Ayush");
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    // unordered map
    // it is similar to map but it stores the elements in an unordered manner
    // unordered map is implemented using hashing
    unordered_map<string, int> um;
    um["Ayush"] = 21;
    um["Punya"] = 23;
    um["Abhi"] = 31;
    um["Aditya"] = 45;
    um["Harsh"] = 15;
    // all operations are O(1) in unordered map
    cout << "\nPrinting the unordered map: \n";
    for (auto x : um)
    {
        cout << x.first << " " << x.second << endl;
    }
}