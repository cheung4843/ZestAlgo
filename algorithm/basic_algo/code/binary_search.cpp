#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &lst, int target) {
    int left = 0;
    int right = lst.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (lst[mid] == target) {
            return mid;
        } else if (lst[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 1, 4, 5, 7, 8, 9, 10, 11, 12};
    cout << binary_search(nums, 4) << endl;
    cout << binary_search(nums, 1) << endl;
    cout << binary_search(nums, 12) << endl;
    cout << binary_search(nums, 13) << endl;

    return 0;
}