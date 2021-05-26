//
// Created by crablet on 2021/9/28.
//
#if defined(TARGET_OS_MAC) || defined(__APPLE__) || defined(__MACH__)

#ifndef WEBBROWSER_FIREFOXMACOS_H
#define WEBBROWSER_FIREFOXMACOS_H

#include "Include/Browsers/BaseBrowser.h"

class FirefoxMacOS : public BaseBrowser
{
public:
    bool Open(const std::string &url, int behaviour, bool autoRaise) override;
    bool OpenNew(const std::string &url) override;
    bool OpenNewTab(const std::string &rl) override;
};

#endif //WEBBROWSER_FIREFOXMACOS_H

#endif
