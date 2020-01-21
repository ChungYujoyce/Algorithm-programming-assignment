#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    if (m < n) return findMedianSortedArrays(nums2, nums1);
    if (n == 0) return ((double)nums1[(m - 1) / 2] + (double)nums1[m / 2]) / 2.0;
    int left = 0, right = n * 2;
    while (left <= right) {
        int mid2 = (left + right) / 2;
        int mid1 = m + n - mid2;
        double L1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
        double L2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
        double R1 = mid1 == m * 2 ? INT_MAX : nums1[mid1 / 2];
        double R2 = mid2 == n * 2 ? INT_MAX : nums2[mid2 / 2];
        if (L1 > R2) left = mid2 + 1;
        else if (L2 > R1) right = mid2 - 1;
        else return (max(L1, L2) + min(R1, R2)) / 2;
    }
    return -1;
}
        // O(nlogn) version
        /*vector<int> nums3;
        double ans;
        nums3.insert(nums3.end(),nums1.begin(),nums1.end());
        nums3.insert(nums3.end(),nums2.begin(),nums2.end());
        sort(nums3.begin(),nums3.end());
        if(nums3.size()%2==1)
            ans=nums3[((nums3.size())-1)/2];
        else
        {
            ans=(nums3[(nums3.size())/2]+nums3[(nums3.size())/2-1])/2.0;
        }
        return ans;*/



int main()
{
    int length=0;
    int element=0;
    vector<int> array1;
    vector<int> array2;
    /*cin >> length;
    for(int i=0;i<length;i++){
        cin >> element;
        array1.push_back(element);
    }
    for(int i=0;i<length;i++){
        cin >> element;
        array2.push_back(element);
    }*/
    auto start = std::chrono::high_resolution_clock::now();
    ifstream file("C:\\Users\\USER\\Desktop\\algo\\testcase_hw2\\testcase.txt");
    int a;
    while (file >> a)
    {
        array1.push_back(a);
        //cout << a << endl;
    }
    ifstream fileb("C:\\Users\\USER\\Desktop\\algo\\testcase_hw2\\testcase-2.txt");
    int b;
    while (fileb >> b)
    {
        array2.push_back(b);
    }
    double ans = findMedianSortedArrays(array1, array2);
    //cout << floor(ans) << endl;

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Time of input 10^4 : " << elapsed.count() << " s\n";

    vector<int> array3;
    vector<int> array4;

    auto start2 = std::chrono::high_resolution_clock::now();
    ifstream file2("C:\\Users\\USER\\Desktop\\algo\\testcase_hw2\\testcase5.txt");
    while (file2 >> a)
    {
        array3.push_back(a);
        //cout << a << endl;
    }
    ifstream fileb2("C:\\Users\\USER\\Desktop\\algo\\testcase_hw2\\testcase5-2.txt");
    while (fileb2 >> b)
    {
        array4.push_back(b);
    }
    double ans2 = findMedianSortedArrays(array3, array4);
    //cout << floor(ans2) << endl;

    auto finish2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = finish2 - start2;
    std::cout << "Time of input 10^5 : " << elapsed2.count() << " s\n";
    vector<int> array5;
    vector<int> array6;
    auto start3 = std::chrono::high_resolution_clock::now();
    ifstream file3("C:\\Users\\USER\\Desktop\\algo\\testcase_hw2\\testcase6.txt");
    while (file3 >> a)
    {
        array5.push_back(a);
        //cout << a << endl;
    }
    ifstream fileb3("C:\\Users\\USER\\Desktop\\algo\\testcase_hw2\\testcase6-2.txt");
    while (fileb3 >> b)
    {
        array6.push_back(b);
    }
    double ans3 = findMedianSortedArrays(array5, array6);
    //cout << floor(ans3) << endl;

    auto finish3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed3 = finish3 - start3;
    std::cout << "Time of input 10^6 : " << elapsed3.count() << " s\n";
    return 0;
}
