# Sets
## Introduction
如果給你一個串列，請你檢查裡面有沒有重複的元素，你會怎麼做呢?你會怎麼樣確保裡面的元素是唯一的呢?

在這一章，我們將會學習到**集合(Set)**，它有以下特性:

- 無序: 集合裡面的元素是沒有順序的
- 不重複: 集合裡面的元素是唯一的
- 可變: 可以新增、刪除元素，但是裡面的元素必須是**不可變的(immutable)**
- 用大括號`{}`來表示，裡面的元素用逗號`,`隔開

## Create a Set
你可以用`#!python set()`來建立一個集合，或者用大括號`{}`，直接看例子:

```python linenums="1"
a = set("FOREVER")
print(a)

b = [4, 8, 4, 3]
c = set(b)
print(c)

d = {(0, 1), (1, 2), (2, 3)}
print(d)
print(type(d))

e = {}
print(type(e))
```

``` linenums="1" title="Output"
{'R', 'F', 'O', 'E', 'V'}
{8, 3, 4}
{(2, 3), (1, 2), (0, 1)}
<class 'set'>
<class 'dict'>
```

[SUHO(수호) _ FOREVER](https://youtu.be/CfpRA2bXZW8?si=mIigqmzrijziYN4i)

你得注意，建立空集合的時候，你必須用`#!python set()`，因為`{}`是用來建立空字典的。

以及所謂的無序，你試著多執行幾次程式，你會發現，每次輸出的結果都不一樣。

你甚至可以用 Comprehension 來建立集合。

```python linenums="1"
a = {1, 2, 3}
b = {3, 4, 5}
diff_b = {x for x in b if x not in a}
print(diff_b)

c = {x ** 2 for x in range(-3, 4)}
print(c)
```

``` linenums="1" title="Output"
{4, 5}
{0, 9, 4, 1}
```

## Operations
### Accessing elements
因為集合是無序的，所以你不能用索引來存取元素，但是你可以用`#!python in`來檢查元素是否存在，以及搭配`#!python for`迴圈來遍歷集合。

```python linenums="1"
perfect_nums_set = {6, 28, 496, 8128, 33550336}
print(4843 in perfect_nums_set)

for num in perfect_nums_set:
    print(num, end=' ')
```

``` linenums="1" title="Output"
False
33550336 8128 496 6 28 
```

!!! question
    對於一個長度為 $n$ 的集合，你認為需要花幾個步驟檢查某一個元素是否存在?

答案可能會讓你驚訝，不需要 $n$ 個步驟，只要幾個步驟就好，可以說是馬上。

### Union
你可以用`#!python |` 或者 `#!python union()` 來取得兩個集合的聯集。

```python linenums="1"
a = {1, 3, 5}
b = {2, 4, 5, 6}

print(a.union(b))
c = a | b
print(c)

a |= b
print(a)
```

``` linenums="1" title="Output"
{1, 2, 3, 4, 5, 6}
{1, 2, 3, 4, 5, 6}
{1, 2, 3, 4, 5, 6}
```

### Intersection
你可以用`#!python &` 或者 `#!python intersection()` 來取得兩個集合的交集。

```python linenums="1"
a = {1, 3, 5}
b = {2, 4, 5, 6}

print(a.intersection(b))
c = a & b
print(c)

a &= b
print(a)
```

``` linenums="1" title="Output"
{5}
{5}
{5}
```

### Difference
你可以用`#!python -` 或者 `#!python difference()` 來取得兩個集合的差集。

```python linenums="1"
a = {1, 3, 5}
b = {2, 4, 5, 6}

print(a.difference(b))
c = b - a
print(c)

a -= b
print(a)
```

``` linenums="1" title="Output"
{1, 3}
{2, 4, 6}
{1, 3}
```

我就舉這三個例子，其他請你自己查 Docs 來學習。

## Methods
### Adding elements
你可以用 `#!python add()` 來新增元素到集合中。

```python linenums="1"
nums_set = {1, 2, 3, 4, 5}
nums_set.add(6)
nums_set.add(3)
print(nums_set)
```

``` linenums="1" title="Output"
{1, 2, 3, 4, 5, 6}
```

也可以用 `#!python update()` 來新增多個元素到集合中。

其實就跟 `|=` 一樣。

```python linenums="1"
nums_set = {1, 2, 3, 4, 5}
nums_set.update({6, 7})
print(nums_set)

nums_set.update([1, 8, 9], {10, 11})
print(nums_set)
```

``` linenums="1" title="Output"
{1, 2, 3, 4, 5, 6, 7}
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
```

### Removing elements
你可以用 `#!python remove()` 來移除集合中的元素，如果元素不存在，會拋出錯誤。

```python linenums="1"
a = {1, 2, 3}
a.remove(1)
print(a)
a.remove(1)
print(a)
```

``` linenums="1" title="Output"
{2, 3}
KeyError: 1
```

或者用 `#!python discard()` 來移除集合中的元素，如果元素不存在，不會拋出錯誤。

```python linenums="1"
a = {1, 2, 3}
a.discard(2)
print(a)
a.discard(2)
print(a)
```

``` linenums="1" title="Output"
{1, 3}
{1, 3}
```

那怎麼清空呢?你可以用 `#!python clear()` 來清空集合。

```python linenums="1"
a = {1, 2, 3}
a.clear()
print(len(a))
```

``` linenums="1" title="Output"
0
```

還有更多的方法，請你自己查 Docs 來學習，但這些目前應該夠你用。

## Practice

!!! success ""
    Itsa - [[C_AR20-易] 檢查數值是否有重複](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=2162)

??? abstract "Reference code"
    ```python linenums="1"

    n = int(input())
    num_set = set(input().split())

    if len(num_set) == n:
        print(1)
    else:
        print(0)
    ```
    檢查有沒有重複的元素，這個問題就很適合用集合來解決，因為集合裡面的元素是唯一的，所以只要檢查集合的長度是否等於輸入串列的長度就好。

## Assignment
在 Itsa 上不太好找題目，所以乾脆附上解答。

!!! success ""
    Itsa - [[C_ST23-易] 相同字集的字串](https://e-tutor.itsa.org.tw/mod/programming/view.php?a=935)

??? abstract "Reference code"
    ```python linenums="1"

    a, b = input().split(',')
    a_set = set(str.lower(a))
    a_set.discard(" ")
    b_set = set(str.lower(b))
    b_set.discard(" ")

    if a_set == b_set:
        print(1)
    else:
        print(0)
    ```
    這裡應該能感受 `discard()` 的用處，題目要求不區分大小寫，所以我們先把字串轉成小寫，然後再把空白字元移除(不管有沒有)，最後再檢查兩個集合是否相等。

@EditTime : 2024-02-06 23:16