# LMcps Book

[Book link](https://cheung4843.github.io/LMcpsBook/)


## 協作規範

### 1. 資料夾規範
```
LMcps Book
│  .gitignore
│  mkdocs.yml
│  README.md
│
├─docs
│  │  about.md
│  │  index.md
│  │  license.md
│  │
│  ├─fundamental
│  │  │  index.md
│  │  │
│  │  ├─cpp
│  │  │  │  index.md
│  │  │  │
│  │  │  └─media
│  │  └─python
│  │      │  index.md
│  │      │  say_hello.md
│  │      │
│  │      └─media
│  │              cat_2.jpg
│  │              variable_1.mp4
│  │
│  ├─imgs
│  │      cat.jpg
│  │      lmcps.png
│  │      lmcps_brand.png
│  │      lmcps_brand_2.png
│  │
│  └─stylesheets
│          extra.css
└─site
```

每一個主題都會有一個資料夾，例如 `fundamental`，裡面會有一個 `index.md`，作為該主題的目錄，接著會有不同語言的資料夾，例如 `cpp` 與 `python`，都包含有各自的 `index.md`，作為目錄，以及擁有 `media` 資料夾，負責存放該主題的圖片跟影片。而其餘的 `.md` 檔案則是該主題的內容，例如 `say_hello.md`。

`imgs` 資料夾存放全域使用的圖片，若該圖片只會在某個主題使用，請放在該主題的 `media` 資料夾中。

`mkdocs.yml` 除了 `nav` 之外，其他的都不要動，`nav` 會決定左側的目錄結構。

`site` 資料夾已經被 `.gitignore` 忽略，請別上傳到 GitHub 上。

### 2. 命名規範
- 資料夾名稱：小寫英文，單字間以 `_` 連接。
- 檔案名稱：小寫英文，單字間以 `_` 連接。


### 3. Commit 規範
* `add: xxx`：

* `docs: xxx`：

### 4. 依賴項目
此專案使用python+mkdocs+mkdocs-material進行寫作，請確保你擁有必要的相關套件在進行寫作。

你可以透過下列指令安裝相關套件。
```bash
$ pip install mkdocs mkdocs-material                                                                                                                                ─╯
```

## 貢獻者

[cheung4843](https://github.com/cheung4843)

[Bloodnighttw](https://github.com/bloodnighttw)


