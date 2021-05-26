//
// Created by crablet on 2021/9/28.
//
#if defined(TARGET_OS_MAC) || defined(__APPLE__) || defined(__MACH__)

#include <cstdlib>

#include "FirefoxMacOS.h"

bool FirefoxMacOS::Open(const std::string &url, int behaviour, bool autoRaise)
{
    std::string command = R"(open -a Firefox ")";
    command += url + '"';

    std::system(command);

    return true;
}

bool FirefoxMacOS::OpenNew(const std::string &url)
{
    return false;
}

bool FirefoxMacOS::OpenNewTab(const std::string &rl)
{
    return false;
}

#endif
