# 1. Hello World 

## Hello World (輸出)
首先，請在vscode (Visual studio code)中新增一個名為hello_world.cpp，並打入下列程式碼。
```cpp linenums="1"
#include <iostream>

using namespace std;

int main(){
    cout << "hello world!" << endl;
    return 0;
}
```
確認好存檔過後，按下右上角的執行按鍵，你就會成功看到你寫的第一支程式。

接著，我們將更深入討論這段程式，到底發生了什麼事情。

## Hello World程式解釋
在這段程式中，已經有許多稍微複雜的概念，但這邊礙於篇幅，以及講了你也聽不懂，我們就只要了解到:

1. 程式一定是從``int main(){......}``裡面開始執行的
2. 最後一定會有個``return 0;`` 代表程式成功結束。

讓我們焦點放在第六行

```cpp linenums="1" hl_lines="6"
#include <iostream>

using namespace std;

int main(){
    cout << "hello world!" << endl;
    return 0;
}
```

這邊有了我們的第一支程式，你可以把``cout``當成電腦螢幕的文字印表機，把``<<``當成傳遞的箭頭，而這段程式就是要把這段字傳給電腦印出。

這邊的``endl``代表著換行的意思，透過``<<``傳給電腦印表機。

!!! tip

    這邊提供另外一個換行的寫法，具體差異在熟悉語法後，會在另外一篇文章做說明。

    ```cpp linenums="1" hl_lines="6"
    #include <iostream>

    using namespace std;

    int main(){
        cout << "hello world!\n";
        return 0;
    }
    ```
    ``\n``為換行字元，在字元中有許多字元會有特定功用，會以``\``開頭，連結一個字母或數字，代表著跳脫字元，作為特殊用途使用。

細心如你，這是又要提問了，分號``;``又代表什麼意思？

分號``;``是告訴電腦說，這些指令跟下一個字元或下一行是分開的，不要把他連在一起，也因為有這東西，我們程式可以這樣寫。

```cpp linenums="1" hl_lines="6"
#include <iostream>

using namespace std;

int main(){
    cout << "hello world!\n"; cout << endl;
    return 0;
}
```

## 加入變數 (輸入)

### 讀取字串
```cpp linenums="1"
#include <iostream>

using namespace std;

int main(){
    string str;
    cin >> str;
    cout << str << endl;
    return 0;
}
```

按下執行，打入隨便一串文字，按下enter，你會發現你打的文字被印在螢幕上。

---
### 讀取數字
假如今天我們輸入的數字，則程式碼改成這樣。

```cpp linenums="1"
#include <iostream>

using namespace std;

int main(){
    int temp;
    cin >> temp;
    cout << temp << endl;
    return 0;
}
```

按下執行，打入隨便一個數字，按下enter，你會發現你打的一串數字被印在螢幕上。

!!! info
    如果今天打入的數字非常非常的大，你可能會發現印出來的數字跟打入的數字不一樣，期原因是溢位，這點我們會在下一章談到其原因與解法。
