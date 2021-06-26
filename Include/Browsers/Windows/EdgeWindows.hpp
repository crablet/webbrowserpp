//
// Created by crablet on 2021/9/29.
//
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)

#ifndef WEBBROWSER_EDGEWINDOWS_HPP
#define WEBBROWSER_EDGEWINDOWS_HPP

#include "Browsers/BaseBrowser.hpp"

class EdgeWindows : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise) override;
};

bool EdgeWindows::OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? "--new-tab " : "--new-window ";
    const std::string command = std::string("start msedge ") + tabOrWindow + url;

    return std::system(command.c_str()) == 0;
}

#endif //WEBBROWSER_EDGEWINDOWS_HPP

#endif
