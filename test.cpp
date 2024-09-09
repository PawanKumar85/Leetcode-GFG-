#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int temp[100];

    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < temp[k]; i++) {
            for (int j = 0; j < temp[k]; j++) {
                if (i % 2 == j % 2) {
                    cout << "##";
                } else {
                    cout << "..";
                }
            }
            cout << endl;
            for (int j = 0; j < temp[k]; j++) {
                if (i % 2 == j % 2) {
                    cout << "##";
                } else {
                    cout << "..";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
