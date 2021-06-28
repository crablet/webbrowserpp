//
// Created by crabletchen on 2021/10/6.
//
#if defined(__linux__) || defined(linux) || defined(__linux)

#ifndef WEBBROWSER_KONQUERORLINUX_HPP
#define WEBBROWSER_KONQUERORLINUX_HPP

#include "Browsers/BaseBrowser.hpp"

class KonquerorLinux : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise) override;
};

bool KonquerorLinux::OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? "newTab " : "openURL ";
    const std::string command = std::string("kfmclient ") + tabOrWindow + url;

    return std::system(command.c_str()) == 0;
}

#endif //WEBBROWSER_KONQUERORLINUX_HPP

#endif
