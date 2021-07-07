# WebBrowser++  

简体中文 | [English](./README-EN.md)

这是一个基于C++17的唯头文件跨平台浏览器控制库。  
您只需要将本目录下的Include文件夹拷贝至您的项目中即可使用。如果使用CMake编译，则可直接`include_directories(Include)`，也可以模仿本项目的CMakeLists.txt进行编写。  
建立该库的目的是为了提供一个更好用的C++跨平台浏览器控制库，并且尽量使得API通俗易懂，抛弃晦涩难懂的语法，零上手难度。  
该库仅使用C++标准库及操作系统标准接口，无任何第三方依赖。  
本项目API参考了Python中 [webbrowser](https://docs.python.org/zh-cn/3/library/mimetypes.html) 库的部分设计。

## 例子
```c++
#include "WebBrowser.hpp"

int main()
{
    // 使用默认浏览器打开网页
    WebBrowser().Open("https://www.tencent.com");

    // 使用默认浏览器在新标签页打开网页（方法一）
    WebBrowser().Open("https://www.tencent.com", Behaviour::NewTab);

    // 使用默认浏览器在新标签页打开网页（方法二）
    WebBrowser().OpenNewTab("https://www.tencent.com");

    // 使用默认浏览器在新窗口打开网页（方法一）
    WebBrowser().Open("https://www.tencent.com", Behaviour::NewWindow);

    // 使用默认浏览器在新窗口打开网页（方法二）
    WebBrowser().OpenNewWindow("https://www.tencent.com");

    // 使用火狐浏览器打开网页（使用其他浏览器同理，见Browser中定义的类型）
    // Open函数，OpenNewTab函数以及OpenNewWindow用法同上，不再赘述
    WebBrowser::Get(Browser::Firefox)->Open("https://www.tencent.com");

    return 0;
}
```

## 支持情况

|       |Firefox|Chrome|Edge|Opera|Konqueror|Safari| IE |
|:-----:|:-----:|:----:|:--:|:---:|:-------:|:----:|:--:|
|Linux  |√      |√     |√   |√    |√        |○     |○   |
|Windows|√      |√     |√   |√    |○        |○     |√   |
|MacOS  |√      |√     |√   |√    |○        |√     |○   |

注：已支持为√，未支持为×，该平台不存在该浏览器为○。
