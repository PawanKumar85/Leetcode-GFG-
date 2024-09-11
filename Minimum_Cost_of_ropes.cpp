#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void display(priority_queue<int,vector<int>,greater<int>>q){
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl << endl;
}

int solve(vector<int> &A){
    int ans = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0;i < A.size();i++)
        pq.push(A[i]);
    
    while(pq.size()!= 1){
        int X = pq.top();
        pq.pop();
        int Y = pq.top();
        pq.pop();

        cout << X << "+" << Y << "=" << X + Y << endl;

        pq.push(X + Y);
        display(pq);
        ans += (X + Y);
    }
}

int main(){
    vector<int> A = {4,2,3,6};
    solve(A);
    return 0;
}