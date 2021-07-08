# WebBrowser++

[简体中文](./README.md) | English

This is a cross-platform header-only web browser control library base on C++17.   
You only need to copy the `Include` directory to your project for using it. Just write `include_directories(Include)` if you build with CMake. You can also imitate the CMakeLists.txt of this project.  
The purpose of establishing this library is to provide a better C++ cross-platform browser control library. I try to make the API easy to understand, abandon the obscure and difficult syntax, let it with zero getting started difficulty.  
The library is built with only C++ standard library and OS standard interfaces, without any third-party dependencies.  
The API refers to part of the design of the [webbrowser](https://docs.python.org/3/library/mimetypes.html) library in Python.

## Example
```c++
#include "WebBrowser.hpp"

int main()
{
    // open website with the default browser
    WebBrowser().Open("https://www.tencent.com");

    // open website with the default browser in new tab (method 1)
    WebBrowser().Open("https://www.tencent.com", Behaviour::NewTab);

    // open website with the default browser in new tab (method 2)
    WebBrowser().OpenNewTab("https://www.tencent.com");

    // open website with the default browser in new window (method 1)
    WebBrowser().Open("https://www.tencent.com", Behaviour::NewWindow);

    // open website with the default browser in new window (method 2)
    WebBrowser().OpenNewWindow("https://www.tencent.com");

    // open website with Firefox (see the type defined in Browser for using another browser.)
    // function Open, OpenNewTab and OpenNewWindow are the same as the above
    WebBrowser::Get(Browser::Firefox)->Open("https://www.tencent.com");

    return 0;
}
```

## Support

|       |Firefox|Chrome|Edge|Opera|Konqueror|Safari| IE |
|:-----:|:-----:|:----:|:--:|:---:|:-------:|:----:|:--:|
|Linux  |√      |√     |√   |√    |√        |○     |○   |
|Windows|√      |√     |√   |√    |○        |○     |√   |
|MacOS  |√      |√     |√   |√    |○        |√     |○   |

Note: √ for supported, × for not supported, ○ for browser not exists on that platform
