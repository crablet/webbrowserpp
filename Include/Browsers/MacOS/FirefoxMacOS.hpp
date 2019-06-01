//
// Created by crablet on 2021/9/28.
//
#if defined(TARGET_OS_MAC) || defined(__APPLE__) || defined(__MACH__)

#ifndef WEBBROWSER_FIREFOXMACOS_H
#define WEBBROWSER_FIREFOXMACOS_H

#include "Include/Browsers/BaseBrowser.hpp"

class FirefoxMacOS : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise) override;
};

bool FirefoxMacOS::OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? "-a" : "-n -a";
    std::string command = std::string("open ") + tabOrWindow + " Firefox " + url;

    std::system(command.c_str());

    return true;
}

#endif //WEBBROWSER_FIREFOXMACOS_H

#endif
