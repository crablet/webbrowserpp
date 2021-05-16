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

}
