# Dictionaries
## Introduction
來介紹本主題中最後一個資料結構：**字典(Dictionaries)**，是由**鍵(Key)**和**值(Value)**所組成的有序集合，你可以經由鍵來取得值，鍵必須是**不可變的(immutable)**，而值則可以是任何型態的資料。

!!! question
    1. 序對可以做為字典的鍵嗎?
    2. 串列可以做為字典的鍵嗎?
    3. 字典可以做為字典的值嗎?

留給你思考，你一定知道答案，就算你沒辦法馬上知道，你也可以自己寫程式來測試。

## Create a Dictionary
你可以用`#!python {}`、`#!python dict()` 或者 Comprehension 來建立一個字典。

```python linenums="1"
scores = {"Compiler": 100, "AWS": 95, "Data Science": 92}
print(scores)

# when keys are strings, using keyword arguments
directions = dict(North="↑", South="↓", East="→", West="←")
print(directions)

capital = dict([("Taiwan", "Taipei"), ("Japan", "Tokyo"), ("Korea", "Seoul")])
print(capital)

# comprehension
cube = {x: x ** 3 for x in range(-2, 3)}
print(cube)
```

```linenums="1" title="Output"
{'Compiler': 100, 'AWS': 95, 'Data Science': 92}
{'North': '↑', 'South': '↓', 'East': '→', 'West': '←'}
{'Taiwan': 'Taipei', 'Japan': 'Tokyo', 'Korea': 'Seoul'}
{-2: -8, -1: -1, 0: 0, 1: 1, 2: 8}
```

那為什麼說字典是有序的呢?你多執行幾次，輸出的順序與你建立的順序是一樣的嗎?

## Operations
### Accessing and Modifying elements
你可以透過鍵來取得值，也可以透過鍵來修改值，如果鍵不存在，你會得到 `#!python KeyError`。

```python linenums="1"
recent_listening = {"King Gnu": "飛行艇"}
print(recent_listening["King Gnu"])

recent_listening["King Gnu"] = "SPECIALZ"
print(recent_listening["King Gnu"])

recent_listening["HEALTH"] = "Blue Monday"
print(recent_listening["HEALTH"])

print(recent_listening["ALI"])
```

```linenums="1" title="Output"
飛行艇
SPECIALZ
Blue Monday
KeyError: 'ALI'
```

[King Gnu - 飛行艇](https://www.youtube.com/watch?v=MSv7NbfbtU8)

[Blue Monday](https://youtu.be/u1_KbKR_sng?si=QK1W4nhVL3qXAMnr)

那麼該如何檢查鍵是否存在呢?你可以使用 `#!python in` 來檢查，來避免錯誤。

```python linenums="1"
recent_listening = {"King Gnu": "飛行艇"}

print("King Gnu" in recent_listening)
print("ALI" in recent_listening)
```

```linenums="1" title="Output"
True
False
```

!!! question
    對於一個長度為 $n$ 的字典，你認為需要花幾個步驟檢查某一個鍵存在?

### Removing elements
你可以使用 `#!python del` 來刪除字典中的元素。

例如我這陣子都不寫 Java 了，所以把 Java 從我的心中刪除。

```python linenums="1"
my_love = {"python": 100, "Java": 70, "Js": 60}
print(my_love)

del my_love["Java"]
print(my_love)
```

```linenums="1" title="Output"
{'python': 100, 'Java': 70, 'Js': 60}
{'python': 100, 'Js': 60}
```

### Iterating
直接來看例子吧。

```python linenums="1"
my_love = {"python": 100, "Java": 70, "Js": 60}

for key in my_love:
    print(key, my_love[key])
```

```linenums="1" title="Output"
python 100
Java 70
Js 60
```

如果你只想要取得鍵或者值，你可以使用 `#!python keys()` 或者 `#!python values()`。

```python linenums="1"
my_love = {"python": 100, "Java": 70, "Js": 60}

for key in my_love.keys():
    print(key)

print(my_love.keys())

for value in my_love.values():
    print(value)

print(list(my_love.values()))
```

```linenums="1" title="Output"
python
Java
Js
dict_keys(['python', 'Java', 'Js'])
100
70
60
[100, 70, 60]
```

那如果你想要同時取得鍵和值呢?你可以使用 `#!python items()`。

```python linenums="1"
my_cat = {"name": "Fat Orange", "age": 12, "is_cute": True}

for key, value in my_cat.items():
    print(f"{key}: {value}")
```

```linenums="1" title="Output"
name: Fat Orange
age: 12
is_cute: True
```

<div align=center><img src=https://raw.githubusercontent.com/cheung4843/cheung4843/main/my_orange.jpg width=300 heigh=300></div>

我愛我的橘貓。

## Methods
### get
你可以使用 `#!python get()` 來取得字典中的值，如果鍵不存在，你可以設定預設值，很方便喔。

```python linenums="1"
my_info = {'name': 'Sean', 'age': 20, 'hobbies': ['coding', 'working out']}
print(my_info['name'])
print(my_info.get('hobbies')[1])

# print(my_info['is_handsome']) # This will cause an error
print(my_info.get('is_handsome', 'Of course I am!'))
```

```linenums="1" title="Output"
Sean
working out
Of course I am!
```

希望你不要覺得我自戀。

### pop
你可以使用 `#!python pop()` 來取得字典中的值，同時刪除該鍵值對。

```python linenums="1"
my_info = {'name': 'Sean', 'age': 20, 'hobbies': ['coding', 'working out']}
print(my_info.pop('age'))
print(my_info)
```

```linenums="1" title="Output"
20
{'name': 'Sean', 'hobbies': ['coding', 'working out']}
```

### clear
你可以使用 `#!python clear()` 來清空字典。

```python linenums="1"
my_info = {'name': 'Sean', 'age': 20, 'hobbies': ['coding', 'working out']}
my_info.clear()
print(my_info)
```

```linenums="1" title="Output"
{}
```

umm... 再過不久我就要 21 歲了。

我認為這些方法就夠用了，其他的你可以自己查 Docs 來學習囉~

## Practice
!!! success ""
    Itsa - [[C_ST19-易] 時間轉換](https://e-tutor.itsa.org.tw/mod/programming/view.php?a=931)

??? abstract "Reference code"
    ```python linenums="1"

    n = int(input())

    time_diff = {"TW": 0, "JA": 60, "USE": -720, "USC": -780, "USW": -840, "UK": -480}

    for _ in range(n):
        time, cur, to = input().split()
        minutes = int(time[:2]) * 60 + int(time[3:])
        minutes += time_diff[to] - time_diff[cur]

        if minutes < 0:
            minutes += 1440
        minutes %= 1440

        h, m = divmod(minutes, 60)
        print(f"{h:02d}{m:02d} {to}")
    ```
    一律先轉換成分鐘，再進行時區轉換，最後再轉換成小時和分鐘。

    `#!python divmod` 回傳一個序對，商與餘數。

## Assignment
!!! success ""
    Itsa - [[C_AR111-易] 對話機器人](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=20146)

!!! success ""
    Itsa - [[C_AR152-易] 正整數統計](https://e-tutor.itsa.org.tw/mod/programming/view.php?a=12264)

??? Tip
    `#!python sorted()` and `key`

!!! success ""
    Itsa - [[C_AR42-易] 過半元素](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=3042)

!!! success ""
    Itsa - [[C_AR188-易] 陣列元素](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=29920)

??? Tip
    除了用字典來解題之外，你也可以學 [Boyer–Moore majority vote algorithm](https://zh.wikipedia.org/zh-tw/%E5%A4%9A%E6%95%B0%E6%8A%95%E7%A5%A8%E7%AE%97%E6%B3%95)


