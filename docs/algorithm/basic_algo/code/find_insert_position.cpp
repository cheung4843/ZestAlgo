#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &lst, int target) {
    int left = 0;
    int right = lst.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (lst[mid] == target) {
            return mid;
        } else if (lst[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

void printVector(const vector<int> &nums) {
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 1, 4, 5, 7, 8, 9, 10, 11, 12};

    int idx = binary_search(nums, 6);
    nums.insert(nums.begin() + idx, 6);
    printVector(nums);

    int idx2 = binary_search(nums, 13);
    nums.insert(nums.begin() + idx2, 13);
    printVector(nums);

    int idx3 = binary_search(nums, 0);
    nums.insert(nums.begin() + idx3, 0);
    printVector(nums);

    return 0;
}