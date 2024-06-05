#include <bits/stdc++.h>
using namespace std;
bool comp(string a, string b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}
int main()
{
    string arr[] = {"Abhi", "Ayush", "Aditya", "Harsh", "Punya", "Abhishek"};
    sort(arr, arr + 6, comp);
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
}
// Output: Abhi Ayush Harsh Punya Aditya Abhishek
