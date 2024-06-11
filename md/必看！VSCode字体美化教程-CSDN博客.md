> 本文由 [简悦 SimpRead](http://ksria.com/simpread/) 转码， 原文地址 [blog.csdn.net](https://blog.csdn.net/m0_46491549/article/details/134024757)

> 文章浏览阅读2.2w次，点赞39次，收藏92次。VSCode是一款轻量级开源编辑器，在Windows版本中默认的UI其显示效果肯定是没有在Mac中好的，其中一个重要的原因就是Mac所使用的中文字体苹方和英文字体SF Pro以及Mac独特的渲染机制，使得界面看起来更加舒适美观，所以本期教程教授大家如何更换VSCode的界面字体，以达到在Win平台下所能达到最佳的视觉体验。_vscode字体

必看！VSCode 美化教程😍
----------------

#### 🆙2024 更新

fix: 修复右键菜单字体没有生效的问题

![](https://img-blog.csdnimg.cn/direct/4c3fbe339d5041369c4c4084c65ab836.png)

### 前言

VSCode 是一款轻量级开源编辑器，在 Windows 版本中默认的 UI 其显示效果肯定是没有在 Mac 中好的，其中一个重要的原因就是 Mac 所使用的中文字体 `苹方` 和英文字体 `SF Pro` 以及 Mac 独特的渲染机制，使得界面看起来更加舒适美观，所以本期教程教授大家如何更换 VSCode 的界面字体，以达到在 Win 平台下所能达到最佳的视觉体验。

觉得教程对小伙伴有帮助的记得动动小手点个赞或者收藏哦！

### 效果图

首先先直接上效果图。

#### 默认界面

在 windows 下默认界面的中文字体为 Microsoft Yahei，即微软雅黑，英文字体为 Segoe UI，代码字体为 Consolas

![](https://img-blog.csdnimg.cn/a12f9f225f694c3092dc6ab429e44dbc.png)

![](https://img-blog.csdnimg.cn/8bd8e823dc7a41f491ca69724592f20f.png)

#### 美化后的界面

美化后的界面，中文字体为鸿蒙字体，英文为 Inter，代码字体为 Jetbrains Mono

![](https://img-blog.csdnimg.cn/4b47566c94fd4d048e4d35613588b4ca.png)

![](https://img-blog.csdnimg.cn/1f2b3af933764950a19d271a000b67b6.png)

好了，接下来赶紧进入教程吧~

### 步骤〇 更换文件图标主题

该风格为 JetBrains 全家桶系列软件新的产品图标，在 VSCode 插件仓库搜索 JetBrains Icon Theme 即可

![](https://img-blog.csdnimg.cn/direct/c46e59957d174ba99aea8eae0c24242f.png)

![](https://img-blog.csdnimg.cn/direct/71781d4453ac4d51a48fc3af9a2d5af6.png)

### 步骤一 准备字体

默认界面的中文字体是微软雅黑，英文是 Segoe UI，所以我们对应的也要寻找美观大方的黑体字，这里我推荐英文字体使用 Inter 字体，中文字体使用鸿蒙字体

#### Inter 字体

官网链接：[https://rsms.me/inter](https://rsms.me/inter)  
之所以选择 Inter 字体是因为其视觉效果与 Mac 的 SF Pro 字体有着相似的字形，在多重分辨率下仍具辨识度，更有利于保证内容在屏幕上的显示效果，因此许多知名软件也使用了这款字体。  
例如 **Postman**，著名的原型设计软件 **Figma**，还有 JetBrains 最新全家桶，例如 **IDEA**、**Webstorm** 等也是用 Inter 作为默认的 UI 字体，等等…

![](https://img-blog.csdnimg.cn/c66d761bc9384d10a38e5b11216ffe85.png)  
排版效果  
![](https://img-blog.csdnimg.cn/92dc5921675e40beb73975614dbdea0c.png)

#### SF Pro 字体（仅做了解）

Apple 官网现在用的就是这款英文字体

![](https://img-blog.csdnimg.cn/direct/9a997b55e381429b9610cfa5044fcd67.png)

![](https://img-blog.csdnimg.cn/ed7365848aaf4aa2bf62c323e4deec30.png)

#### 鸿蒙字体

由华为开源的一款不错的中文字体，其他厂商开源的（例如小米的 MiSans、OPPO 的 OPPO Sans、阿里巴巴的普惠体）也可以自行选择

![](https://img-blog.csdnimg.cn/8f8c69ce695349ff8ee94095bb594d60.png)

Q: 鸿蒙也自带英文字体，为什么不直接用鸿蒙的？  
A: 因为鸿蒙的英文字体作为用于 UI 界面的字体而言还是没有 Inter 的宽度和字形舒服，博主还是更加推荐 Inter 字体

#### JetBrains Mono

比起默认的 Consolas 代码字体，我更推荐使用 JetBrains Mono 字体，由 IDEA 的开发公司 JetBrains 所设计和开源

![](https://img-blog.csdnimg.cn/fcf213dd839e44868428759e225b68d3.png)

支持连字特性，更加利于阅读

![](https://img-blog.csdnimg.cn/35122b78912f4e34a91d6a2b213a5fab.png)

#### 下载地址

**Inter 下载:**  
由于 Inter 是开源字体，所以可以到 GitHub 下载，或者从网上搜索下载  
下载地址： [https://github.com/rsms/inter/releases/](https://github.com/rsms/inter/releases/)  
下载完成后**解压**，**选中以下三个字体** → 右键 “**为所有用户安装**” 即可

![](https://img-blog.csdnimg.cn/direct/365419d251eb430c835a5c24fc4aa2d7.png)

**HarmonyOS Sans**  
由于鸿蒙字体是开源字体，所以可以到官网直接下载、从网上搜索下载  
下载地址：  
[https://developer.harmonyos.com/cn/design/resource/](https://developer.harmonyos.com/cn/design/resource/)  
下载完成后**解压**，**选中以下字体** → 右键 “**为所有用户安装**” 即可

![](https://img-blog.csdnimg.cn/direct/bf5dc247d3e6407a839b0907cee77a88.png)

**JetBrains Mono**  
由于 JetBrains Mono 是开源字体，所以可以到官网直接下载或者到 github 下载，也可以在网上搜索下载  
下载地址：  
[https://www.jetbrains.com/zh-cn/lp/mono/](https://www.jetbrains.com/zh-cn/lp/mono/)

下载完成后**解压**到任意位置 **打开 ttf 文件夹 → Ctrl+A 全选然后右键 → 为所有用户安装** 即可

![](https://img-blog.csdnimg.cn/direct/6a03a484bded425fa793c994ac22ec86.png)

### 步骤二 更换字体

#### 打开 vscode css 文件

打开 VsCode 安装目录，按照下图或者类似路径定位到 `workbench.desktop.main.css`，如果你是默认安装的话则路径为以下路径

```
C:\Program Files\Microsoft VS Code\resources\app\out\vs\workbench\workbench.desktop.main.css


```

以下为每层目录的点击过程

1.  进入 resources 文件夹  
    ![](https://img-blog.csdnimg.cn/cab0de22306244d592d4d3ba7d00b430.png)
    
2.  进入 app 文件夹
    

![](https://img-blog.csdnimg.cn/f3aa0a60c6084ea8b0cfdd5558388521.png)

3.  进入 out 文件夹

![](https://img-blog.csdnimg.cn/3190312336ed4f19b329c1a55e379d59.png)

4.  进入 vs 文件夹  
    ![](https://img-blog.csdnimg.cn/907f2ec3e8df44708c6d99909a91a4eb.png)
5.  进入 workbench 文件夹  
    ![](https://img-blog.csdnimg.cn/c243f3d28e5c48118a0ff20a50c11dfa.png)
6.  进入 api 文件夹，找到 workbench.desktop.main.css  
    ![](https://img-blog.csdnimg.cn/51b1cbf53778408b93cd8490d6463ba9.png)  
    然后右键用 VSCode 打开

#### 修改 css 代码

Ctrl + F 定位到这段代码

```
.windows:lang(zh-Hans){font-family:Segoe WPC,Segoe UI,Microsoft YaHei,sans-serif}


```

然后修改为

```
.windows:lang(zh-Hans){font-family:Inter,HarmonyOS Sans SC,Segoe WPC,Segoe UI,Microsoft YaHei,sans-serif}


```

**注意：英文字体的名称在前，中文字体的名称在后，上述为 Inter, HarmonyOS Sans SC，即使用 Inter 的英文字体和 HarmonyOS Sans SC 的中文字体（即 Inter 没有的字符则使用 HarmonyOS Sans SC 的字符候补）**

然后，由于此时编辑器的右键菜单样式不会受到上述 css 影响，因此还要单独修改，直接在当前 css（workbench.desktop.main.css）最后一行加上这段 css 即可

```
.shadow-root-host {
	font-family: Inter, HarmonyOS Sans SC;
}


```

**❗❗❗注意以下所有配置不要写 HarmonyOS Sans，要写 HarmonyOS Sans SC（图片上没有 SC，博主此处声明更正）**

Ctrl + S 保存，提示权限不足，点击 “以管理员身份重试”

![](https://img-blog.csdnimg.cn/5752620fd6c342c4844b7b9154c7df9e.png)

#### 重启 VS Code

然后关闭 VSCode 重新打开，右下角会显示 vs code 似乎已损坏，可以点击设置按钮然后点击 “不再提醒”

![](https://img-blog.csdnimg.cn/123ac3b29f454fe292d8f8fd30c8f63e.png)  
到此处 VSCode 的 UI 界面字体就配置完成了，接下来配置代码的字体，即

#### 设置代码字体

接下来设置一下代码字体，代码的字体一般会显示在编辑器和 VSCode 的终端中，由于 VSCode 编辑器区域默认没有设置中文字体，所以默认中文字体显示宋体，英文字体默认设置为 Consolas

![](https://img-blog.csdnimg.cn/8bd8e823dc7a41f491ca69724592f20f.png)

接下来我们打开设置

![](https://img-blog.csdnimg.cn/f155bc92762645cf86a2b1eb7e14c86a.png)

可以看到默认的字体设置是

```
Consolas, 'Courier New', monospace


```

![](https://img-blog.csdnimg.cn/5c202c2d51184a36aba94e51b0adc54b.png)  
我们将其改为：

```
JetBrains Mono, HarmonyOS Sans SC, Consolas, 'Courier New', monospace


```

![](https://img-blog.csdnimg.cn/45ddb2799836469eb50c4020784a3a7e.png)  
ctrl+ s 保存，这样就可以了，效果会实时显示

以上就是 VSCode 的字体美化教程

### 结语

文章到这里就结束了，不知道各位小伙伴学会了吗，有任何疑问请到评论区留言，觉得文章写的还不错的小伙伴记得动动小手点个赞和收藏哟~ 赶紧把你们的学费交一下！