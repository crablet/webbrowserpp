//
// Created by crabletchen on 2021/10/6.
//
#if defined(__linux__) || defined(linux) || defined(__linux)

#ifndef WEBBROWSER_DEFAULTLINUX_HPP
#define WEBBROWSER_DEFAULTLINUX_HPP

class DefaultLinux : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise) override;
};

bool DefaultLinux::OpenImpl(const std::string &url, Behaviour behaviour, bool autoRaise)
{
}

#endif //WEBBROWSER_DEFAULTLINUX_HPP

#endif
