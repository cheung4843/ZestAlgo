# Linear Search
## Introduction
*線性搜尋(Linear Search)*或稱*循序搜尋(Squential Search)*，是一種簡單的*搜尋*演算法，它是一種遍歷整個串列的方式，逐一檢查每個元素，直到找到目標。

這個演算法的時間複雜度是 $\mathcal{O}(n)$，因為最壞的情況就是目標值不存在，需要檢查整個串列。

<video muted controls autoplay loop>
  <source src="../../basic_algo/media/linear_search.mp4" type="video/mp4">
</video>

這應該是最簡單的演算法之一，不過我們可以來複習上一章所學的時間複雜度。

## Implementation

直接來看程式碼，定義 `linear_search(lst, target)` 函式，這個函式接受一個串列 `lst` 和一個目標值 `target`，回傳目標值在串列中的索引，如果目標值不存在就回傳 `-1`。

``` python linenums='1'
def linear_search(lst, target):
    for i in range(len(lst)):
        if lst[i] == target:
            return i

    return -1


a = [4, 8, 4, 3, 1, 2, 3, 0]
print(linear_search(a, 4))
print(linear_search(a, 0))
print(linear_search(a, 10))
```

``` title="Output" linenums="1"
0
7
-1
```

還記得上一章的練習嗎? 這個函式的最佳、最壞、平均時間複雜度是多少?

??? note "Answer"
    最佳狀況就是第一個元素就是目標，最壞狀況就是目標不存在或是他是最後一個元素，平均狀況就是目標在串列的中間，所以時間複雜度是 $\mathcal{O}(1),\mathcal{O}(n),\mathcal{O}(n/2)$。

而串列原本就有一個 `index` 方法可以做到這件事，以及你可以用 `in` 關鍵字來檢查目標值是否在串列中。

``` python
a = [4, 8, 4, 3, 1, 2, 3, 0]
print(a.index(4))
print(4 in a)
```

``` title="Output"
0
True
```

所以這個演算法在實務上並不常用，就當作熱熱身。

## Practice
### LeetCode 540. Single Element in a Sorted Array
!!! success ""
    [LeetCode 540. Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/description/)

??? abstract "Reference Code"
    ``` python linenums="1"
    class Solution:
        def singleNonDuplicate(self, nums: list[int]) -> int:
            if len(nums) == 1 or nums[0] != nums[1]:
                return nums[0]
            elif nums[-1] != nums[-2]:
                return nums[-1]

            for i in range(1, len(nums) - 1):
                if nums[i] != nums[i - 1] and nums[i] != nums[i + 1]:
                    return nums[i]
    ```

    很直觀，只要檢查相鄰的兩個元素是否相等，如果不相等就是答案。但這樣我們並沒有用到這個串列是排序過的這個特性，下一章介紹的*二元搜尋法(Binary Search)*可以更快的解決這個問題。