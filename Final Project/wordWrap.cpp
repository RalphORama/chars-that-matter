// Console Word Wrap - Alex Rodgers (05/02/2013)
// http://alexrodgers.co.uk/2012/08/09/c-word-wrap-for-console-output-tutorial/
/////////////////////////////////////////////////

#include "wordWrap.h"

namespace WordWrap
{
    int GetBufferWidth()
    {
        CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
        int bufferWidth, result;

        result = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);

        if (result)
        {
            bufferWidth = bufferInfo.dwSize.X;
        }

        return bufferWidth;
    }

    void OutputText(std::string s)
    {
        int bufferWidth = GetBufferWidth();

        for (unsigned int i = 1; i <= s.length(); i++)
        {
            char c = s[i - 1];

            int spaceCount = 0;

            // Add whitespace if newline detected.
            if (c == '\n')
            {
                int charNumOnLine = ((i) % bufferWidth);
                spaceCount = bufferWidth - charNumOnLine;
                s.insert((i - 1), (spaceCount), ' ');   // insert space before newline break
                i += (spaceCount);                      // jump forward in string to character at beginning of next line
                continue;
            }

            if ((i % bufferWidth) == 0)
            {
                if (c != ' ')
                {
                    for (int j = (i - 1); j > -1; j--)
                    {
                        if (s[j] == ' ')
                        {
                            s.insert(j, spaceCount, ' ');
                            break;
                        }
                        else spaceCount++;
                    }
                }
            }
        }

        // Output string to console
        std::cout << s << std::endl;
    }
}
