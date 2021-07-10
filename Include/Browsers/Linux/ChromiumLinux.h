//
// Created by crablet on 2021/11/17.
//
#if defined(__linux__) || defined(linux) || defined(__linux)

#ifndef WEBBROWSER_CHROMIUMLINUX_H
#define WEBBROWSER_CHROMIUMLINUX_H

#include "Browsers/BaseBrowser.hpp"

class ChromiumLinux : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise) override;
};

bool ChromiumLinux::OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? " " : "--new-window ";
    const std::string command = std::string("chromium-browser ") + tabOrWindow + url + '&';

    return std::system(command.c_str()) == 0;
}

#endif //WEBBROWSER_CHROMIUMLINUX_H

#endif
