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
    using Firefox = FirefoxMacOS;
#include "Browsers/MacOS/ChromeMacOS.hpp"
    using Chrome = ChromeMacOS;
#include "Browsers/MacOS/OperaMacOS.hpp"
    using Opera = OperaMacOS;
#include "Browsers/MacOS/EdgeMacOS.hpp"
    using Edge = EdgeMacOS;
#include "Browsers/MacOS/SafariMacOS.hpp"
    using Safari = SafariMacOS;
#include "Browsers/MacOS/DefaultMacOS.hpp"
    using Default = DefaultMacOS;
#elif defined(__linux__) || defined(linux) || defined(__linux)
#include "Browsers/Linux/FirefoxLinux.hpp"
    using Firefox = FirefoxLinux;
#include "Browsers/Linux/ChromeLinux.hpp"
    using Chrome = ChromeLinux;
#include "Browsers/Linux/OperaLinux.hpp"
    using Opera = OperaLinux;
#include "Browsers/Linux/EdgeLinux.hpp"
    using Edge = EdgeLinux;
#endif

#endif //WEBBROWSER_ENVIRONMENT_HPP
