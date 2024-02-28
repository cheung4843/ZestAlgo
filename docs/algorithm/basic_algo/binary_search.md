# Binary Search
## Before you start
你需要有以下的先備知識，才能更容易地閱讀這篇文章:

!!! success "Requirements"
    1. [What is an Algorithm?](../what_is_algo.md)
    
由這章開始逐漸變得困難，所以你可以依據需求來選擇閱讀:

!!! tip "Optional"
    1. 對 Binary Search 有個概念的認識，可以看到 [Complexity](#complexity)
    2. 知道實作與簡單的變形，可以看到 [Find the insert position](#find_the_insert_position)


## Introduction
Binary Search(二元搜尋法) 是*分治法(Divide and Conquer)*的一種應用，非常有效率，但只適用在**單調(Monotonic)**的序列或函數上，也就是說，必須是遞增或遞減的，或是你簡單理解成*排序過(sorted)*的，舉幾個例子:

1. `[1, 2, 3, 4, 5]`
2. `['a', 'b', 'c', 'd', 'e']`
3. `[32, 16, 8, 4, 2, 1]`
4. $f(x)=x^2, \ x \ge 0,\ [f(1), f(2), f(3), f(4), f(5)]$

函數 $f(x)=x^2$ 在 $x \ge 0$ 時是遞增的:

![](./media/binary_search_1.png)

```python linenums="1"
def f(x):
    return x ** 2


xs = [1, 2, 3, 4, 5]
print(xs)
# [f(1), f(2), f(3), f(4), f(5)]
ys = [f(x) for x in xs]
print(ys)
```

```title="Output" linenums="1"
[1, 2, 3, 4, 5]
[1, 4, 9, 16, 25]
```

最後一個例子是想跟你強調，*函數也可以用二元搜尋法*，例如想要找第一個 $f(x) \ge 10$ 的整數 $x$，我們可以用二元搜尋法找到 $x=4$。

那麼 `['I', 'n', 't', 'e', 'r', 's', 't', 'e', 'l', 'l', 'a', 'r']` 能用二元搜尋法嗎?答案應該是不能啦，但如果你找的到一個神奇的函式 $Magic(x)$，可以將這個序列經過映射後變成單調的，那算你厲害，但是，又要找什麼呢?

[Interstellar Main Theme - Extra Extended - Soundtrack by Hans Zimmer](https://www.youtube.com/watch?v=UDVtMYqUAyw)

## Complexity

玩過猜數字嗎?你每猜一次，我會告訴你猜的數字是太大還是太小，讓你從 $[1, 100]$ 間猜一個數字，怎麼猜會最有效率?如果你第一次就猜 $50$，我告訴你猜的數字太大，你就可以知道答案一定在 $[1, 49]$ 之間，這樣你就可以*省下一半*的時間，你可以再猜 $25$，而我告訴你猜的數字太小，那麼答案一定在 $[26, 49]$ 之間，你又省下一半的時間，這就是二元搜尋法的精神。

<video muted controls autoplay loop>
  <source src="../../basic_algo/media/binary_search_2.mp4" type="video/mp4">
</video>

那最多要猜幾次呢?假設你真的很衰，猜到剩下 $[47, 48]$ 這兩個數字在選的時候又猜錯，你猜了 $47$ 而我告訴你猜太小，那就只剩下 $48$ 了，也就是區間 $[48, 48]$ **剩下一個元素，這是我們的終止條件。**

考慮一般的情況，有 $n$ 個數字，每次猜都可以把區間縮小一半，設我們要猜 $k$ 次才能把區間縮小到剩下一個元素:

$$
\frac{n}{2^k} = 1
$$

$$
\Rightarrow n = 2^k
$$

$$
\Rightarrow \log_2 n = k
$$

那麼時間複雜度就是 $\mathcal{O}(k) = \mathcal{O}(\log n)$。

## Implementation

在寫程式之前，先來看動畫，有一個已排序過的串列 `[1, 1, 4, 5, 7, 8, 9, 10, 11, 12]`，我們要找 `4`:

<video muted controls autoplay loop>
  <source src="../../basic_algo/media/binary_search_3.mp4" type="video/mp4">
</video>

再來看程式碼:

=== "Python"
    ```python title="binary_search.py" linenums="1" hl_lines="2 4 5 9 11"
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
    ```
=== "C++"
    ```cpp title="binary_search.cpp" linenums="1" hl_lines="7 8 10 11 15 17"
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
    ```

```title="Output" linenums="1"
2
1
9
-1
```

如果找到 `target`，就回傳他的索引，否則回傳 `-1`。

先幫我留意一下，找 `1` 的時候是回傳從左到右第二個 `1` 的索引值，那如果我想要找到從左到右第一個 `1` 的索引值呢?這個我們後面會討論。

## Why it works?

事實上在實作二元搜尋法時，有很多細節需要注意:

- [1]首先注意到 `left, right` 的初始值，`left` 是 `0`，而 `right` 是 `len(lst) - 1`，這是因為我們的搜索範圍是 `[left, right]`，這是一個**閉區間**，也就是說 `left` 與 `right` 也都可能是答案。

- [2]注意到我們的中止條件是 `left > right`，而不是 `left >= right`，也請你多看幾次下方的動畫，只有白色的區域才是我們要尋找的範圍，而他的邊界由 `left` 與 `right` 來決定，如上所述，這是一個**閉區間** `[left, right]`，兩個端點 `left` 與 `right` 也在我們的搜索範圍內；考慮到 `left == right` 的情況，這時候我們的搜索範圍是 `[left, left]`，也就是只剩下一個元素，這也是合法的區間，也需要檢查。

<video muted controls autoplay loop>
  <source src="../../basic_algo/media/binary_search_4.mp4" type="video/mp4">
</video>

- [3]還有一個細節是 `mid` 的計算，使用 `(left + right) // 2` 來尋找區間中點並且向下取整，如果是使用 C++ 來實作，可以使用 `left + (right - left) / 2` 來避免*溢位(Overflow)*的問題，但在 Python 中不需要擔心這個問題，再次讚嘆。

- [4]再來看為什麼 `left = mid + 1` 與 `right = mid - 1`，這是因為我們已經知道 `mid` 不是我們要找的元素，因此要將他排除在搜索範圍之外；因此 `[mid + 1, right]` 或 `[left, mid - 1]` 是我們的新搜索範圍。你可能有看過其他寫法，一邊不變，一邊變。

- [5]事實上連 `lst[mid] < target` 這個也可以討論(可以處理重複值)，但我覺得你會很頭痛，上面這幾個排列組合湊起來會用哭你。

好了，我介紹完*最簡單*的版本了，我們來看一些例子，後面會介紹一些變形。

## Find the insert position
在上面的例子中，如果我們找不到目標元素，我們會回傳 `-1`，但有時候我們會想要知道目標元素應該插入的位置，該怎麼修改程式碼呢?

讓我們先看幾個動畫:


尋找比 `1` 還小的元素 `-1`:

<video muted controls>
  <source src="../../basic_algo/media/binary_search_5.mp4" type="video/mp4">
</video>

尋找雖然大於等於 `1` 以及小於等於 `12`，但不存在於串列中的元素 `6`:

<video muted controls>
  <source src="../../basic_algo/media/binary_search_6.mp4" type="video/mp4">
</video>

尋找比 `12` 還大的元素 `4843`:

<video muted controls>
  <source src="../../basic_algo/media/binary_search_7.mp4" type="video/mp4">
</video>

三種情況下，都可以發現 `left` 就是要插入的位置，所以最後回傳他就好了。

那為什麼呢?你可以發現總會有 `left == right` 的時候，`mid == left ==  right`。

如果 `lst[mid] < target`，那麼 `left = mid + 1`，`right` 保持不變，所以 `left` 會位於 `mid` 的右方一格，也正好是要插入的位置。

如果 `lst[mid] > target`，那麼 `right = mid - 1`，`left` 保持不變，`left` 也是正好是要插入的位置。

但來看一個例外，`left` 與 `right` 並不會重疊，而下一步直接 `left > right` 跳出迴圈。

<video muted controls>
  <source src="../../basic_algo/media/binary_search_9.mp4" type="video/mp4">
</video>

這是因為在當下 `left` 與 `right` 正好相差一格，而 `mid = (left + right) // 2`，等於 `left`，又因為 `target > lst[mid]`，所以 `right = mid - 1`，這時候 `right` 會變成 `left - 1`，造成 `right < left`，而跳出迴圈，但 `left` 仍然是要插入的位置。

所以最後的程式碼是:

=== "Python"
    ```python linenums="1" hl_lines="13" title="find_insert_position.py"
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
    ```

=== "C++"
    ```cpp linenums="1" hl_lines="21" title="find_insert_position.cpp"
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
    ```

```title="Output" linenums="1"
[1, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12]
[1, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]
[0, 1, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]
```

我們可以利用 `insert` 方法將元素插入串列中。

## Handling the duplicates
在上面的例子中，我們的串列中有 $2$ 個 `1`，我想要從左到右第一個 `1` 的索引值，該怎麼修改程式碼呢?

讓我們先看一個動畫:

<video muted controls>
  <source src="../../basic_algo/media/binary_search_8.mp4" type="video/mp4">
</video>

在我們目前的寫法中，我們只要 `lst[mid] == target` 就回傳 `mid`，就結束程式了，而沒有管他是不是第一個，所以應該要繼續縮小搜尋範圍。

現在我們要來面對 [Why it works?](#why_it_works) 的最後一點，修改 `right` 變動的部分，讓他繼續往左邊縮小搜尋範圍，直接看程式碼:

=== "Python"
    ```python linenums="1" hl_lines="6" title="find_first_position.py"
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
    ```

=== "C++"
    ```cpp linenums="1" hl_lines="12" title="find_first_position.cpp"
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
    ```

```title="Output" linenums="1"
0
4
```

找最左側的 `1`:

<video muted controls>
  <source src="../../basic_algo/media/binary_search_10.mp4" type="video/mp4">
</video>

找最左側的 `8`:

<video muted controls>
  <source src="../../basic_algo/media/binary_search_11.mp4" type="video/mp4">
</video>

事實上這樣寫，意思就變成找「大於等於 `target` 的第一個元素」，那如果要寫「小於等於 `target` 的最後一個元素」呢?試試看吧!

## Variant
來介紹我最喜歡的變形之一，你可以拿他來當作模板解題。

也跟你介紹我這陣子最喜歡的歌:

[LORDE - Everybody Wants to Rule the World (Extended)](https://www.youtube.com/watch?v=smSSSs46rng)

還記得我一直強調的*區間*嗎?上面的例子初始化左右邊界都是 $[0, n - 1]$，而這個變形是定義為 $(-1, n)$，這樣可以避免一些邊界問題。

To be continued...寫到有點頭痛，動畫、文章架構、程式碼都要打磨，先休息一下。

## Build-in function

## Practice

## Asignment