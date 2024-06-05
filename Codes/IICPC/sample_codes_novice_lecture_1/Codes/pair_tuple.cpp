#include <bits/stdc++.h>
using namespace std;
int main()
{
    // defining a pair
    cout << "Defining a pair: \n";
    pair<int, int> p1 = make_pair(1, 12);
    cout << p1.first << " " << p1.second << endl;
    pair<int, string> p2(2, "Hello");
    cout << p2.first << " " << p2.second << endl;

    // defining a tuple
    cout << "\nDefining a tuple: \n";
    tuple<int, int, int> t1 = make_tuple(1, 2, 3);
    cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << endl;
    tuple<int, string, string> t2(4, "Hello", "World");
    cout << get<0>(t2) << " " << get<1>(t2) << " " << get<2>(t2) << endl;

    // unpacking a tuple
    cout << "\nUnpacking a tuple: \n";
    int a, b, c;
    tie(a, b, c) = t1;
    cout << "a: " << a << " b: " << b << " c: " << c << endl;

    // concetanating two tuples
    cout << "\nconcetanating two tuples: \n";
    tuple<int, int, int> t3 = make_tuple(4, 5, 6);
    auto t4 = tuple_cat(t1, t3);
    cout << get<0>(t4) << " " << get<1>(t4) << " " << get<2>(t4) << " " << get<3>(t4) << " " << get<4>(t4) << " " << get<5>(t4) << endl;

    // vector of pairs
    cout << "\nVector of pairs: \n";
    vector<pair<int, int>> v;
    v.push_back({3, 9});
    v.push_back({3, 4});
    v.push_back({5, 6});
    v.push_back({6, 2});
    for (auto x : v)
    {
        cout << x.first << " " << x.second << endl;
    }
    // sorting the vector of pairs
    sort(v.begin(), v.end());
    cout << "After sorting: \n";
    for (auto x : v)
    {
        cout << x.first << " " << x.second << endl;
    }

    // vector of tuples
    cout << "\nVector of tuples: \n";
    vector<tuple<int, int, int>> v1;
    v1.push_back({4, 5, 6});
    v1.push_back({4, 2, 3});
    v1.push_back({7, 8, 9});
    v1.push_back({1, 2, 3});
    for (auto x : v1)
    {
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
    }

    // sorting the vector of tuples
    sort(v1.begin(), v1.end());
    cout << "\n\nAfter sorting: \n";
    for (auto x : v1)
    {
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
    }

    // vector of vectors
    cout << "\nVector of vectors: \n";
    vector<vector<int>> v2;
    v2.push_back({4, 5, 6});
    v2.push_back({4, 5, 3, 7});
    v2.push_back({2, 8, 9});
    v2.push_back({1, 2, 3, 4});
    v2.back().push_back(10);
    sort(v2.begin(), v2.end());
    for (auto x : v2)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    // vector of vectors
    cout << "\nVector of vectors initalised: \n";
    vector<vector<int>> v3(4, vector<int>(4, 1));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            v3[i][j] = i + j;
            cout << v3[i][j] << " ";
        }
        cout << endl;
    }

}