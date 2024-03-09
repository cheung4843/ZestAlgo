#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &lst, int target) {
    int left = 0;
    int right = lst.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (lst[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    vector<int> nums = {1, 1, 4, 5, 8, 8, 8, 10, 11, 12};

    cout << binary_search(nums, 1) << endl;
    cout << binary_search(nums, 8) << endl;

    return 0;
}