# 陣列

在前面的章節，我們了解如何宣告變數，那讓我們設想一個狀況，我們今天要宣告100000個變數，該不會只能這樣做吧？

```c++ linenums="1" hl_lines="7"

#include <iostream>

using namespace std;

int main(){

    int a1,a2,a3,a4,......,a99999,a100000;

    return 0;
}

```

想也知道我們不可能這樣作對吧！
而且這樣還有延伸一個問題，要如何取得第n個變數的值？

## 陣列的概念

在程式中，我們可以宣告**一連串的記憶體**，來給程式使用，我們稱其為陣列。

## 一維陣列

### 宣告

那讓我們回到一開始的問題，宣告100000個變數，我們只要這樣做，並存取它。

```c++ linenums="1"

#include <iostream>

using namespace std;

int main(){

    int a[100000];

    a[0] = 1; //write into memory

    cout << a[0] << endl;

    return 0;
}

```

??? success "註解"
    這邊``//``為註解，它會省略``//``後面的內容，直到下行，不做執行。同樣的東西有用``/*`` ``*/``包父的程式，用這兩個東西包覆的片段也不會被執行，下方為範例。

    ```c++ linenums="1"

    #include <iostream>

    using namespace std;

    int main(){

        int a[100000];

        a[0] = 1; //write into memory

        /*cout << a[0] << endl;*/

        return 0;
    }

    ```

??? danger "常見的錯誤"

    如果你沒有給定值就做存取，那你也會遇到未給值得相關錯誤，如同前面對變數的描述一樣。

    ```c++ linenums="1"

    #include <iostream>

    using namespace std;

    int main(){

        int a[100000];

        a[0] = 1; //write into memory

        cout << a[1] << endl;

        return 0;
    }

    ```

    這邊的輸出會不固定！

這邊有個點需要注意，存取array都是從0開始的，以上方的程式為例，要存取最後一個陣列元素的方法為：

```c++ linenums="1"

#include <iostream>

using namespace std;

int main(){

    int a[100000];

    a[99999] = 1; //write into memory

    cout << a[99999] << endl;

    return 0;
}

```

### 超出陣列範圍
下方的程式為超出陣列應該存取的範圍 （0~99999），會根據不同的作業系統（及版本），出現不同的處理方式，有報錯的，有乾脆不處理的。

```c++ linenums="1" title="錯誤程式"

#include <iostream>

using namespace std;

int main(){

    int a[100000];

    a[100000] = 1; //error

    cout << a[100000] << endl; //error

    return 0;
}

```

請注意，這個錯誤常是我們寫程式的誤區，在撰寫程式時，**請務必確保會存取到有效的範圍**。

## 二維陣列

### 宣告

事實上，陣列不侷限於一維，它也可以是二維的狀態，下方為範例程式：

```c++ linenums="1"

#include <iostream>

using namespace std;

int main(){

    int a[100][100];

    a[0][0] = 1; //write into memory

    cout << a[0][0] << endl; 

    return 0;
}

```

### 超出陣列範圍

```c++ linenums="1" title="錯誤程式"

#include <iostream>

using namespace std;

int main(){

    char a[100][100];

    a[0][100] = 'a'; //write into memory

    cout << a[1][0] << endl; // output not random, print 'a' here 

    return 0;
}

```
此程式會印出 a，而不是有相關錯誤，這是為何？

記不記得前面所說，陣列為**一連串**的記憶體空間，所以它分配了**一連串**程式能用的空間，[0][100]所在的實際位置位於[1][0]，所以才不會有嚴重的錯誤，不過請注意，平時撰寫時，也盡量不要出現這樣的錯誤，畢竟會出現這樣的寫法，八成是你寫錯了！

而下方程式就會出現超出陣列的錯誤，因為已經超出能使用的範圍：
```c++ linenums="1"

#include <iostream>

using namespace std;

int main(){

    int a[10][10];

    a[10][10] = 1; //error

    cout << a[10][10] << endl; //error

    return 0;
}
```

## 多維陣列

### 宣告

```c++ linenums="1"

#include <iostream>

using namespace std;

int main(){

    int a[100][100][10];

    a[0][99][9] = 1; //write into memory

    cout << a[0][99][9] << endl; 

    return 0;
}

```

## 常見錯誤

你或許在其他地方看過這樣的程式，用於宣告一個不固定大小的陣列。

```c++ linenums="1"
#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    int arr[n];

    return 0;
}
```

然而，這個寫法存在一個問題，這種程式編譯器通常會自動把arr分配的大一點，因為編譯器不知道``n``長怎樣，所以只好配一個有點大的大小給這個陣列，我們會在未來的記憶體篇章來詳細敘述為啥會出現這個情況。

而你在這邊要知道，這個寫法，**不一定**會正確。

## 練習