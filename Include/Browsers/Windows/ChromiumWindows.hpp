//
// Created by crablet on 2021/11/17.
//
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)

#ifndef WEBBROWSER_CHROMIUMWINDOWS_HPP
#define WEBBROWSER_CHROMIUMWINDOWS_HPP

#include "Browsers/BaseBrowser.hpp"

class ChromiumWindows : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise) override;
};

bool ChromiumWindows::OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise)
{
    const std::string tabOrWindow = behaviour == Behaviour::NewTab ? "--new-tab " : "--new-window ";
    const std::string command = std::string("start chromium ") + tabOrWindow + url;

    return std::system(command.c_str()) == 0;
}

#endif //WEBBROWSER_CHROMIUMWINDOWS_HPP

#endif
