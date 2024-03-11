# Tkinter
## 視窗
想要做出一個介面，首先你要有一個視窗，請參考以下的程式碼來建立一個視窗。

```python linenums="1"
import tkinter as tk

root = tk.Tk()   
root.mainloop()  
```

執行程式後，你就會得到一個什麼都沒有的視窗，接下來讓我們來做點調整。

```python linenums="1"
import tkinter as tk

root = tk.Tk()  
root.title('window')    
root.geometry("600x600")   
root.mainloop()  
```

利用 title 為視窗命名， geometry 設定視窗大小，這部分可以按照自己的喜好來修改。

接下來讓我們來幫空蕩蕩的視窗加點東西。

## Label
首先是加個文字:

```python linenums="1"
import tkinter as tk

root = tk.Tk()  
root.title('window')    
root.geometry("600x600")   
world = tk.Label(root, text="hello")
world.pack()
root.mainloop()  
```

有了文字後，我們來設定字體、大小和顏色。

```python linenums="1"  
world = tk.Label(root, text="hello", font=("Arial", 14), fg="blue")
```

接著調整文字的位置，我會教你兩種方式:相對位置和絕對位置。

先說相對位置

```python linenums="1"  
world.pack(padx=10, pady=10, anchor='nw')
```

執行後你會發現文字靠左上方，並且可以用 padx 和 pady 來調整文字和左上視窗的間距。

n (上)、s (下)、w (左)、e (右)、ne、nw、sw、se、center 

再來是絕對位置

```python linenums="1"  
world.place(x=10, y=10)
```

除此之外還有其他的位置設置方式，有興趣的可以自行研究。

## Entry and Text
那要怎麼在介面上添加文本框呢?

有兩種方式 ，Entry 和 Text 。

Entry 是用來輸入一行文本， Text 則是多行文本，以下是範例程式。

### Entry
```python linenums="1"  
world_box = tk.Entry(root)
world_box.pack(padx=10, pady=50, anchor='nw')
```

### Text
```python linenums="1"  
world_box = tk.Text(root, width=10, height=5)
world_box.pack(padx=10, pady=50, anchor='nw')
```

各位可能會好奇說要怎麼得到文字框內的字串，這部分會在教完設置按鈕後提到。









