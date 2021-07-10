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
    IE,
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

#if defined(__linux__) || defined(linux) || defined(__linux)
#include "Browsers/Linux/FirefoxLinux.hpp"
    using Firefox = FirefoxLinux;
#include "Browsers/Linux/ChromeLinux.hpp"
    using Chrome = ChromeLinux;
#include "Browsers/Linux/ChromiumLinux.h"
    using Chromium = ChromiumLinux;
#include "Browsers/Linux/OperaLinux.hpp"
    using Opera = OperaLinux;
#include "Browsers/Linux/EdgeLinux.hpp"
    using Edge = EdgeLinux;
#include "Browsers/Linux/KonquerorLinux.hpp"
    using Konqueror = KonquerorLinux;
#include "Browsers/Linux/DefaultLinux.hpp"
    using Default = DefaultLinux;
#elif defined(TARGET_OS_MAC) || defined(__APPLE__) || defined(__MACH__)
#include "Browsers/MacOS/FirefoxMacOS.hpp"
    using Firefox = FirefoxMacOS;
#include "Browsers/MacOS/ChromeMacOS.hpp"
    using Chrome = ChromeMacOS;
#include "Browsers/MacOS/ChromiumMacOS.h"
    using Chromium = ChromiumMacOS;
#include "Browsers/MacOS/OperaMacOS.hpp"
    using Opera = OperaMacOS;
#include "Browsers/MacOS/EdgeMacOS.hpp"
    using Edge = EdgeMacOS;
#include "Browsers/MacOS/SafariMacOS.hpp"
    using Safari = SafariMacOS;
#include "Browsers/MacOS/DefaultMacOS.hpp"
    using Default = DefaultMacOS;
#elif defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#include "Browsers/Windows/FirefoxWindows.hpp"
    using Firefox = FirefoxWindows;
#include "Browsers/Windows/ChromeWindows.hpp"
    using Chrome = ChromeWindows;
#include "Browsers/Windows/ChromiumWindows.hpp"
    using Chromium = ChromiumWindows;
#include "Browsers/Windows/EdgeWindows.hpp"
    using Edge = EdgeWindows;
#include "Browsers/Windows/OperaWindows.hpp"
    using Opera = OperaWindows;
#include "Browsers/Windows/DefaultWindows.hpp"
    using Default = DefaultWindows;
#include "Browsers/Windows/IEWindows.hpp"
    using IE = IEWindows;
#endif

#endif //WEBBROWSER_ENVIRONMENT_HPP
