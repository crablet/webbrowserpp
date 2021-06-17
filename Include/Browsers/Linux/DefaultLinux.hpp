//
// Created by crabletchen on 2021/10/6.
//
#if defined(__linux__) || defined(linux) || defined(__linux)

#ifndef WEBBROWSER_DEFAULTLINUX_HPP
#define WEBBROWSER_DEFAULTLINUX_HPP

#include <cstdio>

#include "unistd.h"

#include "Browsers/BaseBrowser.hpp"
#include "FirefoxLinux.hpp"
#include "ChromeLinux.hpp"
#include "EdgeLinux.hpp"
#include "KonquerorLinux.hpp"
#include "OperaLinux.hpp"

class DefaultLinux : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise) override;
};

bool DefaultLinux::OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise)
{
    auto *ptr = popen("xdg-settings get default-web-browser", "r");
    if (ptr == nullptr)
    {
        return false;
    }
    else
    {
        char buffer[32] = { 0 };
        std::fgets(buffer, sizeof(buffer), ptr);
        pclose(ptr);

        std::string systemPreferredBrowser = buffer;
        if (systemPreferredBrowser.find("firefox") != std::string::npos)
        {
            return FirefoxLinux().Open(url, behaviour, autoRaise);
        }
        else if (systemPreferredBrowser.find("chrome") != std::string::npos)
        {
            return ChromeLinux().Open(url, behaviour, autoRaise);
        }
        else if (systemPreferredBrowser.find("edge") != std::string::npos)
        {
            return EdgeLinux().Open(url, behaviour, autoRaise);
        }
        else if (systemPreferredBrowser.find("konqueror") != std::string::npos)
        {
            return KonquerorLinux().Open(url, behaviour, autoRaise);
        }
        else if (systemPreferredBrowser.find("opera") != std::string::npos)
        {
            return OperaLinux().Open(url, behaviour, autoRaise);
        }
        else
        {
            if (access("xdg-open", F_OK) == 0)
            {
                return std::system(std::string("xdg-open ") + url);
            }
            else if (access("gvfs-open", F_OK) == 0)
            {
                return std::system(std::string("gvfs-open ") + url);
            }
            else if (access("gnome-open", F_OK) == 0)
            {
                return std::system(std::string("gnome-open ") + url);
            }
            else if (access("x-www-browser", F_OK) == 0)
            {
                return std::system(std::string("x-www-browser ") + url);
            }
            else
            {
                return false;
            }
        }
    }
}

#endif //WEBBROWSER_DEFAULTLINUX_HPP

#endif
