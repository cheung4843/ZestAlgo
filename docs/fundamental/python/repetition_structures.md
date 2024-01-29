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

首先跟你介紹 `#!python range`，這個函式可以產生一個數列，並且可以指定起始值、結束值、間隔值。這個函式的用法如下:

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

來看一個稍微複雜的例子，輸入一個數字，判斷他是不是質數。

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

我們把問題複雜一點，輸入一個數字 $n$，請輸出在 $[1, n]$ 之間最大的質數。

在這裡介紹如何讓 `#!python range()` 倒著數回來，並且介紹**巢狀迴圈(Nested Loop)**。

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

@EditTime : 2024-01-29 23:51