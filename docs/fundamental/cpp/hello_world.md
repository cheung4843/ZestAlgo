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

如果今天打入的數字非常非常的大，你可能會發現印出來的數字跟打入的數字不一樣，這點我們會在下一章談到原因與解法。
