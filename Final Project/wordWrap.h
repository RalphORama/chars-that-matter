// Console Word Wrap - Alex Rodgers (05/02/2013)
// http://alexrodgers.co.uk/2012/08/09/c-word-wrap-for-console-output-tutorial/
/////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <string> 
#include <sstream>
#include <windows.h>

namespace WordWrap
{
    int GetBufferWidth();
    void OutputText(std::string);
}

