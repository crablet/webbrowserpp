//
// Created by crablet on 2021/9/29.
//
#if defined(__linux__) || defined(linux) || defined(__linux)

#ifndef WEBBROWSER_FIREFOXLINUX_HPP
#define WEBBROWSER_FIREFOXLINUX_HPP

#include "Browsers/BaseBrowser.hpp"

class FirefoxLinux : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise) override;
};

bool FirefoxLinux::OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? " -new-tab " : " -new-window ";
    const std::string command = std::string("firefox ") + tabOrWindow + url;

    return std::system(command.c_str()) == 0;
}


#endif //WEBBROWSER_FIREFOXLINUX_HPP

#endif
