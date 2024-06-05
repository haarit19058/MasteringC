#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1 = "Hello";
    string s2 = "World";
    string s3 = s1 + s2; //"HelloWorld"
    cout << s3 << endl;
    cout << s3.size() << endl; // 10
    cout << s3[0] << endl;     // H
    cout << s3[1] << endl;     // e
    cout << s3[2] << endl;     // l

    // substring of a string
    cout << "\nSubstring of a string: \n";
    cout << s3.substr(0, 5) << endl; // Hello
    // 0 is the starting index and 5 is the length of the substring
    // time complexity of substr is O(n)

    // finding a substring in a string
    cout << "\nFinding a substring in a string: \n";
    cout << s3.find("lo") << endl; // 3

    // replacing a substring in a string
    cout << "\nReplacing a substring in a string: \n";
    s3.replace(3, 5, "Abhishek"); // HelloWorld -> HelAbhishekld
    // 3 is the starting index, 5 is the length of the substring to be replaced
    // time complexity of replace is O(n)
    cout << s3 << endl;

    // erasing a substring in a string
    cout << "\nErasing a substring in a string: \n";
    s3.erase(3, 8); // HelAbhishekld -> Helld
    // 3 is the starting index, 8 is the length of the substring to be erased
    // time complexity of erase is O(n)
    cout << s3 << endl;

    // converting a string to an integer
    cout << "\nConverting a string to an integer: \n";
    string s4 = "123";
    int x = stoi(s4);
    cout << x << endl;

    // converting an integer to a string
    cout << "\nConverting an integer to a string: \n";
    int y = 123;
    string s5 = to_string(y);
    cout << s5 << endl;

    // sorting a string
    cout << "\nSorting a string: \n";
    string s6 = "HelloWorld";
    // time complexity of sort is O(nlogn)
    sort(s6.begin(), s6.end());
    cout << s6 << endl;

    // reversing a string
    cout << "\nReversing a string: \n";
    string s7 = "HelloWorld";
    // time complexity of reverse is O(n)
    reverse(s7.begin(), s7.end());
    cout << s7 << endl;

    // unique function is used to remove consecutive duplicate characters
    // string should be sorted before using unique function
    cout << "\nUnique characters in a string: \n";
    string s8 = "HelloWorld";
    sort(s8.begin(), s8.end());
    // time complexity of unique is O(n)
    cout << s8 << endl;
    s8.erase(unique(s8.begin(), s8.end()), s8.end());
    cout << s8 << endl;

    // shuffling a string
    cout << "\nShuffling a string: \n";
    string s9 = "HelloWorld";
    random_shuffle(s9.begin(), s9.end());
    cout << s9 << endl;

    // finding the maximum and minimum element in a string
    cout << "\nMaximum and minimum element in a string: \n";
    string s10 = "HelloWorld";
    cout << *max_element(s10.begin(), s10.end()) << endl; // r
    cout << *min_element(s10.begin(), s10.end()) << endl; // H

    cout << "\nCounting the number of occurrences of a character in a string: \n";
    string s11 = "HelloWorld";
    cout << count(s11.begin(), s11.end(), 'l') << endl; // 3

    cout << "\nChecking if a string is lexicographically smaller than another string: \n";
    string s12 = "Hello";
    string s13 = "World";
    cout << (s12 < s13) << endl; // 1

    // replacing all occurrences of a character in a string
    cout << "\nReplacing all occurrences of a with l: \n";
    string s14 = "HelloWorld";
    replace(s14.begin(), s14.end(), 'l', 'a');
    cout << s14 << endl;

    // converting a string to uppercase
    cout << "\nConverting a string to uppercase: \n";
    string s15 = "HelloWorld";
    transform(s15.begin(), s15.end(), s15.begin(), ::toupper);
    cout << s15 << endl;

    // converting a string to lowercase
    cout << "\nConverting a string to lowercase: \n";
    string s16 = "HelloWorld";
    transform(s16.begin(), s16.end(), s16.begin(), ::tolower);
    cout << s16 << endl; 
}