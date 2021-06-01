//
// Created by crablet on 2021/9/23.
//

#ifndef WEBBROWSER_BASEBROWSER_HPP
#define WEBBROWSER_BASEBROWSER_HPP

#include <string>

#include "Include/Control.hpp"

class BaseBrowser
{
public:
    virtual bool Open(const std::string &url, Behaviour behaviour, bool autoRaise) = 0;
    virtual bool OpenNew(const std::string &url) = 0;
    virtual bool OpenNewTab(const std::string &rl) = 0;

    virtual ~BaseBrowser() = default;
};


#endif //WEBBROWSER_BASEBROWSER_HPP
