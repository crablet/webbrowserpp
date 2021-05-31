//
// Created by crablet on 2021/9/28.
//

#ifndef WEBBROWSER_BROWSERNOTFOUND_HPP
#define WEBBROWSER_BROWSERNOTFOUND_HPP

#include <stdexcept>
#include <string>

#include "Include/WebBrowser.hpp"

class BrowserNotFound : public std::logic_error
{
public:
    explicit BrowserNotFound(const std::string &s)
        : std::logic_error(s)
    {
    }
    explicit BrowserNotFound(const char *s)
        : std::logic_error(s)
    {
    }
    BrowserNotFound(Browser b, Platform p)
        : std::logic_error(GetErrorMessage(b, p))
    {
    }

    virtual ~BrowserNotFound() noexcept;

private:
    static std::string GetErrorMessage(Browser b, Platform p)
    {
        std::string browserName;
        switch (b)
        {
            case Browser::Firefox: browserName = "Firefox"; break;
            case Browser::Chromium: browserName = "Chromium"; break;
            case Browser::Chrome: browserName = "Chrome"; break;
            case Browser::Safari: browserName = "Safari"; break;
            case Browser::Konqueror: browserName = "Konqueror"; break;
            case Browser::Opera: browserName = "Opera"; break;
            case Browser::Edge: browserName = "Edge"; break;
            case Browser::Default: browserName = "Default"; break;
        }

        std::string platformName;
        switch (p)
        {
            case Platform::Linux: platformName = "Linux"; break;
            case Platform::Windows: platformName = "Windows"; break;
            case Platform::MacOS: platformName = "MacOS"; break;
            case Platform::Unix: platformName = "Unix"; break;
            case Platform::Android: platformName = "Android"; break;
            case Platform::Other: platformName = "Other"; break;
        }

        return browserName + " on " + platformName + " is not found!";
    }
};


#endif //WEBBROWSER_BROWSERNOTFOUND_HPP
