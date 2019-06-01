//
// Created by crablet on 2021/9/23.
//

#ifndef WEBBROWSER_BASEBROWSER_HPP
#define WEBBROWSER_BASEBROWSER_HPP

#include <string>

#include "Include/Control.hpp"

// 为了避免虚函数中使用默认参数会导致的一系列问题，本接口使用non-virtual interfaces技术，详见以下网址：
// https://stackoverflow.com/questions/27974653/default-parameter-in-virtual-functions-c
class BaseBrowser
{
public:
    bool Open(const std::string &url, Behaviour behaviour = Behaviour::NewTab, bool autoRaise = true);
    bool OpenNewWindow(const std::string &url);
    bool OpenNewTab(const std::string &url);

    virtual ~BaseBrowser() = default;

protected:
    virtual bool OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise) = 0;
};

bool BaseBrowser::Open(const std::string &url, Behaviour behaviour, bool autoRaise)
{
    return OpenImpl(url, behaviour, autoRaise);
}

bool BaseBrowser::OpenNewWindow(const std::string &url)
{
    return Open(url, Behaviour::NewWindow);
}

bool BaseBrowser::OpenNewTab(const std::string &url)
{
    return Open(url, Behaviour::NewTab);
}

#endif //WEBBROWSER_BASEBROWSER_HPP
