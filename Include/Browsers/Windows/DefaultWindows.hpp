//
// Created by crablet on 2021/10/12.
//
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)

#ifndef WEBBROWSER_DEFAULTWINDOWS_HPP
#define WEBBROWSER_DEFAULTWINDOWS_HPP

#include <string>

#include "Windows.h"

#include "Browsers/BaseBrowser.hpp"
#include "FirefoxWindows.hpp"
#include "ChromeWindows.hpp"
#include "EdgeWindows.hpp"
#include "OperaWindows.hpp"

class DefaultWindows : public BaseBrowser
{
protected:
    bool OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise) override;
};

bool DefaultWindows::OpenImpl(const std::string& url, Behaviour behaviour, bool autoRaise)
{
    int dataSize;
    if (RegGetValue(HKEY_CURRENT_USER, R"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\FileExts\.html\UserChoice)", R"(ProgID)", RRF_RT_REG_SZ, nullptr, nullptr, &dataSize) 
        != ERROR_SUCCESS)
    {
        return false;
    }

    std::wstring data;
    data.resize(dataSize / sizeof(wchar_t);
    if (RegGetValue(HKEY_CURRENT_USER, R"(SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\FileExts\.html\UserChoice)", R"(ProgID)", RRF_RT_REG_SZ, nullptr, &data[0], &dataSize)
        != ERROR_SUCCESS)
    {
        return false;
    }

    DWORD stringLengthInWchars = dataSize / sizeof(wchar_t);
    data.resize(stringLengthInWchars - 1);

    if (data.find("Firefox") != std::wstring::npos)
    {
        return FirefoxWindows().Open(url, behaviour, autoRaise);
    }
    else if (data.find("Chrome") != std::wstring::npos)
    {
        return ChromeWindows().Open(url, behaviour, autoRaise);
    }
    else if (data.find("Edge") != std::wstring::npos)
    {
        return EdgeWindows().Open(url, behaviour, autoRaise);
    }
    else if (data.find("Opera") != std::wstring::npos)
    {
        return OperaWindows().Open(url, behaviour, autoRaise);
    }
    else
    {
        return false;
    }
}

#endif //WEBBROWSER_DEFAULTWINDOWS_HPP

#endif
