#include <iostream>
#include <vector>
#include <map>
using namespace std;

//Time complexity O(n^2)
int count(vector<int> v,int k)
{
    int count = 0;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n;j++)
        {
            if(v[i] == v[j] && abs(i - j) >= k)
                count++;
        }
    }
    return count;
}


// time complexity O(1)
int count2(vector<int> a,int k)
{
    int n = a.size();
    map<int,int> m;
    int ans = 0;

    for(int i = k;i < n;i++)
    {
        m[a[i - k]]++;
        ans += m[a[i]];
    }

    return ans;
}

int main()
{
    vector<int> v{1, 2, 2, 1, 2};
    int k = 2;

    cout << count2(v,k);
    return 0;
}