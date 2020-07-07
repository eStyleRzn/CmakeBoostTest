#include <deque>
#include <vector>
#include <algorithm>

#include "solution.hpp"

using namespace std;

using TypeStack = deque<char>;
using TypeBufferCh = string::const_pointer;
using TypeBuffer = vector<TypeBufferCh>;

string solution(const string& input)
{
    if (!input.size())
        return "";

    TypeStack  bracesStack;
    TypeBuffer seqRet;
    TypeBuffer seqTemp;

    // Reset current sequence
    auto reset = [&]() { seqTemp.clear(); bracesStack.clear(); };

    // Curent temp sequence is a valid sequence
    auto tempIsValid = [&](){ return  0 == bracesStack.size(); };

    bool breakIfError{false};
    for (auto it = input.begin(); ; ++it)
    {
        // Current sequence is valid
        if (tempIsValid() && (seqRet.size() < seqTemp.size()))
        {
            // Evaluate longer sequence
            seqRet = seqTemp;
        }

        // Loop
        if (it == input.end())
        {
            it = input.begin();
            breakIfError = true;
        }

        // Detect loop condition
        TypeBufferCh chPtr = &(*it);
        if (seqTemp.size() && chPtr == *(seqTemp.begin()))
        {
            if (tempIsValid())
            {
                return "Infinite";
            }

            break; // Break loop
        }

        const auto& ch = *it;

        if ('{' == ch ||'[' == ch || '(' == ch)
        {
            bracesStack.push_back(ch);
        }
        else if ('}' == ch ||']' == ch || ')' == ch)
        {
            if (!bracesStack.size())
            {
                if (breakIfError)
                {
                    break;
                }

                reset();
                continue; // Incorrect start character, continue with next character
            }

            // Match charaters
            const auto& matchCh = bracesStack.back();

            if ((matchCh == '{' && '}' == ch) || (matchCh == '[' && ']' == ch) || (matchCh == '(' && ')' == ch))
            {
                bracesStack.pop_back();
            }
            else
            {
                if (breakIfError)
                {
                    break;
                }

                reset();
                continue; // Unmatched characters detected
            }
        }

        // Push character to the temp sequence
        seqTemp.push_back(chPtr);
    }

    string r;
    for_each(seqRet.begin(), seqRet.end(), [&](TypeBufferCh p){
        r.push_back(*p);
    });

    return r;
}
