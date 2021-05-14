//
// Created by crablet on 2021/9/23.
//

#ifndef WEBBROWSER_WEBBROWSERPP_H
#define WEBBROWSER_WEBBROWSERPP_H

#include <vector>
#include <memory>

#include "Browsers/BaseBrowser.h"

class WebBrowserPP
{
private:
    std::vector<std::unique_ptr<BaseBrowser>> tryOrder;
};

#endif //WEBBROWSER_WEBBROWSERPP_H
