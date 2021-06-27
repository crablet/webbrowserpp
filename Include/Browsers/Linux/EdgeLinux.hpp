//
// Created by crablet on 2021/9/29.
//
#if defined(__linux__) || defined(linux) || defined(__linux)

#ifndef WEBBROWSER_EDGELINUX_HPP
#define WEBBROWSER_EDGELINUX_HPP

#include "Browsers/BaseBrowser.hpp"

class EdgeLinux : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise) override;
};

bool EdgeLinux::OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? " " : "--new-window ";
    const std::string command = std::string("microsoft-edge ") + tabOrWindow + url + '&';

    return std::system(command.c_str()) == 0;
}


#endif //WEBBROWSER_EDGELINUX_HPP

#endif
