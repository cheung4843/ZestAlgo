# Selection Structures
## if ... elif ... else

在往下之前，請你先回想 [Operators - Comparison Operators](operators.md#comparison_operators) 的內容，我們可以透過比較運算子來得到一個布林值，而 `if` 會根據 `True` 或 `False` 來決定是否執行某段程式碼。

我們先來看一個簡單的例子:

我們輸入一個整數，輸出他的絕對值。

```python linenums="1"
num = int(input("Enter a number: "))

# get the absolute value of the input
if num < 0:
    num = -num

print(num)
```

```linenums="1" title="input"
-1984
1984
```

```linenums="1" title="ouput"
1984
1984
```

[Ivan Torrent - "1984" Lyrics Video](https://youtu.be/7bFFh0eLGcw?si=fTcmrjxLb0vwTBM5)

邏輯很簡單，如果輸入的數字小於零，那麼就將他放上負號。提醒你一下，這裡的 `-` 與 `not` 一樣，都是一元運算子，

在這個例子中，我們只有用到 `if`，接著我們有請 `else` 登場。

請看下一個例子，輸入一個整數，判斷他是奇數還是偶數。

```python linenums="1"
num = int(input("Enter a number: "))

# odd or even
if num % 2 == 0:
    print("Even")
else:
    print("Odd")
```

```linenums="1" title="input"
1983
-1982
```

```linenums="1" title="ouput"
Odd
Even
```

[Timecop1983 - On the Run](https://youtu.be/_Ci0Kgdpgsw?si=DSQuzI2etcWkh6Wu)

這裡我們用到了 `else`，當 `if` 的條件不成立時，就會執行 `else` 的內容。

我們再來看更複雜的例子，輸入你的分數，輸出你的評價，因為有很多種評價，所以需要用到 `elif`。

當 `if` 的條件不成立時，就會檢查下面 `elif` 的條件，如果 `elif` 的條件成立，就會執行 `elif` 的內容，如果目前的 `elif` 的條件不成立，就會檢查下一個 `elif` 的條件，如果所有的 `elif` 的條件都不成立，就會執行 `else` 的內容。

這樣講或許有點繞口，你可以看看下面的程式碼，應該就能理解了。

```python linenums="1"
score = int(input("Enter your score: "))

if score >= 90:
    print("A")
    print("Excellent!")
elif score >= 80:
    print("B")
elif score >= 70:
    print("C")
elif score >= 60:
    print("D")
else:
    print("F")
```

```linenums="1" title="input"
60
90
49
```

```linenums="1" title="ouput"
D
A
Excellent!
F
```

接下來給你一個可能會疑惑的例子: 

```python linenums="1"
score = int(input("Enter your score: "))
if score >= 60:
    print("D")
elif score >= 70:
    print("C")
elif score >= 80:
    print("B")
elif score >= 90:
    print("A")
    print("Excellent!")
else:
    print("F")
```

```linenums="1" title="input"
90
```

```linenums="1" title="ouput"
D
```

你可能會覺得奇怪，為什麼輸入 `90` 會印出 `D`，而不是 `A`，這是因為 `if` 的條件成立時，就會執行 `if` 的內容，就不會檢查 `elif` 的條件了。

所以，你在撰寫條件式的時候，要注意順序，以及確保每個條件是否是*互斥*的。

```python linenums="1"
score = int(input("Enter your score: "))

if 70 > score >= 60:
    print("D")
elif 80 > score >= 70:
    print("C")
elif 90 > score >= 80:
    print("B")
elif 100 >= score >= 90:
    print("A")
    print("Excellent!")
else:
    print("F")
```

```linenums="1" title="input"
90
4843
55
```

```linenums="1" title="ouput"
A
Excellent!
F
F
```

這樣就不會有問題了，但是，當我輸入超過 `100` 的分數時，是會印出 `F` 的，你該怎麼解決呢?


### Nested if
`if` 的內容可以是另一個 `if`，這種結構稱為**巢狀條件式(Nested if)**。

舉一個例子，如果你有三個整數 `a, b, c` ，請你輸出最大的那個數字。


```python linenums="1"
a, b, c = map(int, input().split())
max_one = None

if a > b:
    max_one = a
    if c > max_one:
        max_one = c
else:
    max_one = b
    if c > max_one:
        max_one = c

print(max_one)
```

```linenums="1" title="input"
10 20 30
12 12 12
-3 -4 -5
```

```linenums="1" title="ouput"
30
12
-3
```

想法很簡單，先讓 `a, b` 進行比較，得到最大的那個數字，再讓 `c` 與 `max_one` 比較，得到最大的那個數字。

這裡偷偷告訴你一個神奇妙妙工具，`#!python max()`，他會找出括號內的東西中最大的那個數字。

```python linenums="1"
a, b, c = map(int, input().split())
print(max(a, b, c))
```

```linenums="1" title="input"
114514 1919 810
```

```linenums="1" title="ouput"
114514
```

## match ... case
在 Python 3.10 中，新增了 `match ... case` ，但遺憾的是一些古老的 Online Judge 的 Python 版本太舊不能用，但我還是想介紹給你。

我們先來看一個在 `if ... elif ... else` 中的例子:

```python linenums="1"
month = int(input("Enter a month (1-12): "))

# which season?
if 3 <= month <= 5:
    print("Spring")
elif 6 <= month <= 8:
    print("Summer")
elif 9 <= month <= 11:
    print("Fall")
elif month == 12 or month == 1 or month == 2:
    print("Winter")
else:
    print("Invalid month")
```

```linenums="1" title="input"
4
7
10
1
13
```

```linenums="1" title="ouput"
Spring
Summer
Fall
Winter
Invalid month
```

再來看看 `match ... case` 的版本:

```python linenums="1"
month = int(input("Enter a month (1-12): "))

match month:
    case 3 | 4 | 5:
        print("Spring")
    case 6 | 7 | 8:
        print("Summer")
    case 9 | 10 | 11:
        print("Autumn")
    case 12 | 1 | 2:
        print("Winter")
    case _:
        print("Invalid month")
```

```linenums="1" title="input"
270
11
3
```

```linenums="1" title="ouput"
Invalid month
Autumn
Spring
```

是不是很簡潔呢?如果你有學過其他像是 `C, C++, Java` 等語言，你可能看過 `switch .. case`，但是 `match ... case` 更強大!

關於 `match ... case` 我就介紹到這裡，更重要的是，你要知道 `if ... elif ... else` 的用法。

@EditTime : 2024-01-29 12:32

## Practice
!!! success ""
    Itsa - [[C_MM09-易] 計算 i 次方的值](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6879)

??? abstract "Reference code"

    ```python linenums="1"
    i = int(input())
    if i > 31:
        print("Value of more than 31")
    else:
        print(1 << i)
    ```



