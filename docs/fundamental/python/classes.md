# Classes
## Introduction
回想 [Variable and Input - Variable](variable_and_input.md#variable) 中所講的:

!!! quote
    在 Python 中，一切都是物件。

在 Python 中，我們可以自己定義一個新的物件，這個物件的定義方式就是**類別(Class)**，它就像是一個藍圖，可以用來創建物件。而依此創造出的物件就是**實體(Instance)**。

## Define a Class

舉個例子，我想要定義一個類別 `Ship`，擁有*屬性(Attribute)* `hp, name, speed`，以及方法(Method) `move` 和 `stop`。

```python linenums="1"
class Ship:
    # Class attribute
    max_no_flags = 3

    def __init__(self, hp, name, speed):
        # Instance attribute
        self.hp = hp
        self.name = name
        self.speed = speed

    # Method
    def move(self):
        print(f"{self.name} is moving at speed {self.speed}.")

    def stop(self):
        self.speed = 0
        print(f"{self.name} has stopped.")


# Create instances
Titanic = Ship(120, "Titanic", 21)
Carpathia = Ship(100, "RMS Carpathia", 14)
# Access class attributes
print(Ship.max_no_flags)
print(Titanic.max_no_flags)
Ship.max_no_flags = 4
print(Carpathia.max_no_flags)
# Access instance attributes
print(Titanic.name)
print(Carpathia.name)
# Call methods
Titanic.move()
Carpathia.stop()
```

``` title="Output" linenums="1"
3
3
4
Titanic
RMS Carpathia
Titanic is moving at speed 21.
RMS Carpathia has stopped.
```

[Céline Dion - My Heart Will Go On](https://youtu.be/9bFHsd3o1w0?si=iQKn0Vx1p4tmjdP7)

`max_no_flags` 是一個**類別屬性(Class attribute)**，它是屬於類別 `Ship` 的，只要是 `Ship` 的實體都可以存取，然而只要 `Ship` 修改了它，所有的實體都會受到影響。

`hp, name, speed` 是**實體屬性(Instance attribute)**，它們是屬於 `Ship` 的實體，每個實體都有自己的 `name` 和 `speed`。

`move` 和 `stop` 是**實體方法(Instance method)**，它們是屬於 `Ship` 的實體，可以被 `Ship` 的實體呼叫。

`self` 是一個特殊的參數，它代表了實體本身。

`__init__` 是一個特殊的方法，當我們創建一個新的實體時，它會在創建實體時自動被呼叫來初始化實體。但它並非是必要的，你也可以不寫。

你可能有學過其他語言，聽過**建構子(Constructor)**這個名詞，概念類似。

## Inheritance
如果我還想要再定義一個類別 `BattleShip`，它擁有所有 `Ship` 的屬性和方法，但是還有一些額外的屬性和方法，我又不想整個重寫一次，這時候就可以用到**繼承(Inheritance)**。

```python linenums="1"
from random import random


class Ship:
    max_no_flags = 3

    def __init__(self, hp, name, speed):
        # Instance attribute
        self.hp = hp
        self.name = name
        self.speed = speed

    def move(self):
        print(f"{self.name} is moving at speed {self.speed}.")

    def stop(self):
        self.speed = 0
        print(f"{self.name} has stopped.")


class BattleShip(Ship):
    def __init__(self, hp, name, speed, max_speed, damage, defense, acc):
        super().__init__(hp, name, speed)
        self.max_speed = max_speed
        self.damage = damage
        self.defense = defense
        self.acc = acc

    # Overriding the move method
    def move(self, acceleration=1):
        if self.speed < self.max_speed:
            self.speed += acceleration
        self.speed = min(self.speed, self.max_speed)
        print(f"{self.name} is moving at speed {self.speed}.")

    def stop(self):
        self.speed = 0
        print(f"{self.name} has stopped.")

    # New method
    def fire(self, target):
        if random() <= self.acc:
            damage = self.damage - target.defense
            print(f"{self.name} hit {target.name} for {damage} damage.")
            target.hp -= damage
            if target.hp <= 0:
                print(f"{target.name} has been destroyed.")
        else:
            print(f"{self.name} missed {target.name}.")


Bismarck = BattleShip(500, "Bismarck", 0, 30, 30, 10, 0.8)
Yamato = BattleShip(650, "Yamato", 0, 27, 41, 12, 0.6)

Bismarck.move(5)
Bismarck.fire(Yamato)
Yamato.fire(Bismarck)
Bismarck.stop()

print(type(Bismarck))
```

``` title="Possible Output" linenums="1"
Bismarck is moving at speed 5.
Bismarck hit Yamato for 18 damage.
Yamato missed Bismarck.
Bismarck has stopped.
<class '__main__.BattleShip'>
```

[SABATON - Bismarck](https://youtu.be/oVWEb-At8yc?si=prw7INCve_NwAZF6)

只要在定義 `BattleShip` 時，把 `Ship` 放在括號裡，就可以讓 `BattleShip` 繼承 `Ship` 的所有屬性和方法。

這裡我從 `random` 模組中引入了 `random` 函數，它可以隨機產生一個 $[0, 1)$ 之間的浮點數，來模擬射擊的準確度。

`BattleShip` 繼承了 `Ship`，所以它擁有 `Ship` 的所有屬性和方法，還多了一些自己的屬性和方法。其中 `move` 方法被**覆寫(Overriding)**了，這樣 `BattleShip` 的實體呼叫 `move` 方法時，會呼叫 `BattleShip` 的 `move` 方法，而不是 `Ship` 的。而新方法 `fire` 只有 `BattleShip` 有。

`#!python super()` 是一個特殊的工具，它取得父類別，因此我們在 `BattleShip` 的 `__init__` 方法中可以呼叫 `Ship` 的 `__init__` 方法。

## Encapsulation
在 Python 中，我們無法像其他語言一樣，對屬性設定存取權限，但是我們可以用**命名規則(Naming Convention)**來告訴使用者，哪些屬性是不應該直接存取的。

在 Python 中，我們可以用**屬性名稱重整(Name Mangling)**來達到這個目的，只要在屬性名稱前面加上兩個底線 `__`，Python 就會把它改名成 `_類別名稱__屬性名稱`，這樣就不容易被存取到。

```python linenums="1"
class Ship:
    def __init__(self, hp, name, speed):
        self.__hp = hp
        self.__name = name
        self.__speed = speed

    def get_hp(self):
        return self.__hp

    def set_hp(self, hp):
        if hp > 0:
            self.__hp = hp
        else:
            print("HP must be greater than 0.")
```

To be continued...

## Practice
其實這章我不太清楚要教到哪個地步，因為這是偏開發的東西，但我是想教你解題，所以內容還會再變動，但至少你應該知道怎麼定義類別，以及怎麼用屬性和方法。

下面的練習，其實也可以不用類別來寫，但我想讓你熟悉一下類別的使用。

!!! success ""
    Itsa - [[C_AR76-易] 提款機程式](https://e-tutor.itsa.org.tw/mod/programming/view.php?a=1681)

??? abstract "Reference code"
    ```python linenums="1"

    class ATM:
        def __init__(self, data):
            self.accounts = {}
            for account, password, money in data:
                self.accounts[(account, password)] = money

        def get_money(self, account, password):
            if (account, password) in self.accounts:
                print(self.accounts[(account, password)])
            else:
                print('error')


    data = [[123, 456, 9000], [456, 789, 5000], [789, 888, 6000], [336, 558, 10000], [775, 666, 12000],
            [566, 221, 7000]]

    atm = ATM(data)
    N = int(input())

    for _ in range(N):
        account, password = map(int, input().split())
        atm.get_money(account, password)
    ```

!!! success ""
    Itsa - [[C_AR97-易] 矩陣分素乘積](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=13735)

??? abstract "Reference code"
    ```python linenums="1"

    class Matrix:
        def __init__(self, matrix):
            self.matrix = matrix
            self.rows = len(matrix)
            self.cols = len(matrix[0])

        def entrywise_product(self, other):
            result = [[0 for _ in range(self.cols)] for _ in range(self.rows)]

            for i in range(self.rows):
                for j in range(self.cols):
                    result[i][j] = self.matrix[i][j] * other.matrix[i][j]

            return Matrix(result)


    m, n = map(int, input().split())
    mat1 = [list(map(int, input().split())) for _ in range(m)]
    mat2 = [list(map(int, input().split())) for _ in range(m)]

    matrix1 = Matrix(mat1)
    matrix2 = Matrix(mat2)

    result = matrix1.entrywise_product(matrix2)

    for row in result.matrix:
        print(*row)
    ```

    `*` 在這裡稱為 *Unpacking Operator*


## Assignment

!!! success ""
    Itsa - [[C_AR74-中] 學生資料搜尋程式](https://e-tutor.itsa.org.tw/mod/programming/view.php?id=3696)

??? tip
    不用怕，你可以的。