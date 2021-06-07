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
#endif

#endif //WEBBROWSER_ENVIRONMENT_HPP
