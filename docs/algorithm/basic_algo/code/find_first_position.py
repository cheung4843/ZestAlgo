def binary_search(lst, target):
    left, right = 0, len(lst) - 1

    while left <= right:
        mid = (left + right) // 2
        if lst[mid] >= target:
            right = mid - 1
        else:
            left = mid + 1

    return left


nums = [1, 1, 4, 5, 8, 8, 8, 10, 11, 12]

print(binary_search(nums, 1))
print(binary_search(nums, 8))