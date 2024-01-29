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

首先跟你介紹 `!#python range`，這個函式可以產生一個數列，並且可以指定起始值、結束值、間隔值。這個函式的用法如下:

如果只有一個參數，那就是結束值，起始值預設為 0，間隔值預設為 1。

`range(start=0, stop, step=1)` 並且注意，`stop` 是不包含在數列中的。

再舉個例子，想要計算 $\sum_{i=1}^n{i}=1+2+\cdots+n$

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


