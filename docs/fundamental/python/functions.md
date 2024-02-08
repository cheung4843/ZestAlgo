# Functions
## Introduction
往下之前，請你回想 [Repetition Structures - Nested Loop](repetition_structures.md#nested_loop) 中的例子:

輸入一個正整數 $n$，輸出 $[1, n]$ 間的最大質數。

```python linenums="1" hl_lines="4-8"
n = int(input())

for i in range(n, 0, -1):
    is_prime = True
    for j in range(2, i):
        if i % j == 0:
            is_prime = False
            break

    if is_prime:
        print(f"{i} is the largest prime in [1, {n}]")
        break
```

這個程式碼的功能是正確的，但是程式碼的可讀性不高，因為程式碼的長度太長，並且程式碼的邏輯不夠清晰。

我們可以把判斷質數的部分抽出來，並且將他包裝成一個函式:

```python linenums="1" hl_lines="10-13"
def is_prime(x):
    for i in range(2, x):
        if x % i == 0:
            return False
    return True


n = int(input())

for i in range(n, 0, -1):
    if is_prime(i):
        print(f"{i} is the largest prime in [1, {n}]")
        break
```

這樣的好處是，我們可以將相同的程式碼重複使用，並且可以讓程式碼更加簡潔。

那如果我想要進一步程式碼封裝成一個接受正整數 $n$ 的函式，並且回傳 $[1, n]$ 間的最大質數呢?

```python linenums="1"
def is_prime(x):
    for i in range(2, x):
        if x % i == 0:
            return False
    return True


def largest_prime(n):
    for i in range(n, 0, -1):
        if is_prime(i):
            return i


n = int(input())

print(f"{largest_prime(n)} is the largest prime in [1, {n}]")
```

不曉得你有沒有感受到，當程式碼越來越長，我們就越需要函式來幫助我們將程式碼分割成更小的部分，這樣我們就可以更容易的閱讀程式碼。

這個引子告訴我們，函式是一個可以將程式碼包裝成一個獨立的單位，並且可以重複使用的工具。

## Define a Function
函式的定義是以 `#!python def` 開頭，後面接著函式的名稱，以及括號內的**參數(Parameter)**，縮排內的程式碼就是函式的內容。

你可以選擇是否要在函式中加上 `#!python return` 來回傳值，如果沒有，函式則會回傳 `#!python None`。

舉個例子，定義一個函式 `#!python greet`，他接受一個參數 `#!python name`，並印出 `Hello, {name}`:

```python linenums="1" hl_lines="5"
def greet(name):
    print(f"Hello, {name}")


print(greet("World"))
```

```linenums="1" title="Output"
Hello, World
None
```

`greet("World")` 會先印出 `Hello, World`，接著回傳 `None`。

字串 `"World"` 被稱為**引數(Argument)**，而 `name` 則被稱為**參數(Parameter)**。但也不用太拘泥。

再舉個例子，定義一個函式 `#!python freq(x)` 接受一個數字字串 `x` ，回傳 `0-9` 的出現次數，以序對的方式回傳:

```python linenums="1"
def freq(x: str) -> tuple:
    table = [0] * 10
    for digit in x:
        table[int(digit)] += 1

    return tuple(table)


a, b = "114514", "111445"
print(freq(a) == freq(b))
```

```linenums="1" title="Output"
True
```

我們可以在參數後面加上 `#!python :` 來指定參數的型別，並且在函式後面加上 `#!python ->` 來指定回傳值的型別。

### Default Argument Values
有時候我們會希望函式的參數有預設值，這樣在呼叫函式時就不需要填入引數。

例如，函式 `max_of(x, k=1)` 接受兩個參數 `x` 串列與 `k` 數字，回傳 `x` 中最大的 `k` 個數字，以串列的方式回傳，而 `k` 的預設值為 `1`:

```python linenums="1"
def max_of(x: list[int], k=1):
    return sorted(x, reverse=True)[:k]


y = [4, 8, 5, 3, 9]
print(max_of(y))
print(max_of(y, 2))
print(max_of(y, k=3))
```

```linenums="1" title="Output"
[9]
[9, 8]
[9, 8, 5]
```

再舉一個例子，函式 `weight_score(math, english, programming, math_weight=0.25, english_weight=0.25, programming_weight=0.5)` 接受三個參數 `math`, `english`, `programming` 以及三個預設值 `math_weight=0.25`, `english_weight=0.25`, `programming_weight=0.5`，回傳加權分數:

```python linenums="1"
def weight_score(math, english, programming, math_weight=0.25, english_weight=0.25, programming_weight=0.5):
    return math * math_weight + english * english_weight + programming * programming_weight


sean_score = weight_score(80, 90, 100)
yaris_score = weight_score(math=82, math_weight=0.3, english=90, english_weight=0.3, programming=100,
                           programming_weight=0.4)
print(sean_score, yaris_score)
```

```linenums="1" title="Output"
92.5 91.6
```

有預設值的參數必須放在沒有預設值的參數後面。但如果你在呼叫函式的時候，指定了參數的名稱，則可以不用遵守這個規則。

其實還有一些神奇的用法，但就不在這裡討論了。

### Lambda Function
還記得 `map` 嗎? 他可以將一個函式應用到一個串列上。

先回憶一下，我們可以這樣使用 `map`:

```python linenums="1"
def square(x):
    return x ** 2


lst = [1, 2, 3, 4, 5]
print(list(map(square, lst)))

song_name = ["I", "Really", "Want", "to", "Stay", "At", "Your", "House"]
print(list(map(len, song_name)))
```

```linenums="1" title="Output"
[1, 4, 9, 16, 25]
[1, 6, 4, 2, 4, 2, 4, 5]
```

[I Really Want to Stay At Your House” by Rosa Walton](https://youtu.be/KvMY1uzSC1E?si=McX5qpTCm9q4z8hX)

這種接受函式為參數的函式被稱為**高階函式(Higher-Order Function)**。

但是，如果函式只會被使用一次，我們可以使用 `lambda` 來定義一個匿名函式:

```python linenums="1"
lst = [1, 2, 3, 4, 5]
print(list(map(lambda x: x ** 2, lst)))
```

```linenums="1" title="Output"
[1, 4, 9, 16, 25]
```

再舉個例子，用過 `min` 嗎? 他可以找出一個串列中的最小值，我們也可以自訂規則，例如有一個座標串列 `points`，我們可以這樣找出最靠近原點的點:

```python linenums="1"
points = [(9, 2), (3, 4), (5, 6), (7, 8), (4, 8), (1, 3)]
print(min(points, key=lambda x: x[0] ** 2 + x[1] ** 2))
```

```linenums="1" title="Output"
(1, 3)
```

再舉個例子，兩個串列 `a` 與 `b`，我們可以這樣計算兩個串列的內積:

```python linenums="1"
a, b = [1, 2, 3], [4, 5, 6]
print(sum(map(lambda x, y: x * y, a, b)))
```

```linenums="1" title="Output"
32
```

## Factory Function
有時候我們會希望函式回傳另一個函式，這樣的函式被稱為**工廠函式(Factory Function)**。

舉個例子，定義一個函式 `#!python make_power_fun(n)` ，他接受一個數字 `n`，回傳一個函式，這個函式接受一個數字 `x`，回傳 `x` 的 `n` 次方:

```python linenums="1"
def make_power_fun(n):
    return lambda x: x ** n


power_fun_2 = make_power_fun(2)
power_fun_3 = make_power_fun(4)

print(power_fun_2(3))
print(power_fun_3(3))
```

```linenums="1" title="Output"
9
81
```

這樣的好處是，我們可以在不同的地方使用不同的 `n`，而不需要重複定義函式。

## Nested Function
函式可以被定義在另一個函式的內部，這樣的函式被稱為**巢狀函式(Nested Function)**。

例如，函式 `collect_anagrams(words, target)` 接受一個字串串列 `words` 與一個字串 `target`，回傳 `words` 中與互為 `target` 是*相同字母異序詞*的串列:

於是我在函式的內部先定義了一個*輔助函式(Helper Function)* `#!python is_anagram(x, y)`，他接受兩個字串 `x` 與 `y`，回傳 `x` 與 `y` 是否為相同字母異序詞:

```python linenums="1"
def collect_anagrams(words, target):
    def is_anagram(x, y):
        return sorted(x) == sorted(y)

    return [word for word in words if is_anagram(word, target)]


strs = ["now", "won", "own", "no", "on", "www"]
print(collect_anagrams(strs, "onw"))
```

```linenums="1" title="Output"
['now', 'won', 'own']
```

這個在刷 LeeCode 時會常常用到。

## Recursion
來到本章的重頭戲，**遞迴(Recursion)**。

遞迴是一種函式呼叫自己的技巧，這樣的函式被稱為**遞迴函式(Recursive Function)**。

先來個經典的例子，計算 $n!$，迴圈的寫法是這樣的:

```python linenums="1"
def factorial(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result


print(factorial(0))
print(factorial(5))
```

```linenums="1" title="Output"
1
120
```

記得高中數學課本上的定義嗎?

$$
\text{factorial}(n) = \begin{cases} 1 & \text{if } n = 0 \text{, base case}\\ n \times \text{factorial}(n-1) & \text{if } n > 0 \text{, recursive case}\end{cases}
$$

這樣的定義就可以直接翻譯成程式碼:

```python linenums="1"
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)


print(factorial(0))
print(factorial(5))
```

```linenums="1" title="Output"
1
120
```

當 `n == 0` 時，我們稱為*基本情況(Base Case)*，這是遞迴的終止條件，當 `n > 0` 時，我們稱為*遞迴情況(Recursive Case)*，這是遞迴的執行條件。

每一個遞迴函式都應該有一個基本情況，這樣的遞迴才會終止，否則就會陷入無窮遞迴，咦?有沒有很熟悉?還記得無窮迴圈嗎?

再舉個例子，計算費氏數列的第 $n$ 項，迴圈的寫法是這樣的:

```python linenums="1"
def fibonacci(n):
    a, b = 0, 1
    for _ in range(n):
        a, b = b, a + b
    return a


print(fibonacci(0))
print(fibonacci(10))
```

```linenums="1" title="Output"
0
55
```

同樣的，還記得高中數學課本上的定義嗎?

$$
\text{fibonacci}(n) = \begin{cases} 0 & \text{if } n = 0 \text{, base case}\\ 1 & \text{if } n = 1 \text{, base case}\\ \text{fibonacci}(n-1) + \text{fibonacci}(n-2) & \text{if } n > 1 \text{, recursive case}\end{cases}
$$

這樣的定義就可以直接翻譯成程式碼:

```python linenums="1"
def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


print(fibonacci(0))
print(fibonacci(10))
```

```linenums="1" title="Output"
0
55
```

但是，遞迴的效率通常比迴圈低，因為遞迴會造成大量的函式呼叫，而且容易造成大量的重複計算。

再來一個經典的例子，計算整數 `a, b` 的最大公因數，你可能有聽過輾轉相除法，又稱為**歐幾里得演算法(Euclidean algorithm)**，他的定義是這樣的:

$$
\text{gcd}(a, b) = \begin{cases} a & \text{if } b = 0 \text{, base case}\\ \text{gcd}(b, a \mod b) & \text{if } b > 0 \text{, recursive case}\end{cases}
$$

直接寫成程式碼:

```python linenums="1"
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


print(gcd(12, 18))
print(gcd(18, 12))
print(gcd(4843, 1234))
```

```linenums="1" title="Output"
6
6
1
```

這個要寫成**迭代(Iterative)**版本還比較難。

關於遞迴，就先講到這裡，未來進入演算法的章節時，會再深入討論，而且會有更多的例子。

## Practice
!!! success ""
    Itsa - [[C_MM48-易] F91](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=6976)

??? abstract "Reference code"
    ```python linenums="1"

    def f91(n):
        if n <= 100:
            return f91(f91(n + 11))
        elif n >= 101:
            return n - 10


    k = int(input())
    n = list(map(int, input().split()))
    for x in n:
        print(f91(x))
    ```

    你仔細觀察一下，其實可以寫成這樣:

    ```python linenums="1"

    def f91(z): 
        if z >= 101: 
            return z - 10 
        else: 
            return 91 
    
    
    k = int(input()) 
    n = list(map(int, input().split())) 
    for x in n: 
        print(f91(x)) 
    ```

!!! success ""
    Itsa - [[C_RU13-易] 大一點的Fibonacci](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=13606)

??? abstract "Reference code"
    ```python linenums="1"

    MAX = 47
    fibonacci = [0] * MAX
    fibonacci[1] = 1

    for i in range(2, MAX):
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2]

    while True:
        n = int(input())
        if n == -1:
            break
        print(fibonacci[n + 1])

    ```
    這種寫法叫做**動態規劃(Dynamic Programming)**，未來會再討論，而且會很頭痛。

## Assignment
!!! success ""
    Itsa - [[C_MM103-易] 費式數列](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=2654)

!!! success ""
    Itsa - [[C_MM143-易] 求Emirp](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=3589)

!!! success ""
    Itsa - [[C_MM144-易] 求組合數C(n,r)](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=3626)

!!! success ""
    Itsa - [題目10. 輾轉相除法](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=30757)

!!! success ""
    Itsa - [[C_RU10-中] 爬樓梯](https://e-tutor.itsa.org.tw/mod/programming/view.php?a=3552)

!!! success ""
    Itsa - [[C_RU14-易] 好高的水晶塔](https://e-tutor.itsa.org.tw/mod/programming/view.php?a=6422)

!!! success ""
    Itsa - [[C_RU23-易] 遞迴練習2f(n)=f(n-1)+2](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=29334)

!!! success ""
    Itsa - [[C_RU24-易] 遞迴練習f(n)＝2f(n-1)/(1+2f(n-1))](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=29335)

!!! success ""
    Itsa - [[C_RU25-易] 遞迴練習f(n)＝3f(n-1)+g(n-1)﹐g(n)＝-f(n-1)+g(n-1)](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=29336)