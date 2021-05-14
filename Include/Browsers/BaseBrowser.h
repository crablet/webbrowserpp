//
// Created by crablet on 2021/9/23.
//

#ifndef WEBBROWSER_BASEBROWSER_H
#define WEBBROWSER_BASEBROWSER_H

#include <string>

class BaseBrowser
{
public:c
    virtual void Open(const std::string &url, int behaviour, bool autoRaise) = 0;
    virtual void OpenNew(const std::string &url) = 0;
    virtual void OpenNewTab(const std::string &rl) = 0;
};


#endif //WEBBROWSER_BASEBROWSER_H
