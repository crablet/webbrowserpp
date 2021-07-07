# WebBrowser++

[简体中文](./README.md) | English

This is a cross-platform header-only web browser control library base on C++17.   
You only need to copy the `Include` directory to your project for using it. Just write `include_directories(Include)` if you build with CMake. You can also imitate the CMakeLists.txt of this project.  
The purpose of establishing this library is to provide a better C++ cross-platform browser control library. I try to make the API easy to understand, abandon the obscure and difficult syntax, let it with zero getting started difficulty.  
The library is built with only C++ standard library and OS standard interfaces, without any third-party dependencies.  
The API refers to part of the design of the [webbrowser](https://docs.python.org/3/library/mimetypes.html) library in Python.

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
