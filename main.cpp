//
// Created by crablet on 2021/9/23.
//

#include "Include/Browsers/MacOS/FirefoxMacOS.hpp"
#include "Include/Browsers/MacOS/OperaMacOS.hpp"

int main()
{
    FirefoxMacOS().Open("https://www.tencent.com");
    OperaMacOS().Open("https://www.tencent.com");

    return 0;
}
