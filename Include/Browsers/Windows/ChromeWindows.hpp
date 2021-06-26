//
// Created by crablet on 2021/9/29.
//
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)

#ifndef WEBBROWSER_CHROMEWINDOWS_HPP
#define WEBBROWSER_CHROMEWINDOWS_HPP

#include "Browsers/BaseBrowser.hpp"

class ChromeWindows : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise) override;
};

bool ChromeWindows::OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? "--new-tab " : "--new-window ";
    const std::string command = std::string("start chrome ") + tabOrWindow + url;

    return std::system(command.c_str()) == 0;
}

#endif //WEBBROWSER_CHROMEWINDOWS_HPP

#endif
