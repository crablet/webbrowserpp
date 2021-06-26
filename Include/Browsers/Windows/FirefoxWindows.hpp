//
// Created by crablet on 2021/9/29.
//
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)

#ifndef WEBBROWSER_FIREFOXWINDOWS_HPP
#define WEBBROWSER_FIREFOXWINDOWS_HPP

#include "Browsers/BaseBrowser.hpp"

class FirefoxWindows : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise) override;
};

bool FirefoxWindows::OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? "--new-tab " : "--new-window ";
    const std::string command = std::string("start firefox ") + tabOrWindow + url;

    return std::system(command.c_str()) == 0;
}


#endif //WEBBROWSER_FIREFOXWINDOWS_HPP

#endif
