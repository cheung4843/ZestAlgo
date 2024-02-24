# 字串

## 字元陣列
一段字，是複數個字母（或稱：字元）所組成，所以我們要顯示一段字，可以宣告字元陣列來儲存。

```c++ linenums="1" title="字元陣列範例程式"

#include <iostream>

using namespace std;

int main(){

    char arr[] = {'g','o','o','d'};

    cout << arr << endl;

    return 0;
}

```

```title="Output"
good


```



## 字串

在C++中，字串來的比字元陣列好用，他與字元陣列相似，但比字元陣列好用許多！

需要注意的是，字串的結尾，**必定是用跳脫字元``\0``做結尾**，用以表示這邊是字串的最後面。

<table>
    <tr>
        <td style="border-color:yellow">H</td>
        <td style="border-color:yellow">e</td>
        <td style="border-color:yellow">l</td>
        <td style="border-color:yellow">l</td>
        <td style="border-color:yellow">o</td>
        <td style="border-color:yellow"> </td>
        <td style="border-color:yellow">W</td>
        <td style="border-color:yellow">o</td>
        <td style="border-color:yellow">r</td>
        <td style="border-color:yellow">l</td>
        <td style="border-color:yellow">d</td>
        <td style="border-color:yellow">\0</td>
    </tr>
</table>

下方為相關程式的範例：

```c++ linenums="1" title="字串範例程式"

#include <iostream>

using namespace std;

int main(){

    string str = "Hello World";

    a[0] = 1; //write into memory

    cout << "Size: " << str.size() << endl; // 讀取字串有多少字
    cout << "str[11]: " << str[11] << endl; // 存取字串的第11個字元，也就是跳脫字元'\0'
    cout << "str[0]: " << str[0] << endl; // 存取字串的第0個字元

    return 0;
}

```

```title="Output"
11

H
```