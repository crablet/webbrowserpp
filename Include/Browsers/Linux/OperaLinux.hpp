//
// Created by crablet on 2021/9/29.
//
#if defined(__linux__) || defined(linux) || defined(__linux)

#ifndef WEBBROWSER_OPERALINUX_HPP
#define WEBBROWSER_OPERALINUX_HPP

#include "Browsers/BaseBrowser.hpp"

class OperaLinux : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise) override;
};

bool OperaLinux::OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? " " : "--new-window ";
    const std::string command = std::string("opera ") + tabOrWindow + url + '&';

    return std::system(command.c_str()) == 0;
}


#endif //WEBBROWSER_OPERALINUX_HPP

#endif
