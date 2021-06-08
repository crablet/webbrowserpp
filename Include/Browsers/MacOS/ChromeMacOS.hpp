//
// Created by crablet on 2021/9/29.
//
#if defined(TARGET_OS_MAC) || defined(__APPLE__) || defined(__MACH__)

#ifndef WEBBROWSER_CHROMEMACOS_HPP
#define WEBBROWSER_CHROMEMACOS_HPP

#include "Browsers/BaseBrowser.hpp"

class ChromeMacOS : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise) override;
};

bool ChromeMacOS::OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? "-a" : "-n -a";
    const std::string command = std::string("open ") + tabOrWindow + R"( "Google Chrome" )" + url;

    return std::system(command.c_str()) == 0;
}


#endif //WEBBROWSER_CHROMEMACOS_HPP

#endif
