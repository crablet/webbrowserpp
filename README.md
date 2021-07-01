# WebBrowser++  

这是一个基于C++17的唯头文件跨平台浏览器控制库。  
您只需要将本目录下的Include文件夹拷贝至您的项目中即可使用。如果使用CMake编译，则可直接`include_directories(Include)`，也可以模仿本项目的CMakeLists.txt进行编写。  
建立该库的目的是为了提供一个更好用的C++跨平台浏览器控制库，并且尽量使得API通俗易懂，抛弃晦涩难懂的语法，零上手难度。  
该库仅使用C++标准库及操作系统标准接口，无任何第三方依赖。  
本项目API参考了Python中webbrowser库的部分设计。

## 例子
```c++
#include "WebBrowser.hpp"

int main()
{
    // 使用默认浏览器打开网页
    WebBrowser().Open("https://www.tencent.com");

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
