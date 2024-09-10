#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> a)
{
    int withDelete = 0;
    int withOutDelete = a[0];
    int result = a[0];

    for (int i = 1; i < a.size(); i++)
    {
        withDelete = max(withOutDelete, withDelete + a[i]);
        withOutDelete = max(withOutDelete + a[i], a[i]);
        result = max(max(result, withDelete), withOutDelete);

        cout << "Result : " << result << endl
             << "WithDelete : " << withDelete << endl
             << "WithoutDelete : " << withOutDelete << endl;
    }
    return result;
}

int main()
{
    vector<int> a = {1, -2, 0, 3};
    solve(a);
    return 0;
}