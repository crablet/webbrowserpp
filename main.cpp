//
// Created by crablet on 2021/9/23.
//

#include "Include/Browsers/MacOS/FirefoxMacOS.hpp"
#include "Include/Browsers/MacOS/SafariMacOS.hpp"
#include "Include/Browsers/MacOS/ChromeMacOS.hpp"

int main()
{
    FirefoxMacOS().Open("https://www.tencent.com");
    SafariMacOS().Open("https://www.tencent.com");
    ChromeMacOS().Open("https://www.tencent.com");

    return 0;
}
