//
// Created by crabletchen on 2021/10/3.
//
#if defined(TARGET_OS_MAC) || defined(__APPLE__) || defined(__MACH__)

#ifndef WEBBROWSER_DEFAULTMACOS_HPP
#define WEBBROWSER_DEFAULTMACOS_HPP

#include "Browsers/BaseBrowser.hpp"

class DefaultMacOS : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise) override;
};

bool DefaultMacOS::OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? "" : " -n ";
    const std::string command = std::string("open ") + tabOrWindow + url;

    return std::system(command.c_str()) == 0;
}

#endif //WEBBROWSER_DEFAULTMACOS_HPP

#endif
