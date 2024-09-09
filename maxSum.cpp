#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>&a){
    int maxSum = a[0];
    int currentSum = a[0];

    for(int i = 1;i < a.size();i++){
        currentSum = max(a[i],a[i] + currentSum);
        maxSum = max(maxSum,currentSum);
    }
    return maxSum;
}

int main()
{
    // vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> a = {1};
    cout << "MaxSum :" << maxSubArray(a);
}