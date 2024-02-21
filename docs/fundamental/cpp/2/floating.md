# 浮點數型態


在前面的篇章，相信你對小數點的儲存不陌生了，那如果今天要存的是有小數點的數字？

在很久很久很久以前，小數點的存法是沒有標準的，但經過時間的演變過後，人們發現過於混亂，於是共同制定了一個共同的存法，而這個標準就是 IEEE 754。

## 科學記號
在談到IEEE 754的標準前，我們先來談一下科學記號，因為科學記號的許多精髓與IEEE 754相近。

如果我們要用必須用科學記號表示一個變數，必然會是這種形式。

$$ -1001 = -1.001 * 10^3 $$

$$ 0.001 = 1*10^{-3} $$

這是對於十進位時的狀況，如果今天是二進位的話，**二進位的**科學記號要長這樣：

$$ 0.5_{10} = {1 * 2^{-1}} = 0.1_2$$

而IEEE 754就是依照這個形式定義的。


## IEEE 754





### 單精度
單精度使用**4byte**做存儲，第一個**bit**儲存正負的資訊，接下來的**7**個**bit**儲存指數的資訊（例如：$1.0*2^{-1}的^{-1}$），剩下的部份儲存實數的資訊（例如：$1.0*2^{-1}的1$）。
下方為$1.0*2^{-1}$在記憶體中的狀態。

<table>
    <tr>
        <td style="border-color:red">0</td>
        <td style="border-color:yellow">0</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td >...</td>
    </tr>
</table>

ㄟ，黃色的部份應該為-1嗎？為何轉換成10進位為62?

這是因為規範規定了，黃色內的值還要再**剪上$2^{7-1}-1=63$**才會是我們要的指數，**這七格並不照著前一章負數規則走(也沒有必要)。**

接著你應該會有第二個疑問？為何剩餘的實數部份皆為0。

讓我們回想看看科學記號，其實它還可以簡化成$(1+a)*10^b\space_{0 \le a < 1}$這個形式，而我們其實只要儲存a的部份就好了，這邊也是這個道理。

需要注意的是，0.0在IEEE中定義為全部的bit都為0，如表格所示：
<table>
    <tr>
        <td style="border-color:red">0</td>
        <td style="border-color:yellow">0</td>
        <td style="border-color:yellow">0</td>
        <td style="border-color:yellow">0</td>
        <td style="border-color:yellow">0</td>
        <td style="border-color:yellow">0</td>
        <td style="border-color:yellow">0</td>
        <td style="border-color:yellow">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td >...</td>
    </tr>
</table>

浮點數當中還有一個特別的數，我們稱為它為Not a Number，或者又叫做NaN，根據定義，為所有的bit都為1，如表格所示:
<table>
    <tr>
        <td style="border-color:red">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:blue">1</td>
        <td style="border-color:blue">1</td>
        <td style="border-color:blue">1</td>
        <td style="border-color:blue">1</td>
        <td style="border-color:blue">1</td>
        <td style="border-color:blue">1</td>
        <td style="border-color:blue">1</td>
        <td style="border-color:blue">1</td>
        <td style="border-color:blue">1</td>
        <td style="border-color:blue">1</td>
        <td style="border-color:blue">1</td>
        <td style="border-color:blue">1</td>
        <td >...</td>
    </tr>
</table>


### 誤差

細心的你在這邊應該會注意到，有些數其實是不能被有限的二進位小數表示的，像是0.3，轉成二進位的話會是無限小數,而這種存法是沒辦法存**無限多**個小數的，所以某些位元後勢必會被捨棄，而造成與輸入不一樣，造成誤差的發生，下方為這類誤差的最經典問題相關連結：

[(0.1+0.2=0.30000000000000004)](https://0.30000000000000004.com/)

總而言之，無論如何請記住這句話:

!!! danger ""
    算錢用浮點，遲早被人扁！

那有哪些方法，可以使其算的更準一些？

加大精準度，而事實上，我們可以加大他的精準度。

### 雙精度
單精度使用**4byte**做儲存，第一個**bit**儲存正負的資訊，接下來的**7+4=11**個**bit**儲存指數的資訊（例如：$1.0*2^{-1}的^{-1}$），剩下的部份儲存實數的資訊（例如：$1.0*2^{-1}的1.0$）。
下方為$1*2^{-1}$在記憶體中的狀態。

<table>
    <tr>
        <td style="border-color:red">0</td>
        <td style="border-color:yellow">0</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">1</td>
        <td style="border-color:yellow">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td style="border-color:blue">0</td>
        <td >...</td>
    </tr>
</table>

黃色的部份轉成10進位為1022，再剪上**剪上$2^{11-1}-1=1023$**，會等於**-1**。

### 總結

依據IEEE 754的規範，浮點數的值會等於

$$ 正負（紅色的部份）* (1.藍色得部份)*2^(黃色的部份剪上特定值)$$

## C/C++中的浮點數
C/C++除了提供了兩種精度的浮點數，分別為``float``和``double``，分別對應單精度與雙精度，還有提供更大範圍的精度，一般而言，double就已經很夠用了，但如果你需要更大的精準度，或者更大的範圍，你可以使用``long double``。


!!! success "reference"
    1. https://en.cppreference.com/w/cpp/language/types#Range_of_values