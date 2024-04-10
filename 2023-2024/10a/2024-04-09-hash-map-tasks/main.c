// https://leetcode.com/problems/ransom-note/?envType=study-plan-v2&envId=top-interview-150

bool canConstruct(char *ransomNote, char *magazine)
{
    int letterOccurences[26] = {0};

    for (int i = 0; ransomNote[i] != '\0'; i++)
    {
        char key = ransomNote[i];
        letterOccurences[key - 'a']++;
    }

    for (int i = 0; magazine[i] != '\0'; i++)
    {
        letterOccurences[magazine[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (letterOccurences[i] > 0)
        {
            return false;
        }
    }

    return true;
}

// https://leetcode.com/problems/isomorphic-strings/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> char_map;
        unordered_map<char, char> char_map2;

        /*
            {
                b: b,
                a: a,
            }
        */

        for (int i = 0; s[i] != '\0'; i++)
        {
            if (char_map[s[i]] && char_map[s[i]] != t[i])
            {
                return false;
            }
            if (char_map2[t[i]] && char_map2[t[i]] != s[i])
            {
                return false;
            }

            char_map[s[i]] = t[i];
            char_map2[t[i]] = s[i];
        }

        return true;
    }
};