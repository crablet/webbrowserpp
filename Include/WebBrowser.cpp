//
// Created by crabletchen on 2021/9/28.
//

#include "WebBrowser.h"

void WebBrowser::Open(const std::string &url, int behaviour, bool autoRaise)
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
    return Open(url, 1);
}

bool WebBrowser::OpenNewTab(const std::string &rl)
{
    return Open(url, 2);
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
