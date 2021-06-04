//
// Created by crabletchen on 2021/9/30.
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
#include "Include/Browsers/MacOS/FirefoxMacOS.hpp"
    using Firefox = FirefoxMacOS;
#include "Include/Browsers/MacOS/ChromeMacOS.hpp"
    using Chrome = ChromeMacOS;
#include "Include/Browsers/MacOS/OperaMacOS.hpp"
    using Opera = OperaMacOS;
#include "Include/Browsers/MacOS/EdgeMacOS.hpp"
    using Edge = EdgeMacOS;
#include "Include/Browsers/MacOS/SafariMacOS.hpp"
    using Safari = SafariMacOS;
#elif

#endif //WEBBROWSER_ENVIRONMENT_HPP
