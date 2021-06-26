//
// Created by crablet on 2021/9/29.
//
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)

#ifndef WEBBROWSER_OPERAWINDOWS_HPP
#define WEBBROWSER_OPERAWINDOWS_HPP

#include "Browsers/BaseBrowser.hpp"

class OperaWindows : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise) override;
};

bool OperaWindows::OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? "--new-tab " : "--new-window ";
    const std::string command = std::string("start opera ") + tabOrWindow + url;

    return std::system(command.c_str()) == 0;
}

#endif //WEBBROWSER_OPERAWINDOWS_HPP

#endif
