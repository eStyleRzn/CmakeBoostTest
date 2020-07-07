#include <deque>
#include <vector>
#include <algorithm>

#include "solution.hpp"

using namespace std;

using TypeStack = deque<char>;
using TypeBufferCh = string::const_pointer;
using TypeBuffer = vector<TypeBufferCh>;

void maxStr(TypeBuffer& strRet, TypeBuffer& strTemp)
{
    if (strRet.size() < strTemp.size())
    {
        strRet.swap(strTemp);
    }

    strTemp.clear();
}

string solution(const string& input)
{
    TypeBuffer ret;

    if (!input.size())
        return "";

    TypeStack resStack;
    TypeBuffer temp;
    bool breakIfError{false};
    for (auto it = input.begin(); ; ++it)
    {
        if (it == input.end())
        {
            it = input.begin();
            breakIfError = true;
        }

        // Detect loop condition
        TypeBufferCh chPtr = &(*it);
        if (temp.size()  && chPtr == *(temp.begin()))
        {
            return "Infinite";
        }

        const auto ch = *it;

        if ('{' == ch ||'[' == ch || '(' == ch)
        {
            resStack.push_back(ch);
        }
        else if ('}' == ch ||']' == ch || ')' == ch)
        {
            if (!resStack.size())
            {
                maxStr(ret, temp);

                if (breakIfError)
                {
                    break;
                }

                continue; // Incorrect start character, continue with next character
            }

            // Match charaters
            const auto& matchCh = resStack.back();

            if ((matchCh == '{' && '}' == ch) || (matchCh == '[' && ']' == ch) || (matchCh == '(' && ')' == ch))
            {
                resStack.pop_back();
            }
            else
            {
                maxStr(ret, temp);

                if (breakIfError)
                {
                    break;
                }

                continue; // Unmatched characters detected
            }
        }

        // Push character to the temp result
        temp.push_back(chPtr);
    }

    string r;
    for_each(ret.begin(), ret.end(), [&](TypeBufferCh p){
        r.push_back(*p);
    });

    return r;
}
