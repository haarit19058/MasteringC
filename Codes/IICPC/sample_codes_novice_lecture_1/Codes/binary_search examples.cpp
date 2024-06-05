#include <bits/stdc++.h>
using namespace std;

int main()
{
    int array[] = {2, 3, 12, 12, 15, 20, 25, 30, 55, 60, 70};
    int n = sizeof(array) / sizeof(array[0]);
    int x = 12;

    // auto keyword automatically determines the data type of the variable
    cout << "First: \n";
    auto k = lower_bound(array, array + n, x) - array;
    if (k < n && array[k] == x)
    {
        cout << k << "\n";
    }

    cout << "Second: \n";
    auto a = lower_bound(array, array + n, x);
    auto b = upper_bound(array, array + n, x);
    cout << b - a << "\n";

    cout << "Third: \n";
    auto r = equal_range(array, array + n, x);
    cout << r.second - r.first << "\n";
}
