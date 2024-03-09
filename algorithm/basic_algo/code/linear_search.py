def linear_search(lst, target):
    for i in range(len(lst)):
        if lst[i] == target:
            return i

    return -1


a = [4, 8, 4, 3, 1, 2, 3, 0]
print(linear_search(a, 4))
print(linear_search(a, 0))
print(linear_search(a, 10))