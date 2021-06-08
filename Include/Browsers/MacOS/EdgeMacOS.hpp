//
// Created by crablet on 2021/9/29.
//
#if defined(TARGET_OS_MAC) || defined(__APPLE__) || defined(__MACH__)

#ifndef WEBBROWSER_EDGEMACOS_HPP
#define WEBBROWSER_EDGEMACOS_HPP

#include "Browsers/BaseBrowser.hpp"

class EdgeMacOS : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise) override;
};

bool EdgeMacOS::OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? "-a" : "-n -a";
    const std::string command = std::string("open ") + tabOrWindow + R"( /Applications/Microsoft\ Edge.app/Contents/MacOS/Microsoft\ Edge )" + url;

    return std::system(command.c_str()) == 0;
}


#endif //WEBBROWSER_EDGEMACOS_HPP

#endif
