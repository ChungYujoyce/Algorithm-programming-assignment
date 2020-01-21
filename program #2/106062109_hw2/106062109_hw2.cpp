#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double FindMedian(vector<int>& array1, vector<int>& array2){
    int N1 = array1.size();
    int N2 = array2.size();
    if(N1 < N2) return FindMedian(array2, array1); // Make array1 always larger than array2

    int left = 0, right = N2 * 2;
    // why right is N2 ? Since we add characters between numbers, so the total position is actually N2 *2

    while(left <= right){ // binary search
        int mid2 = (left + right) /2; // -> C2
        int mid1 = N1 + N2 -mid2; // actually it's (N1 + N2 - mid2) / 2; -> C1

        // Get L1, R1, L2, R2 respectively
        double L1 = (mid1 == 0) ? INT_MIN : array1[(mid1-1)/2];
        double L2 = (mid2 == 0) ? INT_MIN : array2[(mid2-1)/2];
        double R1 = (mid1 == N1 * 2) ? INT_MAX : array1[mid1/2];
        double R2 = (mid2 == N2 * 2) ? INT_MAX : array2[mid2/2];

        if(L1 > R2)
            left = mid2 + 1; // A1' left half is too big, move C1 left (C2 right)
        else if(L2 > R1)
            right = mid2 - 1; // A2's left half too big, move C2 left
        else return (max(L1,L2) + min(R1,R2))/2.0; // Right cut, get median
    }
    return -1;
}

int main()
{
    int length=0;
    int element=0;
    vector<int> array1;
    vector<int> array2;
    cin >> length;
    for(int i=0;i<length;i++){
        cin >> element;
        array1.push_back(element);
    }
    for(int i=0;i<length;i++){
        cin >> element;
        array2.push_back(element);
    }
    double ans = FindMedian(array1, array2);
    cout << floor(ans) << endl;
    return 0;
}
