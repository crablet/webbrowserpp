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
    bool Open(const std::string &url, Behaviour behaviour = Behaviour::NewTab, bool autoRaise = true);
    bool OpenNewWindow(const std::string &url);
    bool OpenNewTab(const std::string &rl);

    static std::unique_ptr<BaseBrowser> Get(Browser b);

private:
    void RegisterStandardBrowsers();
    void Register(Browser b);

private:
    std::vector<std::unique_ptr<BaseBrowser>> tryOrder;
};

bool WebBrowser::Open(const std::string &url, Behaviour behaviour, bool autoRaise)
{
    if (tryOrder.empty())
    {
        RegisterStandardBrowsers();
    }

    for (const auto &browser : tryOrder)
    {
        if (browser && browser->Open(url, behaviour, autoRaise))
        {
            return true;
        }
    }

    return false;
}

bool WebBrowser::OpenNewWindow(const std::string &url)
{
    return Open(url, Behaviour::NewWindow, true);
}

bool WebBrowser::OpenNewTab(const std::string &url)
{
    return Open(url, Behaviour::NewTab, true);
}

void WebBrowser::RegisterStandardBrowsers()
{
    tryOrder.clear();

#if defined(TARGET_OS_MAC) || defined(__APPLE__) || defined(__MACH__)
    Register(Browser::Default);
    Register(Browser::Firefox);
    Register(Browser::Chrome);
    Register(Browser::Safari);
    Register(Browser::Opera);
    Register(Browser::Edge);
#elif defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    Register(Browser::Default);
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
    tryOrder.push_back(Get(b));
}

std::unique_ptr<BaseBrowser> WebBrowser::Get(Browser b)
{
    switch (b)
    {
#if defined(TARGET_OS_MAC) || defined(__APPLE__) || defined(__MACH__)
        case Browser::Firefox: return std::make_unique<Firefox>();
        case Browser::Chrome: return std::make_unique<Chrome>();
        case Browser::Safari: return  std::make_unique<Safari>();
        case Browser::Chromium: return nullptr;
        case Browser::Konqueror: return nullptr;
        case Browser::Opera: return std::make_unique<Opera>();
        case Browser::Edge: return std::make_unique<Edge>();
        case Browser::Default: return std::make_unique<Default>();
#elif defined(__linux__) || defined(linux) || defined(__linux)
        case Browser::Firefox: return std::make_unique<Firefox>();
        case Browser::Chrome: return std::make_unique<Chrome>();
        case Browser::Safari: return nullptr;
        case Browser::Chromium: return nullptr;
        case Browser::Konqueror: return std::make_unique<Konqueror>();
        case Browser::Opera: return std::make_unique<Opera>();
        case Browser::Edge: return std::make_unique<Edge>();
        case Browser::Default: return std::make_unique<Default>();
#elif defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
        case Browser::Firefox: return std::make_unique<Firefox>();
        case Browser::Chrome: return std::make_unique<Chrome>();
        case Browser::Safari: return nullptr;
        case Browser::Chromium: return nullptr;
        case Browser::Konqueror: return nullptr;
        case Browser::Opera: return std::make_unique<Opera>();
        case Browser::Edge: return std::make_unique<Edge>();
        case Browser::Default: return std::make_unique<Default>();
#endif
    }
}

#endif //WEBBROWSER_WEBBROWSER_HPP
