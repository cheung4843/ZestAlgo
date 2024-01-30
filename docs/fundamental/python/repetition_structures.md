# Repetition Structures
## for loop
首先，我們來看看 `for` 迴圈的用法。並舉個簡單的例子，印出 1 到 5:

```python linenums="1"
for i in range(1, 6, 1):
    print(i, end=' ')
```

```linenums="1" title="ouput"
1 2 3 4 5
```

[Time Loop - Purrple Cat](https://youtu.be/uYtnLt_3kGc?si=-RI0Oof9TMxt-u-_)

`#!python range`，這個函式可以產生一個數列，並且可以指定起始值、結束值、間隔值。這個函式的用法如下:

如果只有一個參數，那就是結束值，起始值預設為 0，間隔值預設為 1。

`#!python range(start=0, stop, step=1)` 並且注意，`stop` 是不包含在數列中的。

再舉個例子，計算 $\sum_{i=1}^n{i}=1+2+\cdots+n$

```python linenums="1"
n = int(input())
total = 0

# 1 + 2 + ... + n
for i in range(n + 1):
    total += i

print(total)
```

```linenums="1" title="input"
100
```

```linenums="1" title="ouput"
5050
```

接下來，跟你介紹 `#!python break` 與 `#!python continue`，這兩個關鍵字可以用來控制迴圈的執行。

`#!python break` 可以用來強制跳出迴圈，而 `#!python continue` 則是強制跳到下一次迴圈。

```python linenums="1"
for i in range(1, 11):
    if i == 5:
        break
    print(i, end=' ')
```

```linenums="1" title="ouput"
1 2 3 4
```

可以發現，`i == 5` 的時候，迴圈就被強制中斷了。

```python linenums="1"
for i in range(1, 11):
    if i == 5:
        continue
    print(i, end=' ')
```

```linenums="1" title="ouput"
1 2 3 4 6 7 8 9 10
```

可以發現，`5` 被跳過了。

### Nested Loop
接著介紹**巢狀迴圈(Nested Loop)**，也就是迴圈裡面還有迴圈。做個比喻的話，如果是兩層的迴圈，就像是時針與分針，內層迴圈每跑一圈，外層迴圈才跑一格。

我們來印一個直角三角形吧，輸入一個數字 $n$，印出 $n$ 層的直角三角形，將最頂端的那一層編號為 $0$，最底端的那一層編號為 $n-1$，其中第 $i$ 層有 $i+1$ 個星星 `*`。

```python linenums="1" hl_lines="3-4"
n = int(input())

for i in range(n):
    for j in range(i + 1):
        print('*', end='')
    print()
```

我稱內層的迴圈叫做 `j` 迴圈，外層的迴圈叫做 `i` 迴圈。 `j` 迴圈控制每一層的星星數量，而 `i` 迴圈則控制總共有幾層。每一層的星星數量都是 `i + 1`，最後會換行。

```linenums="1" title="input"
5
```


```linenums="1" title="output"
*
**
***
****
*****
```

再來看一個經典的例子，九九乘法表。

```python linenums="1" hl_lines="1-2"
for i in range(1, 10):
    for j in range(1, 10):
        print(f"{i} * {j} = {i * j}", end='\t')
    print()
```

```linenums="1" title="output"
1 * 1 = 1	1 * 2 = 2	1 * 3 = 3	1 * 4 = 4	1 * 5 = 5	1 * 6 = 6	1 * 7 = 7	1 * 8 = 8	1 * 9 = 9	
2 * 1 = 2	2 * 2 = 4	2 * 3 = 6	2 * 4 = 8	2 * 5 = 10	2 * 6 = 12	2 * 7 = 14	2 * 8 = 16	2 * 9 = 18	
3 * 1 = 3	3 * 2 = 6	3 * 3 = 9	3 * 4 = 12	3 * 5 = 15	3 * 6 = 18	3 * 7 = 21	3 * 8 = 24	3 * 9 = 27	
4 * 1 = 4	4 * 2 = 8	4 * 3 = 12	4 * 4 = 16	4 * 5 = 20	4 * 6 = 24	4 * 7 = 28	4 * 8 = 32	4 * 9 = 36	
5 * 1 = 5	5 * 2 = 10	5 * 3 = 15	5 * 4 = 20	5 * 5 = 25	5 * 6 = 30	5 * 7 = 35	5 * 8 = 40	5 * 9 = 45	
6 * 1 = 6	6 * 2 = 12	6 * 3 = 18	6 * 4 = 24	6 * 5 = 30	6 * 6 = 36	6 * 7 = 42	6 * 8 = 48	6 * 9 = 54	
7 * 1 = 7	7 * 2 = 14	7 * 3 = 21	7 * 4 = 28	7 * 5 = 35	7 * 6 = 42	7 * 7 = 49	7 * 8 = 56	7 * 9 = 63	
8 * 1 = 8	8 * 2 = 16	8 * 3 = 24	8 * 4 = 32	8 * 5 = 40	8 * 6 = 48	8 * 7 = 56	8 * 8 = 64	8 * 9 = 72	
9 * 1 = 9	9 * 2 = 18	9 * 3 = 27	9 * 4 = 36	9 * 5 = 45	9 * 6 = 54	9 * 7 = 63	9 * 8 = 72	9 * 9 = 81	
```

`i` 控制*列(Row)*，`j` 控制*行(Column)*，每一列的數字都是 `i`，每一行的數字都是 `j`，所以 `i * j` 就是相應的乘積。

熱身完了，來看一個稍微複雜的例子，輸入一個數字，判斷他是不是質數。

這個例子會是等等更複雜的例子的基礎，所以請仔細看。

```python linenums="1" hl_lines="4-5"
n = int(input())
is_prime = True

for i in range(2, n):
    if n % i == 0:
        is_prime = False
        break

if is_prime:
    print("Yes")
else:
    print("No")
```

```linenums="1" title="input"
17
4843
```

```linenums="1" title="ouput"
Yes
No
```

`n` 如果可以整除 `1` 與自己以外的數字，那就不是質數，我們可以用 `#!python break` 來強制跳出迴圈，避免不必要的計算。

我們把問題用得更複雜，輸入一個數字 $n$，輸出在 $[1, n]$ 之間最大的質數。

在這裡介紹如何讓 `#!python range` 倒著數回來。

```python linenums="1" hl_lines="3 5 6"
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

``` linenums="1" title="input"
100
2
```

``` linenums="1" title="output"
97 is the largest prime in [1, 97]
2 is the largest prime in [1, 2]
```

`i` 列舉 $[n, 1]$ 的數字，而 `j` 列舉 $[2, i-1]$ 的數字，如果 `i` 可以整除 `j`，那就不是質數，馬上跳出內層 `j` 迴圈，繼續列舉下一個數字。如果 `i` 是質數，那就印出來，並且跳出外層 `i` 迴圈。

請你仔細端詳這兩個例子中強調的行數。

@EditTime : 2024-01-30 16:33

## while loop
接著來介紹 `while` 迴圈，他的使用場景是當你不知道迴圈要執行幾次的時候，就可以用 `while` 迴圈，但是別寫出*無窮迴圈(Infinite Loop)*喔。

但在往下之前，先來看如何用 `while` 迴圈來印出 1 到 5。

```python linenums="1"
i = 1
while i < 6:
    print(i, end=" ")
    i += 1
```

```linenums="1" title="ouput"
1 2 3 4 5
```

回顧一下 [for loop](#for_loop)，你可以發現邏輯其實一樣。

當條件成立的時候，就會執行迴圈，直到條件不成立。

再舉一個例子，輸入正整數 $n$，輸出 $n!$

```python linenums="1"
n = int(input())
i = 1
fact = 1

while i <= n:
    fact *= i
    i += 1

print(fact)
```

```linenums="1" title="input"
5
1
```

```linenums="1" title="ouput"
120
1
```

但目前這兩個例子無法看出 `while` 的魅力，因為你都知道迴圈什麼時候會結束，所以跟你介紹一個經典問題:

$$
\text{The} \ 3n+1 \ \text{Problem} \ aka \ \text{Collatz Conjecture}
$$

!!! quote "[考拉茲猜想 wikipedia](https://zh.wikipedia.org/zh-tw/%E8%80%83%E6%8B%89%E5%85%B9%E7%8C%9C%E6%83%B3)"
    是指對於每一個正整數，如果它是奇數，則對它乘3再加1，如果它是偶數，則對它除以2，如此循環，最終都能夠得到1。

那我們要寫的程式是，輸入一個正整數 $n$，輸出他會在幾步後變成 $1$。

$$
f(n)=\begin{cases}\frac{n}{2}, & \text{if } n \text{ is even} \\ 3n+1, & \text{if } n \text{ is odd}\end{cases}
$$

依照定義，我們可以寫出以下程式碼:

```python linenums="1""
n = int(input())
step = 0

while n != 1:
    print(n, end=" -> ")
    if n % 2 == 0:
        n = n // 2
    else:
        n = (3 * n + 1)
    step += 1

print(1)
print(f"step = {step}")
```

```linenums="1" title="input"
22
1
```

```linenums="1" title="ouput"
22 -> 11 -> 34 -> 17 -> 52 -> 26 -> 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
step = 15
1
step = 0
```

再來介紹一個經典的例子，輸入一個正整數 $n\gt 1$，輸出 $n$ 的質因數分解。

請你先自己想一下，再看看參考程式碼。

??? example
    ```python linenums="1"
    n = int(input())
    factor = 2

    while n != 1:
        while n % factor == 0:
            print(factor, end=' ')
            n //= factor
        factor += 1
    ```

```linenums="1" title="input"
20
4843
```

```linenums="1" title="ouput"
2 2 5
29 167
```

內層的 `while` 迴圈會一直執行，直到 `n` 不是 `factor` 的倍數為止。外層的 `while` 迴圈則是列舉所有的質因數，直到 `n` 變成 $1$ 為止。

題外話，當初遇到這個題目的時候，想了一下結果一次就*AC*，是很有成就感的一件事，所以也請你好好努力，逐步培養自信，你也可以的。

@EditTime : 2024-01-30 17:55

## Practice
!!! success ""
    Itsa - [[C_MM03-易] 兩數總和](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6861)


??? abstract "Reference code"
    ```python linenums="1"

    while True:
        a, b = map(int, input().split())
        print(a + b)
    ```
    這題會出現在這裡，單純是因為要重複輸入。

!!! success ""
    Itsa - [[C_MM21-易] 算階乘](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6915)


??? abstract "Reference code"
    ```python linenums="1"
    
    ```

!!! success ""
    Itsa - [[C_MM25-易] 計算正整數被3整除之數值之總和](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6925)


??? abstract "Reference code"
    ```python linenums="1"
    
    ```

!!! success ""
    Itsa - [[C_MM26-易] 輸出 1x1、2x2、...、NxN之結果](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6928)


??? abstract "Reference code"
    ```python linenums="1"
    
    ```

!!! success ""
    Itsa - [[C_MM27-易] 計算兩整數間所有整數的總和](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6931)


??? abstract "Reference code"
    ```python linenums="1"
    
    ```

!!! success ""
    Itsa - [[C_MM28-易] 計算1到N之間屬於5和7的倍數](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6933)


??? abstract "Reference code"
    ```python linenums="1"
    
    ```

!!! success ""
    Itsa - [[C_MM29-易] 最大質數問題](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6935)


??? abstract "Reference code"
    ```python linenums="1"
    
    ```

!!! success ""
    Itsa - [[C_MM30-易] 質數判別](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6937)


??? abstract "Reference code"
    ```python linenums="1"
    
    ```

!!! success ""
    Itsa - [[C_MM31-易] 計算1~N內能被2跟3整除，但不能被12整除的整數總和](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6939)


??? abstract "Reference code"
    ```python linenums="1"
    
    ```

!!! success ""
    Itsa - [[C_MM33-易] 找1~N的完美數](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6943)


??? abstract "Reference code"
    ```python linenums="1"
    
    ```

!!! success ""
    Itsa - [[C_MM34-易] 因數問題](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6945)


??? abstract "Reference code"
    ```python linenums="1"
    
    ```

!!! success ""
    Itsa - [[C_MM40-易] 1~N之間的總和](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6957)


??? abstract "Reference code"
    ```python linenums="1"
    
    ```

!!! success ""
    Itsa - [[C_MM49-易] 連續1的倍數](https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=6979)


??? abstract "Reference code"
    ```python linenums="1"
    
    ```

@EditTime : 2024-01-30 18:40

