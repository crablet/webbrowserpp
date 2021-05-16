//
// Created by crabletchen on 2021/9/28.
//

#ifndef WEBBROWSER_WEBBROWSER_H
#define WEBBROWSER_WEBBROWSER_H

#include <string>
#include <vector>
#include <memory>

#include "Browsers/BaseBrowser.h"

class WebBrowser
{
public:
    bool Open(const std::string &url, int behaviour, bool autoRaise);
    bool OpenNew(const std::string &url);
    bool OpenNewTab(const std::string &rl);

private:
    void RegisterStandardBrowsers();

private:
    std::vector<std::unique_ptr<BaseBrowser>> tryOrder;
};


#endif //WEBBROWSER_WEBBROWSER_H
