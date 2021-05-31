//
// Created by crablet on 2021/9/28.
//

#ifndef WEBBROWSER_WEBBROWSER_HPP
#define WEBBROWSER_WEBBROWSER_HPP

#include <string>
#include <vector>
#include <memory>

#include "Browsers/BaseBrowser.hpp"
#include "Environment.hpp"

class WebBrowser
{
public:
    bool Open(const std::string &url, int behaviour, bool autoRaise);
    bool OpenNew(const std::string &url);
    bool OpenNewTab(const std::string &rl);

private:
    void RegisterStandardBrowsers();
    void Register(Browser b);

private:
    std::vector<std::unique_ptr<BaseBrowser>> tryOrder;
};

bool WebBrowser::Open(const std::string &url, int behaviour, bool autoRaise)
{
    if (tryOrder.empty())
    {
        RegisterStandardBrowsers();
    }

    for (const auto &browser : tryOrder)
    {
        if (browser->Open(url, behaviour, autoRaise))
        {
            return true;
        }
    }

    return false;
}

bool WebBrowser::OpenNew(const std::string &url)
{
    return Open(url, 1, true);
}

bool WebBrowser::OpenNewTab(const std::string &url)
{
    return Open(url, 2, true);
}

void WebBrowser::RegisterStandardBrowsers()
{
    tryOrder.clear();

#if defined(TARGET_OS_MAC) || defined(__APPLE__) || defined(__MACH__)
    Register(Browser::Default);
    Register(Browser::Firefox);
    Register(Browser::Chrome);
    Register(Browser::Safari);
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    Register(Browser::Default)
    Register(Browser::Firefox);
    Register(Browser::Chrome);
#else
    Register(Browser::Default);
    Register(Browser::Firefox);
    Register(Browser::Chrome);
#endif
}

void WebBrowser::Register(Browser b)
{

}

#endif //WEBBROWSER_WEBBROWSER_HPP
