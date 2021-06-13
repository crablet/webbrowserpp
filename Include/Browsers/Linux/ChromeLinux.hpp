//
// Created by crablet on 2021/9/29.
//
#if defined(__linux__) || defined(linux) || defined(__linux)

#ifndef WEBBROWSER_CHROMELINUX_HPP
#define WEBBROWSER_CHROMELINUX_HPP

#include "Browsers/BaseBrowser.hpp"

class ChromeLinux : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise) override;
};

bool ChromeLinux::OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? " " : "--new-window ";
    const std::string command = std::string("google-chrome ") + tabOrWindow + url + '&';

    return std::system(command.c_str()) == 0;
}


#endif //WEBBROWSER_CHROMELINUX_HPP

#endif
