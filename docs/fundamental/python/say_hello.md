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

但請你先忘掉這個比喻，因為這個比喻並不完美，但我想你應該能夠理解，`x` 是一個變數，而 `=` 是一個**指派運算子(assignment operator)**，他會將等號右邊的東西指派給等號左邊的變數。

請觀看下面的動畫。

<!-- ![](../python/media/cat2.jpg) -->

<video autoplay muted loop controls>
  <source src="../../python/media/Variable_1.mp4" type="video/mp4">
</video>


[VØJ, Narvent - Memory Reboot (4K Music Video)](https://youtu.be/wL8DVHuWI7Y?si=1_yzspgq_h2puGeu)

但是如果每次想要修改 `x` 裡面的東西，難道都要在程式碼中修改嗎?能不能我自己來輸入呢?

```python linenums="1"
x = input("Enter a number: ")
print(type(x))
y = input("Enter another number: ")
z = int(x) + int(y)
print("The sum is: ", z)
```

喔幹，怎麼一下子多出那麼多東西，別慌，我來解釋，但請你先回想在前一節中學過的東西，你可以發現 `#!python input, int, type` 都是函式。而 `#!python input` 括號中的字串會顯示在控制台中提示你要輸入什麼，`#!python type` 則告訴你括號中的東西是什麼**類別(Class)**，最後，`#!python int` 則是把括號中的東西的類別轉換成整數。

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
    3. `#!python type(x)` 回傳 `x` 的類別。
    4. `#!python str.split()` 以括號內的東西來切割字串，並回傳。

@EditTime : 2024-01-25 22:13

!!! question
    1. `#!python print(int(input()) + int(input()))` 會印出什麼?
    2. `124.spilt("1")` 是合法的嗎?
    3. 看以下的程式碼，為什麼它們的功能相同，`a` 與 `b` 成功互換了呢?

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



