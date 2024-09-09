#include <iostream>
#include <vector>
using namespace std;

int maxi(int a, int b)
{
    return a > b ? a : b;
}

int solve(vector<int> a)
{
    if (a[0] == 0)
        return -1;

    int jumps = 0;
    int maxReach = 0;
    int lastJump = 0;
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        maxReach = max(maxReach, i + a[i]);
        if (i == lastJump)
        {
            jumps++;
            lastJump = maxReach;
        }
    }
    if(lastJump < n - 1) return -1;
    return jumps;
}


int solve2(vector<int> a){
    if(a[0] == 0) return -1;
    
    int maxReach = a[0];
    int jump = 1;
    int n = a.size();
    int i = 0;
    while(i < n){
        i += a[i];
        if(i < n) jump++;
    }
    return jump;
}
int main()
{
    vector<int> a = {9, 10, 1, 2, 3, 4, 8, 0, 0, 0, 0, 0, 0, 0, 1};
    // vector<int> a = {1, 4, 3, 2, 7};
    // vector<int> a = {0, 10, 20};
    // vector<int> a = {1,2,0,0,0};
    // vector<int> a = {1,2,0,0,0};
    // vector<int> a = {1,4,3,2,6,7};

    cout << "\nJumps : " << solve2(a);
    return 0;
}