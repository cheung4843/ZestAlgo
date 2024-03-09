#include <iostream>
#include <vector>
using namespace std;

int linear_search(vector<int> &lst, int target) {
    for (int i = 0; i < lst.size(); i++) {
        if (lst[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<int> a = {4, 8, 4, 3, 1, 2, 3, 0};
    cout << linear_search(a, 4) << endl;
    cout << linear_search(a, 0) << endl;
    cout << linear_search(a, 10) << endl;
}