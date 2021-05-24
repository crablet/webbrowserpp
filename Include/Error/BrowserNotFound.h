//
// Created by crablet on 2021/9/28.
//

#ifndef WEBBROWSER_BROWSERNOTFOUND_H
#define WEBBROWSER_BROWSERNOTFOUND_H

#include <stdexcept>
#include <string>

class BrowserNotFound : public std::logic_error
{
public:
    explicit BrowserNotFound(const std::string &s) : std::logic_error(s) {}
    explicit BrowserNotFound(const char *s) : std::logic_error(s) {}

    virtual ~BrowserNotFound() noexcept;

private:
    std::string errorMessage;
};


#endif //WEBBROWSER_BROWSERNOTFOUND_H
