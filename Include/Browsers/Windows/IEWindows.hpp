//
// Created by crablet on 2021/11/7.
//
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)

#ifndef WEBBROWSER_IEWINDOWS_HPP
#define WEBBROWSER_IEWINDOWS_HPP

#include "Browsers/BaseBrowser.hpp"

class IEWindows : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise) override;
};

bool IEWindows::OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise)
{
    const std::string command = std::string("start iexplore ") + url;

    return std::system(command.c_str()) == 0;
}

#endif //WEBBROWSER_IEWINDOWS_HPP

#endif
