//
// Created by crablet on 2021/10/12.
//
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)

#ifndef WEBBROWSER_DEFAULTWINDOWS_HPP
#define WEBBROWSER_DEFAULTWINDOWS_HPP

#include "Browsers/BaseBrowser.hpp"

class DefaultWindows : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise) override;
};

bool DefaultWindows::OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise)
{
    return false;
}

#endif //WEBBROWSER_DEFAULTWINDOWS_HPP

#endif
