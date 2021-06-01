//
// Created by crablet on 2021/9/28.
//
#if defined(TARGET_OS_MAC) || defined(__APPLE__) || defined(__MACH__)

#ifndef WEBBROWSER_FIREFOXMACOS_H
#define WEBBROWSER_FIREFOXMACOS_H

#include "Include/Browsers/BaseBrowser.hpp"

class FirefoxMacOS : public BaseBrowser
{
public:
    bool Open(const std::string &url, Behaviour behaviour = Behaviour::NewTab, bool autoRaise = true) override;
    bool OpenNewWindow(const std::string &url) override;
    bool OpenNewTab(const std::string &rl) override;
};

bool FirefoxMacOS::Open(const std::string &url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? "-a" : "-n -a";
    std::string command = std::string("open ") + tabOrWindow + " Firefox " + url;

    std::system(command.c_str());

    return true;
}

bool FirefoxMacOS::OpenNewWindow(const std::string &url)
{
    return Open(url, Behaviour::NewWindow);
}

bool FirefoxMacOS::OpenNewTab(const std::string &url)
{
    return Open(url, Behaviour::NewTab);
}

#endif //WEBBROWSER_FIREFOXMACOS_H

#endif
