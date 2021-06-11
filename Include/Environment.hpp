//
// Created by crablet on 2021/9/30.
//

#ifndef WEBBROWSER_ENVIRONMENT_HPP
#define WEBBROWSER_ENVIRONMENT_HPP

enum class Browser
{
    Firefox,
    Chrome,
    Chromium,
    Safari,
    Konqueror,
    Opera,
    Edge,
    Default
};

enum class Platform
{
    Linux,
    Windows,
    MacOS,
    Unix,
    Android,
    Other
};

#if defined(TARGET_OS_MAC) || defined(__APPLE__) || defined(__MACH__)
#include "Browsers/MacOS/FirefoxMacOS.hpp"
#define Firefox FirefoxMacOS
#include "Browsers/MacOS/ChromeMacOS.hpp"
#define Chrome ChromeMacOS
#include "Browsers/MacOS/OperaMacOS.hpp"
#define Opera OperaMacOS
#include "Browsers/MacOS/EdgeMacOS.hpp"
#define Edge EdgeMacOS
#include "Browsers/MacOS/SafariMacOS.hpp"
#define Safari SafariMacOS
#include "Browsers/MacOS/DefaultMacOS.hpp"
#define Default DefaultMacOS
#elif defined(__linux__) || defined(linux) || defined(__linux)
#include "Browsers/Linux/FirefoxLinux.hpp"
#define Firefox FirefoxLinux
#include "Browsers/Linux/ChromeLinux.hpp"
#define Chrome ChromeLinux
#include "Browsers/Linux/OperaLinux.hpp"
#define Opera OperaLinux
#include "Browsers/Linux/EdgeLinux.hpp"
#define Edge EdgeLinux
#endif

#endif //WEBBROWSER_ENVIRONMENT_HPP
