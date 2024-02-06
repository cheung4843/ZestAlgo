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

那 `# print("Hello Cat!")` 是什麼?以井字號為開頭的，被稱為註解，他不會在程式中被執行，他可以幫助你理解程式碼，或者讓你的程式碼可讀性更佳。

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