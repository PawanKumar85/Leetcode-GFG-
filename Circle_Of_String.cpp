#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
            DFS(adj[node][i], adj, visited);
    }
}

int isCircle(vector<string> &A)
{
    vector<int> adj[26];
    vector<int> InDegree(26, 0);
    vector<int> OutDegree(26, 0);
    vector<bool> visited(26, 0);
    int N = A.size();

    for (int i = 0; i < N; i++)
    {
        string temp = A[i];
        int u = temp[0] - 'a';
        int v = temp[temp.size() - 1] - 'a';
        adj[u].push_back(v);
        InDegree[v]++;
        OutDegree[u]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (InDegree[i] != OutDegree[i])
            return 0;
    }

    int node = A[0][0] - 'a';
    DFS(node, adj, visited);
    for (int i = 0; i < 26; i++)
    {
        if (InDegree[i] && !visited[i])
            return 0;
    }
    return 1;
}

int main()
{
    // vector<string> A = {"ab" , "bc", "cd", "da"};
    vector<string> A = {"abc", "bcd", "cdf"};

    isCircle(A) ? cout << "True" : cout << "False";
    return 0;
}