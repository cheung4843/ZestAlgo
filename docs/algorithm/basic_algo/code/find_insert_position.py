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

    return left


nums = [1, 1, 4, 5, 7, 8, 9, 10, 11, 12]

idx = binary_search(nums, 6)
nums.insert(idx, 6)
print(nums)

idx2 = binary_search(nums, 13)
nums.insert(idx2, 13)
print(nums)

idx3 = binary_search(nums, 0)
nums.insert(idx3, 0)
print(nums)