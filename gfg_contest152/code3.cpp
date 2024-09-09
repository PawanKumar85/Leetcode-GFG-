#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int solve(vector<int> v, int k)
{
    int n = v.size();
    stack<int> st;

    int sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        st.push(v[i]);

        if (sum > k)
        {
            int run = count + 1;
            while (run > 0 && !st.empty())
            {
                int top = st.top();
                sum -= top;
                st.pop();
                run--;
            }

            count++;
        }
    }
        return sum;
}

int main()
{
    vector<int> v{2, 3, 1, 3, 4, 1, 1};
    int k = 5;

    cout << solve(v,k);
    return 0;
}