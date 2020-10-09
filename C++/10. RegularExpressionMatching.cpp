/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa"
*/
class Solution
{
    bool is_match(const char *s, const char *p)
    {
        if (*p == 0)
            return *s == 0;
        bool first_match = *s && (*s == *p || *p == '.');
        if (*(p + 1) == '*')
        {
            return is_match(s, p + 2) || (first_match && is_match(++s, p));
        }
        else
        {
            return first_match && is_match(++s, ++p);
        }
    }

public:
    bool isMatch(string s, string p)
    {
        return is_match(s.c_str(), p.c_str());
    }
};
