# Say Hello to Python!
## First Program
嗨，這是你第一個 Python 程式，在 Pycharm 中建立一個 `main.py` 檔案，並在檔案中打上 : 

```python linenums="1"
# print("Hello Cat!")
print("Hello World!")
print('Hello Python!')
print("cheung4843")
```

按下執行後，你的控制台(Console)將會印出 `Hello World!` 接著換行，再印出 `Hello Python!`，接著再印出我 `cheung4843`，再換行。

那 `# print("Hello Cat!")` 是什麼?以井字號為開頭的，被稱為註解，他不會在程式中被執行，而他的作用，你以後一定能體會。

不曉得你是否有發現 `"Hello World!"` 與 `'Hello Python!'` 的差異?當然除了字母不一樣之外，還有雙引號與單引號的差別，但他們都被稱為**字串(String)**，在 Python 中，你可以使用成對的雙引號與單引號來表達一個字串，但是不能混用，例如 :

```python linenums="1"
print("I love cats')
```

執行後，你會發現控制台跟你報告了錯誤，這是語法錯誤，而後續寫程式的過程中，你將遭遇許多語意錯誤。

那你知道什麼是空字串嗎?

```python linenums="1"
print('')
print("")
print("Above are nothing, right?")
```

執行完後，你就知道空字串是什麼了吧?

接著我們來講講 `#!python print` 這個東西，我們在 Python 中稱他為**函式(Function)**，我們要如何使用呢?也就是在**函式的名稱**後加上一個括號`()`。而 `#!python print` 是 Python 內建給我們的「工具」，就是說，我們不知道他是怎麼被造出來的，我們現階段只要知道怎麼用就好，或許你可能聽過一個老掉牙的比喻，稱函式就像是一個黑盒子。

關於**函式(Function)**，我會在往後的章節跟你介紹，而現在你只要知道 `#!python print()` 會將括號內的東西印出來，並換行。

那如果我不想換行呢?

```python linenums="1"
print("You")
print("are")
print("my", end=' ')
print("special", end='\n')
print("1234", end="5")
print("---------")
```

```linenums="1" title="ouput"
You
are
my special
12345---------
```

在這個奇怪的程式碼中，你發現我在 `#!python print` 的括號中多加了一個 `end=` 的東西，讓 `#!python print` 印完前面的東西後，再印出等於後的東西。

[You are my special](https://youtu.be/5yb2N3pnztU?si=SKbav1WexiBvVu_o)

那 `\n` 是什麼東西?他是**跳脫字元(Escape Character**)家族中的一員，你現在只要知道他能夠換行。

!!! note
    1. 雙引號/單引號圍住的內容，稱為字串，例如 `"cheung4843"` 與 `'114514 + 1919810'` ，但記住單雙引號不得混用。
    2. `#!python print(x, end=y)` 會印出 `x` ，再印出 `y`，而 `y` 預設為 `\n` 也就是換行。

@EditTime : 2024-01-25 19:23

!!! question
    1. 那麼 `"'"` 與 `"""` 是合法的字串嗎?
    2. `#!python print()` 括號內沒有放東西會印出什麼?

@EditTime : 2024-01-25 19:55

## Variable and Input
### Variable
接下來，來點好玩的。

```python linenums="1"
x = 4843
print(x)

x = "Memory Reboot"
print(x)

x = '4843'
print(x)
```

或許你可能會覺得神奇，為什麼 `x` 可以變成數字，又可以變成字串，還有為什麼第一個與第三個的輸出會是相同的。

再來用一些 old-school 的比喻，你可以將 `x` 想像成一個箱子，而等號右邊的「值」就是箱子裡裝的東西。既然箱子裡面的東西可以變，那我是不是可以說 `x` 是一個變數呢?

但請你先忘掉這個比喻，因為這個比喻並不完美，但我想你應該能夠理解，`x` 是一個變數，而 `=` 是**指派運算子(Assignment Operator)**，他會將等號右邊的東西指派給等號左邊的變數，或者說 `x` 會指向等號右邊的**物件(Object)**。

!!! quote
    在Python中，一切都是物件。

請觀看下面的動畫。

<!-- ![](../python/media/cat_2.jpg) -->

<video muted controls>
  <source src="../../python/media/variable_1.mp4" type="video/mp4">
</video>


[VØJ, Narvent - Memory Reboot (4K Music Video)](https://youtu.be/wL8DVHuWI7Y?si=1_yzspgq_h2puGeu)

再來介紹幾種不同的變數類型。

```python linenums="1"
a = 114514
print(type(a))
b = 1919810.0
print(type(b))
c = 10e3
print(type(c))
d = "cheung4843"
print(type(d))
e = True
print(type(e))
f = False
print(type(f))
h = None
print(type(h))
```
`#!python type` 告訴你括號中的東西是什麼**類別(Class)**。

`b` 與 `c` 都是**浮點數(Float)**，也就是小數點的數字，而 `d` 則是字串，`e` 與 `f` 則是**布林(Boolean)**，而 `h` 則是空值。

!!! note
    1. `#!python type(x)` 回傳 `x` 的類別。
    2. `#!python int` 整數。
    3. `#!python float` 浮點數。
    4. `#!python str` 字串。
    5. `#!python bool` 布林。
    6. `#!python None` 空值。

!!! question
    1. `#!python print(type(3 + 4.0))` 會印出什麼?
    2. `#!python print(type(3 + True))` 會印出什麼?


@EditTime : 2024-01-27 16:44
### Input

但是如果每次想要修改 `x` 裡面的東西，難道都要在程式碼中修改嗎?能不能我自己來輸入呢?

```python linenums="1"
x = input("Enter a number: ")
print(type(x))
y = input("Enter another number: ")
z = int(x) + int(y)
print("The sum is: ", z)
```

喔幹，怎麼一下子多出那麼多東西，別慌，我來解釋，但請你先回想在前一節中學過的東西，你可以發現 `#!python input, int,` 都是函式。而 `#!python input` 括號中的字串會顯示在控制台中提示你要輸入什麼，`#!python int` 則是把括號中的東西的類別轉換成整數。

那為什麼印出`#!python type(x)` 得到 `<class 'str'>` 呢?代表 `x` 是一個字串，這是因為 `#!python input` 總是將你輸入進來的東西當成字串，但我想要讓 `z = x + y` 這個數學式子成立，所以需要用 `#!python int` 來將字串轉換成整數再進行運算。

那下面這個程式碼的輸出結果是什麼呢?

```python linenums="1"
x = input("Enter a number: ")
print(type(x))
y = input("Enter another number: ")
z = x + y
print("The sum is: ", z)
```

沒錯，字串的相加，就是相連。那你要不要試試看相減?

接下來我們來做個有趣的實驗，順便認識一下 **f-string** 
```python linenums="1"
a = 3.5
b = int(a)
print(f'The value of b is {b}, and its type is {type(b)}')
c = float(b)
print(f'The value of c is {c}, and its type is {type(c)}')
print(b == c)
```

那 `#!python f-string` 是什麼東西呢?他是一種**字串格式化(String Formatting)**的方法，他會將括號內的東西轉換成字串，並將字串中的 `{}` 替換成括號內的東西。

而執行完程式碼後，你會發現 `b` 與 `c` 的類別不同，但他們的值卻相同，這是因為 `#!python int()` 與 `#!python float()` 都是將括號內的東西轉換成整數與浮點數，而 `#!python int()` 會將浮點數的小數點捨去，而 `#!python float()` 則會將整數轉換成浮點數。

那麼 `b == c` 是什麼意思呢?其中 `==` 是**比較運算子(Comparison Operator)**，他會比較等號左右兩邊的東西是否相等，如果相等，則回傳 `True`，否則回傳 `False`。

#### Multiple Input

那如果我今天想要一次輸入好幾個字串，每一個字串以空格來隔開呢?
但在這之前，我們先來看一個小程式 : 

```python linenums="1"
a, b = "Hello World".split()
print(a)
print(b)
```

我知道怪怪的，為什麼字串後面接了一個 `#!python .split()` 呢?在這裡他很像是函式，但又不是函式，那他叫什麼呢?他被稱為 `"Hello World"` 這個字串的**方法(Method)**，但未來你可能還會聽到**類別方法(Class Method)**，以及**靜態方法(Static Method)** 等名詞，我怕你會搞混，所以你就先認逗點後面的是「方法」就好了。

而 `#!python .split()` 會把字串以括號內的東西來切割字串並回傳(那你想想括號內什麼都沒放，預設會是什麼?)，而看看等號左邊，我用 `a, b` 去接著，這稱為*開箱(Unpacking)*

那現在你應該能看懂下面的程式碼了，因為 `#!python input()` 也會回傳一個字串，因此他也能夠使用 `.split()` 

```python linenums="1"
a, b = input().split()
print(a)
print(b)
```


!!! note
    1. `#!python input()` 接受輸入，回傳一個字串。
    2. `#!python int(x)` 將 `x` 轉換成整數。
    3. `#!python float(x)` 將 `x` 轉換成浮點數。
    4. `#!python str.split()` 以括號內的東西來切割字串，並回傳。

@EditTime : 2024-01-25 22:13

!!! question
    1. `#!python print(int(input()) + int(input()))` 會印出什麼?
    2. `124.spilt("1")` 是合法的嗎?
    3. `#!python bool(0)` 與 `#!python bool(1)` 會回傳什麼?
    4. 看以下的程式碼，為什麼它們的功能相同，`a` 與 `b` 成功互換了呢?

```python linenums="1" hl_lines="3"
a, b = 4, 5
print(a, b)
a, b = b, a
print(a, b)
```

```python linenums="1" hl_lines="3-5"
a, b = 4, 5
print(a, b)
tmp = a
a = b
b = tmp
print(a, b)
```

@EditTime : 2024-01-25 22:17

## Practice
在這篇文章中，你學到了:
!!! info
    1. 如何使用 `#!python print()` 與 `#!python input()`。
    2. 知道變數的概念。
    3. 知道 `#!python type(x)` 與 `#!python int(x), float(x)` 的用途。
    4. 知道 `#!python str.split()` 的用途。
    5. 知道如何使用 `#!python f-string`。

那現在你可以試試看以下的題目了。
!!! success ""
    ZeroJudge - [a001. 哈囉](https://zerojudge.tw/ShowProblem?problemid=a001)


??? abstract "Reference code"
    ```python linenums="1"
    
    word = input()
    print(f'hello, {word}')
    ```
    
    

@EditTime : 2024-01-27 17:02