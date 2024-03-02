// C++ program to demonstrate working
// of erase

Some Manipulating Algorithms
arr.erase(position to be deleted) – This erases selected element in vector and shifts and resizes the vector elements accordingly.
arr.erase(unique(arr.begin(),arr.end()),arr.end()) – This erases the duplicate occurrences in sorted vector in a single line.
next_permutation(first_iterator, last_iterator) – This modified the vector to its next permutation.
prev_permutation(first_iterator, last_iterator) – This modified the vector to its previous permutation. 
distance(first_iterator,desired_position) – It returns the distance of desired position from the first iterator.This function               is very useful while finding the index.



#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    // Initializing vector with array values
    int arr[] = { 5, 10, 15, 20, 20, 23, 42, 45 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);
 
    cout << "Given Vector is:\n";
    for (int i = 0; i < n; i++)
        cout << vect[i] << " ";
 
    vect.erase(find(vect.begin(),vect.end(),10));
    cout << "\nVector after erasing element:\n";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";
 
    vect.erase(unique(vect.begin(), vect.end()),
               vect.end());
    cout << "\nVector after removing duplicates:\n";
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";
 
    return 0;
}
Output
Given Vector is:
5 10 15 20 20 23 42 45 
Vector after erasing element:
5 15 20 20 23 42 45 
Vector after removing duplicates:
5 15 20 23 42 45


// C++ program to demonstrate working
// of next_permutation()
// and prev_permutation()
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    // Initializing vector with array values
    int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);
 
    cout << "Given Vector is:\n";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";
 
    // modifies vector to its next permutation order
    next_permutation(vect.begin(), vect.end());
    cout << "\nVector after performing next permutation:\n";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";
 
    prev_permutation(vect.begin(), vect.end());
    cout << "\nVector after performing prev permutation:\n";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";
 
    return 0;
}
Output
Given Vector is:
5 10 15 20 20 23 42 45 
Vector after performing next permutation:
5 10 15 20 20 23 45 42 
Vector after performing prev permutation:
5 10 15 20 20 23 42 45


// C++ program to demonstrate working of distance()
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    // Initializing vector with array values
    int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);
 
    // Return distance of first to maximum element
    cout << "Distance between first to max element: ";
    cout << distance(vect.begin(),
                     max_element(vect.begin(), vect.end()));
    return 0;
}
Output
Distance between first to max element: 7

