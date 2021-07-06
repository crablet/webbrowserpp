//
// Created by crablet on 2021/11/9.
//
#if defined(TARGET_OS_MAC) || defined(__APPLE__) || defined(__MACH__)

#ifndef WEBBROWSER_CHROMIUMMACOS_H
#define WEBBROWSER_CHROMIUMMACOS_H

#include "Browsers/BaseBrowser.hpp"

class ChromiumMacOS : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise) override;
};

bool ChromiumMacOS::OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? "-a" : "-n -a";
    const std::string command = std::string("open ") + tabOrWindow + R"( chromium )" + url;

    return std::system(command.c_str()) == 0;
}

#endif //WEBBROWSER_CHROMIUMMACOS_H

#endif
