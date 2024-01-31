# Lists
## Introduction
不曉得你看到這裡有沒有發現，我們在前面的章節中，都是用一個一個的變數來儲存資料，但是如果我們要儲存很多筆資料，這樣的方式就會變得很麻煩。

所以這裡跟你介紹 **List(串列)**，它可以讓我們儲存很多筆資料，而且可以儲存不同的資料型態，例如: 數字、字串、布林值等等。

## Create a list
要建立一個 List，我們可以使用中括號 `[]`，並在中括號中放入我們要儲存的資料，資料之間用逗號 `,` 隔開。

來舉個例子，建立三個 List，一個都儲存整數，一個是都儲存字串；最後一個則放了不同的資料型態。

```python linenums="1"
numbers = [1, 2, 3, 4, 5]
print(numbers)

what_i_learned = ["C", "C++", "Python", "Java", "C#", "JavaScript", "TypeScript"]
print(what_i_learned)

student_info = ["Sean", 20, "Computer Science", 4.0, True, "aLIEz"]
print(student_info)

print(type(numbers), type(what_i_learned), type(student_info))
```

```linenums="1" title="ouput"
[1, 2, 3, 4, 5]
['C', 'C++', 'Python', 'Java', 'C#', 'JavaScript', 'TypeScript']
['Sean', 20, 'Computer Science', 4.0, True, 'aLIEz']
<class 'list'> <class 'list'> <class 'list'>
```

[Sawano Hiroyuki - aLIEz Aldnoah.Zero Full Lyrics](https://youtu.be/wtW529XbOyU?si=Es6dUQAervDKUzag)

如果你有學過其他的程式語言，你可能會聽過 **Array(陣列)**，List 就是 Python 中的 Array，但又更強大，因為 List 可以儲存不同的資料型態，而通常 Array 只能儲存一種資料型態。

題外話，當初從 C, C++, Java 轉到 Python 的時候，真心覺得怎麼可以這麼隨便，連型態都不用宣告，現在覺得真香。

## Operations
### Accessing elements
要存取 List 中的元素，我們可以使用中括號 `[]`，並在中括號中放入元素的索引值，索引值從 $0$ 開始，並且可以使用負數，負數的索引值是從最後一個元素開始算起。

```python linenums="1"
numbers = [1, 2, 3, 4, 5]

# First element
print(numbers[0])
# Last element
print(numbers[-1])
print(numbers[4])
```

```linenums="1" title="ouput"
1
5
5
```

讓我們配合迴圈來印出串列中的元素。

```python linenums="1"
numbers = [1, 2, 3, 4, 5]

for i in range(len(numbers)):
    print(numbers[i], end=' ')

```

```linenums="1" title="ouput"
1 2 3 4 5
```

`#!python len` 這個函式可以取得串列的長度，也就是串列中元素的個數。

不曉得你還記不記得 [Repetiton Structures - Foreach](repetition_structures.md#foreach) 的內容，我們用這個概念來印出串列中的元素。

```python linenums="1"
numbers = [1, 2, 3, 4, 5]

for number in numbers:
    print(number, end=' ')
```

```linenums="1" title="ouput"
1 2 3 4 5
```

### Slicing
**切片(Slicing)**可以用來取得串列中的一部分，例如:

```python linenums="1"
numbers = [1, 2, 3, 4, 5, 6]

print(numbers[0:4])
print(numbers[:4])
print(numbers[:-2])
print(numbers[1:3])
print(numbers[:6:2])
print(numbers[::-1])
print(numbers[:])
```

@EditTime : 2024-01-31 21:56

## To be continued...
不曉得你還記不記得，我們在前面的章節中，有提到 `#!python range` 這個函式，它可以產生一個整數的序列，例如: `range(5)` 會產生一個從 $0$ 到 $4$ 的整數序列。

`list(range(5))`