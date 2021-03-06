//
// Created by crablet on 2021/9/23.
//

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
