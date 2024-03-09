def binary_search(lst, target):
    left, right = 0, len(lst) - 1

    while left <= right:
        mid = (left + right) // 2
        if lst[mid] == target:
            return mid
        elif lst[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1

nums = [1, 1, 4, 5, 7, 8, 9, 10, 11, 12]
print(binary_search(nums, 4))
print(binary_search(nums, 1))
print(binary_search(nums, 12))
print(binary_search(nums, 13))