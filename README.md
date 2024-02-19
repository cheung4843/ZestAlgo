# ZestAlgo Book

[Book link](https://cheung4843.github.io/ZestAlgo/)


## 環境設定
* python 3.12.1
* mkdocs 1.5.3
* mkdocs-material 9.5.5
* mkdocs-git-revision-date-localized-plugin 1.2.4
* mkdocs-git-committers-plugin-2 2.2.3

請先確保電腦有安裝 python 3.12.1 或以上的版本，接著安裝其他必要套件。

```bash
pip install mkdocs
pip install mkdocs-material
pip install mkdocs-git-revision-date-localized-plugin
pip install mkdocs-git-committers-plugin-2
```

## 協作規範
請先至[協作請求通知](https://github.com/cheung4843/LMcpsBook/discussions/16)，告訴我您的計畫，並等待我們的回覆。

因為我們希望能夠保持對新手友善的文章風格，所以希望您能將文章寫得盡可能的簡單易懂，並且能夠提供一些範例程式碼，以及一些簡單的練習題。

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
│  │  │  │  create_env.md
│  │  │  │  index.md
│  │  │  │
│  │  │  └─media
│  │  │          env1.png
│  │  │          env2.png
│  │  │          env3.png
│  │  │          env4.png
│  │  │          install1.png
│  │  │          install2.png
│  │  │          install3.png
│  │  │          vscode_ext.mp4
│  │  │          warning.png
│  │  │
│  │  └─python
│  │      │  index.md
│  │      │  operators.md
│  │      │  say_hello.md
│  │      │  selection_structures.md
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
│
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
第一行根據操作類型分為四種，分別為 `add`、`modified`、`delete`、`feat`，第二行為說明修改的詳細內容。

* add: file name 1, file name 2,...etc
* modified: file name 1, file name 2, ... etc
* delete: file name 1 , file name 2, ... etc
* feat: feature description


例如: 

```git
modified: say_hello.md
修正部分拼字錯誤。
```

留意: `feat` 是指新增功能，例如可以使用MathJax，或是允許快速查看原始碼等。

## 貢獻者

<a href="https://github.com/cheung4843/LMcpsBook/graphs/contributors">
<img src="https://contrib.rocks/image?repo=cheung4843/LMcpsBook"/>
</a>

