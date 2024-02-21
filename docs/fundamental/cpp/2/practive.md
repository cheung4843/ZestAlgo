# 練習

在經過前面的篇章，相信你對變數型態已經有一定的了解了！接下來我們將練習相關題目，以確保你真的有學進去！


!!! warning "先試著寫寫看，不會的先試著透過網路查詢並理解，真的不行或者寫完再來看詳解！"

## [簡單加法](https://zerojudge.tw/ShowProblem?problemid=a002)

```c++ linenums="1" title="範例程式"
#include <iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;

    return 0;
}


```

## [糟糕，我發燒了！](https://zerojudge.tw/ShowProblem?problemid=d051)

這邊的``fixed``是強制``cout``使用小數點輸出浮點數，``setprecision(3)`` 則是告訴``cout``，印到小數點下第三位！

而第11行的 ``(double)(n-32)``，代表強制轉型，把n-32換成浮點數的型態，讓後面的計算會有小數點，這邊請記住，**整數的四則運算只會有整數，而浮點數的四則運算一樣也只有浮點數！**，整數除上任何一個整數，是不可能出現浮點數的！

```C++ linenums="1" title="範例程式"
// https://zerojudge.tw/ShowProblem?problemid=d051

#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int n;
    cin >> n;
    double ans = (double)(n-32) * 5 / 9;
    cout<< fixed
        << setprecision(3) 
        << ans
        << endl;

    return 0;
}
```
