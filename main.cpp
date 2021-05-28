//
// Created by crablet on 2021/9/23.
//

#include <iostream>

#include "Include/Browsers/MacOS/FirefoxMacOS.hpp"

int main()
{
    FirefoxMacOS().Open("https://www.google.com", 0, true);

    return 0;
}
