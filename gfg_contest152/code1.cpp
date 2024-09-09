#include <iostream>
#include <vector>
#include <unordered_map> 
using namespace std;

void display(vector<int> a)
{
    cout << endl;
    for(auto i : a)
        cout << i << " ";
    cout << endl;
}

vector<int> frequency(vector<int> a)
{
    int n = a.size();
    vector<int> ans(n);
    unordered_map<int, int> m;

    for(int i = n - 1; i >= 0;i--)
    {
        m[a[i]]++;
        ans[i] = m[a[i]];
    }

    return ans;
}


int main()
{
    vector<int> v = {1,1,1,2,2};
    display(v);
    v = frequency(v);
    display(v);
    return 0;
}