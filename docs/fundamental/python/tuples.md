# Tuples
## Introduction
有了上一章的基礎後，我相信**序對(Tuple)**對你來說不會困難，因為它跟**串列(List)**很像，只是它是用小括號`()`來表示，而且它是**不可變的(immutable)**。這表示你不能新增、刪除或修改裡面的元素。那既然如此，為什麼還要用它呢?

## Create a Tuple
要建立一個序對有很多種方法，最簡單的就是用小括號`()`把元素包起來，用逗號`,`隔開就好了。

但在下面的例子中，你會發現，只有一個元素時，你必須在後面加上逗號。這邊你自己試試看，應該都能理解。

```python linenums="1"
empty = ()
one = (1,)
two = (1, 2)
print(len(empty), len(one), len(two))
print(type(empty))

odd = 1, 3, 5
print(odd)
print(type(odd))
```

``` linenums="1" title="Output"
0 1 2
<class 'tuple'>
(1, 3, 5)
(1, 3, 5)
<class 'tuple'>
```

你也可以用`#!python tuple()`來建立一個序對，直接看例子:

```python linenums="1"
lst = [1, 2, 3, 4, 5]
tup = tuple(lst)
print(tup)

s = "know me..."
s_tup = tuple(s)
print(s_tup)
```

``` linenums="1" title="Output"
(1, 2, 3, 4, 5)
('k', 'n', 'o', 'w', ' ', 'm', 'e', '.', '.', '.')
```

[八木海莉 『know me...』](https://youtu.be/h5SoI5l7oYs?si=9u0QnORGTjOl-Kw4)

還記得 [List Comprehension](lists.md#list-comprehension) 嗎?我們將中括號改成小括號試試看:

```python linenums="1"
gen = (x ** 2 for x in range(5))
print(type(gen))
tup = tuple(gen)
print(tup)
```

``` linenums="1" title="Output"
<class 'generator'>
(0, 1, 4, 9, 16)
```

你會發現，結果並非是你預期的序對，而是**產生器(Generator)**，你還需要使用`#!python tuple()`來轉換。

至於為什麼要用**產生器(Generator)**，我會在未來的章節跟你說明，又挖坑了。

那麼加法跟乘法呢?跟**串列(List)**一樣，你可以用加法來合併兩個序對，用乘法來複製序對。

```python linenums="1"
a = (1, 2, 3)
b = 4, 5, 6
c = a + b
print(c)

d = a * 2 + b
print(d)
```

``` linenums="1" title="Output"
(1, 2, 3, 4, 5, 6)
(1, 2, 3, 1, 2, 3, 4, 5, 6)
```

## Operations
### Accessing elements
跟**串列(List)**一樣，你可以用索引來存取序對中的元素，也可以用負索引來從後存取。

```python linenums="1"
t = (1, 2, 3, 4, 5)
print(t[0], t[-1])
```

``` linenums="1" title="Output"
1 5
```

### Slicing
同樣的，你也可以用切片來取得序對中的子序對。

```python linenums="1"
t = (1, 2, 3, 4, 5)
print(t[1:3])
print(t[:3])
print(t[3:])
print(t[:])
```

``` linenums="1" title="Output"
(2, 3)
(1, 2, 3)
(4, 5)
(1, 2, 3, 4, 5)
```

### Modifying elements
但是你不能修改序對中的元素，這是**不可變的(immutable)**，是有折衷的方法啦，就是把序對轉換成串列，再轉換回來。

```python linenums="1" hl_lines="8"
cat_tup = ("😸", "😺", "😻", ["😿", "🙀"])

cat_lst = list(cat_tup)
cat_lst[1] = "😼"
cat_tup = tuple(cat_lst)
print(cat_tup)

cat_tup[3][0] = "😾"
print(cat_tup)

cat_tup[1] = "😽"
print(cat_tup)
```

``` linenums="1" title="Output"
('😸', '😼', '😻', ['😿', '🙀'])
('😸', '😼', '😻', ['😾', '🙀'])
TypeError: 'tuple' object does not support item assignment
```

但你有沒有覺得怪怪的，為什麼我可以修改序對中的串列呢?

### Checking elements
你可以用 `#!python in` 來檢查元素是否在序對中，這跟串列是一樣的。

```python linenums="1"
fib = (0, 1, 1, 2, 3, 5, 8)
print(0 not in fib)
print(5 in fib)
```

``` linenums="1" title="Output"
False
True
```

!!! question
    對於長度為 $n$ 的無序序對，要檢查某個元素是否存在於序對中，最好的情況下，需要檢查多少次?

又是熟悉的問題，你可以的。

## Methods
因為序對是**不可變的(immutable)**，所以只有兩個方法，一個是`#!python count()`，一個是`#!python index()`，你可以自己試試看。

### count
`#!python count()` 會回傳括號內的元素在序對中出現的次數，當然 List 也有這個方法，但前面我並沒有提，因為可以放在這裡水內容(X

```python linenums="1"
t = ((1, 2), (3, 4), 6, 6, [7, 8])
print(t.count(1))
print(t.count([7, 8]))
print(t.count(6))
```

``` linenums="1" title="Output"
0
1
2
```

### index
`#!python index()` 會回傳括號內的元素在序對中的索引，一樣的，List 也有這個方法。

```python linenums="1"
t = ("Love Me Again", "John Newman", 2013)
print(t.index("John Newman"))
print(t.index(2014))
```

``` linenums="1" title="Output"
1
ValueError: tuple.index(x): x not in tuple
```

[John Newman - Love Me Again](https://youtu.be/CfihYWRWRTQ?si=5Hw30F-5g6N8lrnA)

## Tuple vs List
- List
    - 用中括號`[]`表示
    - 可變的(mutable)
    - 不可雜湊(unhashable)
    - 效能較差
    - 適用於頻繁的增刪改
- Tuple
    - 用小括號`()`表示
    - 不可變的(immutable)
    - 可雜湊(hashable)
    - 效能較好
    - 適用於不需要變動的資料，例如常數、座標

關於**「可雜湊的(hashable)」**，我會在**字典(Dict)**這章中跟你說明。

## Practice
!!! success ""
    Itsa - [[C_AR04-易] 邊緣偵測](https://e-tutor.itsa.org.tw/mod/programming/view.php?a=939)

??? abstract "Reference code"
    ```python linenums="1"

    N = int(input())

    dirs = ((0, 1), (0, -1), (1, 0), (-1, 0))

    for k in range(N):
        n, m = map(int, input().split())
        pic = []
        for _ in range(n):
            pic.append(input().split())

        for i in range(n):
            for j in range(m):
                if pic[i][j] == '0':
                    print('_ ', end='')
                else:
                    is_edge = False
                    for d in dirs:
                        x, y = i + d[0], j + d[1]
                        if 0 <= x < n and 0 <= y < m and pic[x][y] == '0':
                            is_edge = True
                            break
                    if is_edge:
                        print('0 ', end='')
                    else:
                        print('_ ', end='')
            print()

        if k != N - 1:
            print()

    ```
    方向 `dirs` 就很適用序對來表示，因為它是固定的，不會變動。

    未來在學圖形走訪的時候，你會一直看到這種寫法。

## Assignment

!!! success ""
    Itsa - [[C_AR119-易] 地雷危險指數表](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=20743)

!!! success ""
    Itsa - [[C_AR139-易] 黃金探測](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=22874)

!!! success ""
    Itsa - [[C-AR140-易] 求最大糧食產量](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=23930)

@EditTime : 2024-02-04 21:15