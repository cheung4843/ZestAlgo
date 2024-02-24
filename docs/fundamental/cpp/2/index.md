# 型態、變數與相關運算

在前一章中，你應該會對變數有相關的概念，這一章我們將更深入討論這些東西。

## 型態宣告

正如前一篇所述，當我們需要使用一個變數，要先做宣告，做宣告的方式為:
```cpp linenums="1"
<型態名稱> <變數名稱>;
```
例如今天我們要宣告一個整數型態的變數，就要這樣寫:
```cpp linenums="1" hl_lines="6"
#include <iostream>

using namespace std;

int main(){
    int number;
    return 0;
}
```

如果今天要指定一個初始值，則要這樣寫:
```cpp linenums="1" hl_lines="6"
#include <iostream>

using namespace std;

int main(){
    int number = 0;
    return 0;
}
```

!!! danger "印出一個沒有給值的變數"

    讓我們試著印出它:

    ```cpp linenums="1" hl_lines="7"
    #include <iostream>

    using namespace std;

    int main(){
        int number;
        cout << nunber << endl;
        return 0;
    }
    ```
    請多執行幾次，你會發現，每次執行的結果好像都沒有規則。

    這是因為在在c/c++中，一個變數如果沒有給初始值，那麼他的值就是未定的，而不會自動給0，以上面的程式為例，如果沒有給定初始值，那他有可能是1 ，也可能會是-10235，所以除非你**非常確定**這個變數在後面會**馬上改變**成一個可知的狀態(像是``cin``輸入進去變數)，不然請**一律**參考有給初始值的寫法，以避免出錯。

## 型態類別
一般而言，常使用的型態有可分為五類，分別為``整數型態``、``小數型態``、``字元型態``、``陣列型態``、和``字串型態``，再接下來的幾篇文章，我們將會著墨於他們是如何存在電腦的，以及他們的相關特性。