# Lists
## Introduction
不曉得你看到這裡有沒有發現，我們在前面的章節中，都是用一個一個的變數來儲存資料，但是如果我們要儲存很多筆資料，這樣的方式就會變得很麻煩。

所以這裡跟你介紹 **List(串列)**，它可以讓我們儲存很多筆資料，而且可以儲存不同的資料型態，例如: 數字、字串、布林值等等。

## Create a list
要建立一個 List，我們可以使用中括號 `[]`，並在中括號中放入我們要儲存的資料，資料之間用逗號 `,` 隔開。

來舉個例子，建立三個 List，一個都儲存整數，一個是都儲存字串；最後一個則放了不同的資料型態。

```python linenums="1"
numbers = [1, 2, 3, 4, 5]
print(numbers)

what_i_learned = ["C", "C++", "Python", "Java", "C#", "JavaScript", "TypeScript"]
print(what_i_learned)

student_info = ["Sean", 20, "Computer Science", 4.0, True, "aLIEz"]
print(student_info)

print(type(numbers), type(what_i_learned), type(student_info))
```

```linenums="1" title="ouput"
[1, 2, 3, 4, 5]
['C', 'C++', 'Python', 'Java', 'C#', 'JavaScript', 'TypeScript']
['Sean', 20, 'Computer Science', 4.0, True, 'aLIEz']
<class 'list'> <class 'list'> <class 'list'>
```

[Sawano Hiroyuki - aLIEz Aldnoah.Zero Full Lyrics](https://youtu.be/wtW529XbOyU?si=Es6dUQAervDKUzag)

如果你有學過其他的程式語言，你可能會聽過 **Array(陣列)**，List 就是 Python 中的 Array，但又更強大，因為 List 可以儲存不同的資料型態，而通常 Array 只能儲存一種資料型態。

但 Python 也有提供真正的「陣列」，但我先不提，請你稍微有個印象就好。

題外話，當初從 C, C++, Java 轉到 Python 的時候，真心覺得怎麼可以這麼隨便，連型態都不用宣告，現在覺得真香。

不曉得你還記不記得，我們在前面的章節中，有提到 `#!python range` 這個函式，它可以產生一個整數的序列，例如: `range(5)` 會產生一個從 $0$ 到 $4$ 的整數序列。

`list(range(5))` 這樣就可以將 `range` 物件轉換成 List。

```python linenums="1"
x = range(5)
print(type(x))
numbers = list(x)
print(numbers)
```

```linenums="1" title="ouput"
<class 'range'>
[0, 1, 2, 3, 4]
```

那能否把字串轉換成 List 呢? 當然可以!

```python linenums="1"
x = "Signals"
print(type(x))
words = list(x)
print(words)
```

```linenums="1" title="ouput"
<class 'str'>
['S', 'i', 'g', 'n', 'a', 'l', 's']
```

[Lazer Boomerang - Signals (Official Audio)](https://youtu.be/MNtpV6_EDJg?si=IgVcBpHqsZq7-cU4)

再來看一個例子，如何初始化一個元素都是 $0$ 的串列。

```python linenums="1"
n = 5
zeros = [0] * n
print(zeros)
```

```linenums="1" title="ouput"
[0, 0, 0, 0, 0]
```

如何將兩個串列合併成一個串列呢?

```python linenums="1"
a = [1, 2, 3]
b = [4, 5, 6]
c = a + b
print(c)
```

```linenums="1" title="ouput"
[1, 2, 3, 4, 5, 6]
```

還有一個方法，就是使用 `#!python extend` 這個方法，這在後面會介紹到。

我相信以上這些例子能讓你抓到一些概念，接下來將介紹一系列的操作與方法，讓你更熟悉 List。


## Operations
### Accessing elements
要存取 List 中的元素，我們可以使用中括號 `[]`，並在中括號中放入元素的索引值，索引值從 $0$ 開始，並且可以使用負數，負數的索引值是從最後一個元素開始算起。

```python linenums="1"
numbers = [1, 2, 3, 4, 5]

# First element
print(numbers[0])
# Last element
print(numbers[-1])
print(numbers[4])
```

```linenums="1" title="ouput"
1
5
5
```

讓我們配合迴圈來印出串列中的元素。

```python linenums="1"
numbers = [1, 2, 3, 4, 5]

for i in range(len(numbers)):
    print(numbers[i], end=' ')

```

```linenums="1" title="ouput"
1 2 3 4 5
```

`#!python len` 這個函式可以取得串列的長度，也就是串列中元素的個數。

不曉得你還記不記得 [Repetiton Structures - Foreach](repetition_structures.md#foreach) 的內容，我們用這個概念來印出串列中的元素。

```python linenums="1"
numbers = [1, 2, 3, 4, 5]

for number in numbers:
    print(number, end=' ')
```

```linenums="1" title="ouput"
1 2 3 4 5
```

### Slicing
**切片(Slicing)**可以用來取得串列中的一部分，例如:

```python linenums="1"
numbers = [1, 2, 3, 4, 5, 6]

print(numbers[0:4])
print(numbers[:4])
print(numbers[:-2])
print(numbers[1:3])
print(numbers[:6:2])
print(numbers[::-1])
print(numbers[:])
```

```linenums="1" title="ouput"
[1, 2, 3, 4]
[1, 2, 3, 4]
[1, 2, 3, 4]
[2, 3]
[1, 3, 5]
[6, 5, 4, 3, 2, 1]
[1, 2, 3, 4, 5, 6]
```

@EditTime : 2024-01-31 21:56

你很聰明，應該發現了用法與 `#!python range` 一樣，分別是起始索引值、結束索引值、間隔，如果不寫的話，預設值分別是 $0$、串列長度、$1$。

### Modifying elements
要修改串列中的元素，我們可以使用中括號 `[]`，並在中括號中放入元素的索引值，然後再指定新的值。

```python linenums="1"
music_info = ["Time_To_Pretend", "Lazer Boomerang", " 2019/4/26", 1, False]
music_info[0] = "Time To Pretend"
music_info[3] = 2
music_info[-1] = True
print(music_info)
```

```linenums="1" title="ouput"
['Time To Pretend', 'Lazer Boomerang', ' 2019/4/26', 2, True]
```

[Lazer Boomerang - Time To Pretend (Official Audio)](https://youtu.be/IXisGwqkJPo?si=QcUtwDoFKqJxyJ0E)

我們可以修改串列中的值，這稱為 **可變動的(mutable)**，而字串則不行，這稱為 **不可變動的(immutable)**。

```python linenums="1"
sad_cat = "😿"
sad_cat[0] = "😸"
```

```linenums="1" title="ouput"
TypeError: 'str' object does not support item assignment
```

## Methods
來介紹一些常用的串列方法。

### append
`#!python append` 這個方法可以在串列的最後面新增一個元素。

```python linenums="1" hl_lines="4"
numbers = [1, 2, 3, 4, 5]
numbers.append(6)
print(numbers)
numbers.append([7, 8, 9])
print(numbers)
```

```linenums="1" title="ouput"
[1, 2, 3, 4, 5, 6]
[1, 2, 3, 4, 5, 6, [7, 8, 9]]
```

希望第二個 `append` 沒有嚇到你，它可以新增一個串列，但是這個串列會變成串列中的一個元素。如果你是想要把 `7`、`8`、`9` 這三個元素加到串列中，你可以使用 `#!python extend` 這個方法。

### extend
`#!python extend` 這個方法可以在串列的最後面新增另一個串列中的元素。

```python linenums="1" hl_lines="2"
numbers = [1, 2, 3, 4, 5]
numbers.extend([6, 7, 8])
print(numbers)
```

```linenums="1" title="ouput"
[1, 2, 3, 4, 5, 6, 7, 8]
```

### pop
`#!python pop` 這個方法可以移除串列中的元素，並回傳被移除的元素。

```python linenums="1" 
fruits = ["apple", "banana", "cherry", "durian", "elderberry"]
print(fruits.pop())
print(fruits)
print(fruits.pop(1))
print(fruits)
```

```linenums="1" title="ouput"
elderberry
['apple', 'banana', 'cherry', 'durian']
banana
['apple', 'cherry', 'durian']
```

通常，我們會使用 `#!python pop` 來移除串列中的最後一個元素，因為這樣可以避免索引值超出範圍的錯誤，你也可以指定索引值，來移除串列中的元素，但不建議。

### clear
`#!python clear` 這個方法可以移除串列中的所有元素。

```python linenums="1"
numbers = [1, 2, 3, 4, 5]
numbers.clear()
print(numbers)
```

```linenums="1" title="ouput"
[]
```

### reverse
`#!python reverse` 這個方法可以反轉串列。

```python linenums="1"
numbers = [1, 2, 3, 4, 5]
numbers.reverse()
print(numbers)
```

```linenums="1" title="ouput"
[5, 4, 3, 2, 1]
```

### sort
`#!python sort` 這個方法可以排序串列，預設是由小到大排序，如果要由大到小排序，可以指定 `reverse=True`。

```python linenums="1"
numbers = [5, 4, 3, 2, 1]
numbers.sort()
print(numbers)
numbers.sort(reverse=True)
print(numbers)
```

```linenums="1" title="ouput"
[1, 2, 3, 4, 5]
[5, 4, 3, 2, 1]
```

甚至你可以設定 `key`，來決定排序的依據，例如: `key=len`，就是根據元素 `x` 的 `#!python len(x)` 來排序。

```python linenums="1"
fruits = ["apple", "banana", "watermelon", "pineapple"]
fruits.sort(key=len)
print(fruits)
```

```linenums="1" title="ouput"
['apple', 'banana', 'pineapple', 'watermelon']
```

### copy
`#!python copy` 這個方法回傳一個*淺複製(Shallow Copy)*的串列。

```python linenums="1" hl_lines="8"
numbers = [1, 2, 3, 4, 5]
numbers_copy = numbers.copy()
print(numbers_copy)
print(numbers)

print("After changing numbers[1]")

numbers[1] = 10
print(numbers_copy)
print(numbers)
```

```linenums="1" title="ouput"
[1, 2, 3, 4, 5]
[1, 2, 3, 4, 5]
After changing numbers[1]
[1, 2, 3, 4, 5]
[1, 10, 3, 4, 5]
```

這個例子還不能看出淺複製，修改了 `numbers` 的第二個元素，`numbers_copy` 不會跟著改變。

```python linenums="1" hl_lines="8"
numbers = [1, [2, 3], 4, 5]
numbers_copy = numbers.copy()
print(numbers_copy)
print(numbers)

print("After changing numbers[1]")

numbers[1][0] = 6
print(numbers_copy)
print(numbers)
```

```linenums="1" title="ouput"
[1, [2, 3], 4, 5]
[1, [2, 3], 4, 5]
After changing numbers[1]
[1, [6, 3], 4, 5]
[1, [6, 3], 4, 5]
```

那什麼又是*深複製(Deep Copy)*呢? 這個就要等到我們學到**物件導向程式設計(Object-Oriented Programming)**的時候，再來跟你介紹，我不應該挖坑的。

還有更多方法，你可以參考 [Python Documentation - List](https://docs.python.org/3/tutorial/datastructures.html#more-on-lists)，但我上面介紹的方法，你至少要會，你也要養成看官方文件的習慣。

## List Comprehension
**串列綜合運算(List comprehension)**讓你用一行程式碼，就可以建立出擁有某項性質元素的串列。

舉個例子，輸入一個串列 `a`，輸出一個串列 `b`，其中 `b[i] = a[i] ** 2`，也就是 `b` 中的元素都是對應 `a` 元素的平方。

我們先使用迴圈來實作:

```python linenums="1"
a = [1, 2, 3, 4, 5]
b = []

for num in a:
    b.append(num ** 2)

print(b)
```

```linenums="1" title="ouput"
[1, 4, 9, 16, 25]
```

再來使用串列綜合運算:

```python linenums="1"
a = [1, 2, 3, 4, 5]
b = [num ** 2 for num in a]

print(b)
```

```linenums="1" title="ouput"
[1, 4, 9, 16, 25]
```

非常地優雅，我們再來看一個例子，輸入一個串列 `a`，輸出一個串列 `b`，其中 `b` 的元素都是 `a` 元素中的偶數。

```python linenums="1"
a = [1, 2, 3, 4, 5]
b = [num for num in a if num % 2 == 0]

print(b)
```

```linenums="1" title="ouput"
[2, 4]
```

還記得 [Operators - Bonus: map for input](operators.md#bonus_map_for_input) 提到的 `#!python map` 嗎?

先來複習一下，`#!python map` 可以將一個函式套用到一個序列的每一個元素，並回傳一個 `map` 物件，我們可以使用 `#!python list` 將 `#!python map` 物件轉換成串列。

```python linenums="1"
a = ["1", "2", "3", "4", "5"]
b = map(int, a)
print(type(b))

c = list(b)
print(c)
```

```linenums="1" title="ouput"
<class 'map'>
[1, 2, 3, 4, 5]
```

@EditTime : 2024-02-01 23:21

那能不能用串列綜合運算來實作呢?

```python linenums="1"
a = ["1", "2", "3", "4", "5"]
b = [int(num) for num in a]
print(b)
```

```linenums="1" title="ouput"
[1, 2, 3, 4, 5]
```

答案是肯定的。

還有很多應用，例如: 串列中的元素都是小寫，我們想要把它們轉換成大寫。

```python linenums="1"
lowercase = ["a", "b", "c", "d", "e"]
uppercase = [letter.upper() for letter in lowercase]
print(uppercase)
```

```linenums="1" title="ouput"
['A', 'B', 'C', 'D', 'E']
```

注意囉，這邊用到的是方法喔。

## Nested Lists
**巢狀串列(Nested Lists)**，就是串列中的元素也是串列。

### 2D 
先來舉一個你可能聽過的名詞，**二維陣列(2D Array)**，我們可以使用巢狀串列來實作二維陣列，例如兩個 $3 \times 3$ 的二維陣列，來進行矩陣加法。

```python linenums="1"
matrix_1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
matrix_2 = [[9, 8, 7], [6, 5, 4], [3, 2, 1]]

matrix_3 = [[0 for i in range(3)] for j in range(3)]

for i in range(3):
    for j in range(3):
        matrix_3[i][j] = matrix_1[i][j] + matrix_2[i][j]

print(matrix_3)
```

```linenums="1" title="ouput"
[[10, 10, 10], [10, 10, 10], [10, 10, 10]]
```

我希望 `matrix_3` 的初始化沒有嚇到你，請你把 `[0 for i in range(3)]` 當成一個整體 `E`，再把 `[E for j in range(3)]` 當成一個整體，這樣就不會覺得很複雜了，`i, j` 都只是計數用的而已，不要被它們嚇到。

### Jagged
**鋸齒狀串列(Jagged Lists)**，就是允許巢狀串列中的元素的長度不一樣。

題外話，之前在學 C 的時候，只能用*指標*來實作，但用起來真的很麻煩。

```python linenums="1"
jagged = [[1, 2, 3], [4, 5], [6, 7, 8, 9]]

for row in jagged:
    for elem in row:
        print(elem, end=' ')
    print()
```

```linenums="1" title="ouput"
1 2 3 
4 5 
6 7 8 9 
```

希望這個迴圈的寫法不會嚇到你，`row` 是 `jagged` 中的一個元素，也就是一個串列，`elem` 是 `row` 中的一個元素，也就是一個整數。

Python 的語法真的很靈活，但也要很小心，他提供了很多工具，但如果你不清楚他是怎麼運作的，就會容易會寫出效率低下的程式碼，這也是雙面刃，所以要多多練習，多多思考，你可以的。

## Practice
!!! success ""
    Itsa - [[C_MM33-易] 找1~N的完美數](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6943)


??? abstract "Reference code"
    ```python linenums="1"

    table = []
    for i in range(6, 2 ** 13, 2):
        s = 0
        for j in range(1, i):
            if i % j == 0:
                s += j
        if s == i:
            table.append(i)

    while True:
        N = int(input())
        print(' '.join([str(x) for x in table if x <= N]))
    ```
    建立一個串列 `table`，裡面放了 $6$ 到 $2^{13}$ 之間的完美數，接著輸入一個整數 $N$，輸出 $1$ 到 $N$ 之間的完美數。

    那麼 $2^{13}$ 是怎麼來的?ㄜ，我刷後台測資推敲來的。

    `join` 方法可以將字串串列中的元素用指定的字串連接起來，這邊用空白字串 `' '` 來連接。

    這種技巧稱為「建表」，事實上完美數很疏散，你甚至可以自己建完表後直接寫死，但這樣的話，程式碼就不具有通用性。

    ```python linenums="1"
    table = [6, 28, 496, 8128]

    N = int(input())
    print(' '.join(str(x) for x in table if x <= N))
    ```

    如果就單純解題的話，這樣也是可以的。
    
    正規的題目都會規範測資範圍，如果你以後上大學後遇到不太靈光的助教沒有標測資範圍，記得電死他們。

!!! success ""
    Itsa - [[C_MM44-易] The Numbers](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6965)

??? abstract "Reference code"
    ```python linenums="1"

    N, M = input().split()

    cnt = 0
    for i in range(0, 6):
        if M[i] == N[0] and M[i + 1] == N[1]:
            cnt += 1

    print(cnt)
    ```

    字串也可以像是串列一樣，使用索引值來存取元素。

!!! success ""
    Itsa - [[C_AR01-易] 一維陣列反轉 I](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?a=274)

??? abstract "Reference code"
    ```python linenums="1"
    arr = input().split()
    print(' '.join(arr[::-1]))
    ```

    `arr.reverse()` 也行，但是這樣會改變原本的串列，如果你不想改變原本的串列，就使用 `arr[::-1]`。

    ```python linenums="1"
    arr = input().split()
    arr.reverse()
    print(' '.join(arr))
    ```

!!! success ""
    Itsa - [[C_AR03-易] 計算陣列中所有元素的立方和](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1291)

??? abstract "Reference code"
    ```python linenums="1"
    arr = map(int, input().split())
    ans = 0

    for num in arr:
        ans += num ** 3

    print(ans)
    ```

    我並沒有把 `map` 物件轉換成串列，因為我只需要一次迭代，所以直接用 `map` 物件就好。

    來看一行解: 
    ```python linenums="1"
    print(sum(int(x) ** 3 for x in input().split()))
    ```

    參考就好。

!!! success ""
    Itsa - [[C_AR09-易] 兩數差值](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1906)

??? abstract "Reference code"
    ```python linenums="1"
    arr1 = list(map(int, input().split(',')))
    arr1.sort()
    arr2 = arr1.copy()
    arr2.sort(reverse=True)

    max_num,min_num  = 0, 0
    for i in range(len(arr1) - 1, -1, -1):
        # convert list to number
        max_num = max_num * 10 + arr1[i]
        min_num = min_num * 10 + arr2[i]

    print(max_num - min_num)
    ```

    不懂排序沒關係，我們先知道怎麼用就好，以後我會教你原理。

    而這題的重點是，如何將串列轉換成數字。從個位數開始，每次乘 $10$，再加上下一個數字。

!!! success ""
    Itsa - [[C_AR022-易] 字母出現的頻率](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=2200)

??? abstract "Reference code"
    ```python linenums="1"
    string = input()

    freq = [0] * 26

    for c in string:
        if c.isalpha():
            freq[ord(c.lower()) - ord('a')] += 1

    print(' '.join(str(x) for x in freq))
    ```

    這題需要一個先備知識，**[ASCII 碼](https://zh.wikipedia.org/zh-tw/ASCII)**，`#!python ord` 函式可以取得字元的 ASCII 碼。

    再利用 `isalpha` 方法，來判斷字元是否為字母，以及 `lower` 方法，來將字母轉換成小寫，這樣就可以將字母*映射*到 `0` 到 `25` 之間。

    關於字串的主題，後面會再跟你介紹。

!!! success ""
    Itsa - [[C_AR025-易] 計算ASCII字元](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=2435)

??? abstract "Reference code"
    ```python linenums="1"
    string = input()

    freq = [0] * 128


    for i in range(len(string)):
        freq[ord(string[i])] += 1

    for i in range(len(freq) - 1, -1, -1):
        if freq[i] > 0:
            print(f'{i} {freq[i]}')
    ```

    這題跟上一題很像。

!!! success ""
    Itsa - [[C_AR029-難] 文字編碼](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?a=1219)

??? abstract "Reference code"
    ```python linenums="1"

    plain_text = input()

    N = len(plain_text)
    M = 1
    while M * M < N:
        M += 1

    arr = [[' ' for _ in range(M)] for _ in range(M)]

    for i in range(N):
        arr[i // M][i % M] = plain_text[i]

    cipher_text = []
    for i in range(M):
        for j in range(M):
            cipher_text.append(arr[j][i])

    print(''.join(cipher_text))
    ```

    矩陣轉置，所以 `arr[j][i]` 變成 `arr[i][j]`。

## Assignment
!!! success ""
    Itsa - [[C_MM42-中] 求(-1)^(n+1)x[1/(2n-1)]的和](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6961)

!!! success ""
    Itsa - [[C_AR02-易] 一維陣列反轉 II](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1289)

!!! success ""
    Itsa - [[C_AR10-中] 新通話費率](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=1912)

!!! success ""
    Itsa - [[C_AR021-易] 成績統計](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=2196)

!!! success ""
    Itsa - [[C_AR023-易] 字根與子字串](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=2203)

!!! success ""
    Itsa - [[C_AR031-中] 一維矩陣表示二維平面空間](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=2606)

!!! success ""
    Itsa - [[C_AR33-易] 轉置矩陣](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=2634)

!!! success ""
    Itsa - [[C_AR34-易] 身分證驗證器](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=2638)

!!! success ""
    Itsa - [[C_AR35-易] 生肖問題](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?a=1280)

!!! success ""
    Itsa - [[C_AR41-易] 一整數序列所含之整數個數及平均值](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?a=1433)

!!! success ""
    Itsa - [[C_AR46-易] 陣列平方和問題](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=3071)

!!! success ""
    Itsa - [[C_AR48-易] 數字加密](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?a=1447)

@EditTime : 2024-02-03 21:30