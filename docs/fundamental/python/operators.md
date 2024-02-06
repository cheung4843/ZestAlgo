# Operators
## Introduction
在這個章節中，我們要來學習運算子，運算子可以讓我們對變數做運算，例如: 加法、減法、乘法、除法等等。

## Arithmetic Operators
首先，我們來看看算術運算子，我們熟悉的四則運算就是算術運算子，他們分別是 `+`、`-`、`*`、`/`，分別代表加法、減法、乘法、除法。

```python linenums="1"
x, y = 10, 3
print(x + y)
print(x - y)
print(x * y)
print(x / y)
z = x // y
print(z)
print(type(z))
print(x % y)
print(x ** y)
```

```linenums="1" title="ouput"
13
7
30
3.3333333333333335
3
<class 'int'>
1
1000
```

我相信看完輸出後，你能大致明瞭各個運算子的作用，其中想請你留意 `*` 乘法運算子，請你不要打成 `x`，以及 `/` 與 `//` 的差別，後者會將結果向下取整。還有比較特別的 `%` ，留意到 `10 = 3 * 3 + 1`，就是取餘數；而看起來最奇特的 `**` ，他的作用是求冪。

我們來複習一下國小數學: 
```python linenums="1"
# Upper case for constant
PI = 3.14
r = 2
area = PI * (r ** 2)
perimeter = 2 * PI * r
print(f'Area: {area}, Perimeter: {perimeter}')

# Sum of 1 to 100
total = (1 + 100) * 100 // 2
print(f'The sum of 1 to 100 is {total}')
```

```linenums="1" title="ouput"
Area: 12.56, Perimeter: 12.56
The sum of 1 to 100 is 5050
```

這邊要提醒你的是，運算子之間有優先順序，當你不確定結果的時候，請善用括號。

```python linenums="1"
x = 'A' + 'n' + 'i' + 'm' + 'a' + 'l' + 's'
print(x)
```

```linenums="1" title="ouput"
Animals
```

[Martin Garrix - Animals (Official Video)](https://youtu.be/gCYcHz2k5x0?si=pbDn18__Mgf9jNdu)

再請你留意一件事，不同類別對於運算子的作用是不同的，例如字串的 `+` 會將兩個字串相連，而整數的 `+` 則會將兩個整數相加。

!!! question
    1. `2 ** 3 ** 2` 的結果是多少?
    2. `2 ** (3 ** 2)` 的結果是多少?
    3. `(2 ** 3) ** 2` 的結果是多少?

## Comparison Operators
比較運算子的結果會是 `True` 或 `False`，這個結果我們稱為布林值。

我們來以直角三角形的性質來做一些比較運算子的練習。

```python linenums="1"
a, b, c = 3, 4, 5

print(a < b)
print(a > b)
print(a <= b)
print(a >= b)
print(a ** 2 + b ** 2 == c ** 2)
print(a ** 2 + b ** 2 != c ** 2)
print((a + b) > c)
```

```linenums="1" title="ouput" 
False
True
False
True
False
True
```

這邊要提醒你， `==` 是比較運算子，而 `=` 是指派運算子，他們的意思是不一樣的。

最後來看一個例子:
```python linenums="1" hl_lines="5 6"
age = 14
print(12 <= age <= 18)

x, y, z = 1, 2, 3
print(x < y < z)
print(x < y and y < z)
```

```linenums="1" title="ouput"
True
True
True
```

在Python中，我們可以將比較運算子連接起來，這樣的寫法可以讓我們的程式碼更簡潔。

!!! question
    1. `#!python print(1 < 2 < 3 < 4 < 5)` 會印出什麼?
    2. `#!python print(1 < 2 < 3 < 4 > 5)` 會印出什麼?

## Logical Operators

我們繼續往下看，這邊我們要介紹邏輯運算子，他可以將多個布林值結合成一個布林值。

```python linenums="1"
has_license = True
is_drunk = False
age = 18

print(f"Can I drive a car? {has_license and not is_drunk and age >= 18}")
print(not has_license)
print(not is_drunk)
print(age >= 18 or is_drunk or not has_license)
```

```linenums="1" title="ouput"
Can I drive a car? True
False
True
True
```

這邊要提醒你的是， `and` 只有在所有布林值都是 `True` 的時候，結果才會是 `True`，而 `or` 只要有一個布林值是 `True`，結果就會是 `True`。

因此有所謂的*短路求值(Short-circuit Evaluation)*，當 `and` 的第一個布林值是 `False`，後面的布林值就不會被計算，因為結果一定是 `False`；而 `or` 的第一個布林值是 `True`，後面的布林值就不會被評估，因為結果一定是 `True`。

而 `not` 是一元運算子，他只會將布林值反轉。

!!! question
    1. `#!python print(not True and False)` 會印出什麼?
    2. `#!python print(not True or False)` 會印出什麼?
    3. `#!python print(not True and not False)` 會印出什麼?
    4. `#!python print(not True or not False)` 會印出什麼?

## Bitwise Operators
在這邊我們要介紹位元運算子，他是對二進位的運算，我們可以用 `bin()` 來觀察二進位的結果。

```python linenums="1"
a, b = 2, 3
print(f"a={bin(a)}")
print(f"b={bin(b)}")

print(a & b, bin(a & b))
print(a | b, bin(a | b))
print(a ^ b, bin(a ^ b))
print(~a, bin(~a))

print(a << 1, bin(a << 1))
print(a >> 1, bin(a >> 1))
```

```linenums="1" title="ouput"
a=0b10
b=0b11
2 0b10
3 0b11
1 0b1
-3 -0b11
4 0b100
1 0b1
```

`&` 是位元的 `and`， `|` 是位元的 `or`， `^` 是位元間的進行互斥或運算， `~` 是位元的 `not`， `<<` 是位元的左移， `>>` 是位元的右移。

在往下之前，請你先想想我們該如何判斷一個數字是奇數還是偶數，我們可以用 `%` 來判斷，但是我們也可以用位元運算來判斷。

```python linenums="1"
a, b = 5678, 4843
print(f"Is a even? {a % 2 == 0}")
print(f"Is b odd? {b & 1 == 1}")
```

```linenums="1" title="ouput"
Is a even? True
Is b odd? True
```

!!! question
    1. 如何判斷一個數字是 `2` 的冪?
    2. 如何得到一個數字的 16 倍，但不能用 `*` 乘法運算子?

## Assignment Operators
我們已經學會了一些運算子，現在我們要來學習一些指派運算子，他可以將運算結果指定給變數。

先來看看一個簡單的例子，我們可以用 `+=` 來將變數加上某個值，這個運算子可以讓我們的程式碼更簡潔。

```python linenums="1" hl_lines="2 4"
x = 1
x = x + 2
y = 1
y += 2
print(x, y)
```

```linenums="1" title="ouput"
3 3
```

再來看看其他的指派運算子。

```python linenums="1"
x = 1
x += 2
print(x)
x -= 1
print(x)
x *= 3
print(x)
x //= 2
print(x)
x **= 2
print(x)
x <<= 1
print(x)
```

```linenums="1" title="ouput"
3
2
6
3
9
18
```

對了，請你別忘記 `=` 也是一個指派運算子。

```python linenums="1"
x = y = z = 1
print(x, y, z)
```

```linenums="1" title="ouput"
1 1 1
```

希望這個例子可以讓你更熟悉指派運算子。

!!! question
    1. 有沒有 `and=` 這個指派運算子?
    2. `&=` 這個指派運算子的作用是什麼?


## Bonus: f-string for float

為了能讓你練習一些題目，我先在這裡介紹如何印出浮點數到指定位數。

在 [Say Hello to Python - Input](say_hello.md#input) 中，有稍微提過，如果你完全沒印象，請你回去複習一下。

給你浮點數 `x` ，請你印出 `x` 的平方根與平方，並且只印出小數點後兩位。

```python linenums="1"
x = 3.1415926
print(f"The square root of {x} is {x ** 0.5:.2f}")
print(f"The square of {x} is {x ** 2:.2f}")
```

```linenums="1" title="ouput"
The square root of 3.1415926 is 1.77
The square of 3.1415926 is 9.87
```

@EditTime : 2024-01-27 11:52

## Bonus: map for input
再次複習 [Variable and Input - Mutiple Input](variable_and_input.md#multiple_input) 中的例子，我們可以用 `split()` 來將輸入的字串切割成多個字串。

但是如果我們想要將這些字串轉換成整數，我們可以怎麼做呢?

```python linenums="1"
a, b, c = input().split()
print(int(a) + int(b) + int(c))
```

```linenums="1" title="input"
1 2 3
```

```linenums="1" title="ouput"
6
```

雖然這樣寫也可以，但是如果我們想要輸入很多個數字，這樣寫就會很麻煩，這時候我們可以用 `map()` 來幫助我們。

```python linenums="1"
a, b, c = map(int, input().split())
print(a + b + c)
```

```linenums="1" title="input"
4 5 6
```

```linenums="1" title="ouput"
15
```

`#!python map(function, iterable)` 會將 `iterable` 中的每一個元素都丟進 `function` 中，在這裡的 `iterable` 是 `#!python input().split()`，而 `function` 是 `#!python int`，因此 `#!python map(int, input().split())` 會將 `#!python input().split()` 中的每一個元素都轉換成整數。

你可以嘗試將使用別的函式，例如 `#!python float` 或 `#!python str`，但請你記得不要加上括號，因為我們只是要將函式的名稱傳進去，而不是要執行函式。

我們使用 *Unpacking* 的方式來將 `#!python map()` 的結果指派給變數。我相信你還記得什麼是 *Unpacking* 吧?

如果你不太能理解，也沒關係，先學會怎麼用就好。

## Practice
有了本章的基礎後，其實已經可以做很多題目了，我們來做一些練習題吧!

!!! success ""
    Itsa - [[C_MM01-易] 計算梯型面積](https://e-tutor.itsa.org.tw/mod/programming/view.php?a=2913)

??? abstract "Reference code"
    ```python linenums="1"
    a, b, h = map(int, input().split())
    area = (a + b) * h / 2
    print(f"Trapezoid area:{area}")
    ```

!!! success ""
    Itsa - [[C_MM02-易] 計算三角形面積](https://e-tutor.itsa.org.tw/mod/programming/view.php?a=2914)

??? abstract "Reference code"
    ```python linenums="1"

    a, b = map(int, input().split())
    area = a * b / 2
    print(area)
    ```

!!! success ""
    Itsa - [[C_MM04-易] 計算總和、乘積、差、商和餘數](https://e-tutor.itsa.org.tw/mod/programming/view.php?a=2916)

??? abstract "Reference code"
    ```python linenums="1"

    a, b = map(int, input().split())

    print(f"{a}+{b}={a + b}")
    print(f"{a}*{b}={a * b}")
    print(f"{a}-{b}={a - b}")
    print(f"{a}/{b}={a // b}...{a % b}")
    ```

!!! success ""
    Itsa - [[C_MM06-易] 英哩轉公里](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=6870)

??? abstract "Reference code"
    ```python linenums="1"

    mile = int(input())
    km = mile * 1.6
    print(f"{km:.1f}")
    ```

## Assignment
!!! success ""
    Itsa - [[C_MM07-易] 計算平方值與立方值](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=6873)

!!! success ""
    Itsa - [[C_MM08-易] 計算兩數和的平方值](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=6876)

!!! success ""
    Itsa - [[C_MM10-易] 攝氏溫度轉華式溫度](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=6882)

!!! success ""
    Itsa - [[C_MM11-易] 購票計算](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=6885)

!!! success ""
    Itsa - [[C_MM12-易] 相遇時間計算](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=6888)

!!! success ""
    Itsa - [[C_MM14-易] 計算時間的組合](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=6894)

@EditTime : 2024-01-28 22:03



