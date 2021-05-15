//
// Created by crabletchen on 2021/9/28.
//

#ifndef WEBBROWSER_WEBBROWSER_H
#define WEBBROWSER_WEBBROWSER_H

#include <string>

class WebBrowser
{
public:
    void Open(const std::string &url, int behaviour, bool autoRaise);
    void OpenNew(const std::string &url);
    void OpenNewTab(const std::string &rl);
};


#endif //WEBBROWSER_WEBBROWSER_H
