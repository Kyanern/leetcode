//Please open this solution in VS2019
//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3728/
//2021 05 19

//STATUS: ACCEPTED

#include <vector>
#include <string>

using namespace std;

class WordFilter
{
private:
    vector<string> words_;
    size_t words_size;
    vector<size_t> uniques;
public:
    WordFilter(vector<string>& words) : words_(words)
    {
        words_size = words_.size();
        size_t idx = words_size;
        while (idx > 0)
        {
            --idx;
            const string& word = words_[idx];
            bool addAsUnique = true;
            for (auto itr = uniques.begin(); itr != uniques.end(); itr++)
            {
                if (word.compare(words_[*itr]) == 0)
                {
                    addAsUnique = false;
                    break;
                }
            }
            if (addAsUnique)
            {
                uniques.push_back(idx);
            }
        }
    }

    bool f_helperAreLengthsOk(const size_t& lenWord, const size_t& lenPre, const size_t& lenSuf)
    {
        if (lenPre > lenWord || lenSuf > lenWord)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool f_helperCheckPrefix(const string& word, const size_t& lenWord, const string& prefix, const size_t& lenPre)
    {
        int result = word.compare(0, lenPre, prefix);
        return (result == 0 ? true : false);
    }

    bool f_helperCheckSuffix(const string& word, const size_t& lenWord, const string& suffix, const size_t& lenSuf)
    {
        int result = word.compare(lenWord - lenSuf, lenSuf, suffix);
        return (result == 0 ? true : false);
    }

    int f(string prefix, string suffix)
    {
        // edge case: words_ is empty (not actually needed as described in problem constraints)
        /*
        if(words_.empty())
        {
          return -1;
        }
        */

        /******
        // algorithm idea:
        // use length to extract substring from words_[i] and
        // do string comparison on substring with pre/suffix
        // (uses string::compare)
        *******/
        //first get prefix, suffix strlen
        size_t lenPre = prefix.length();
        size_t lenSuf = suffix.length();

        // problem asks to return the largest index, so we'll start from reverse.
        // our uniques vector should take care of that already.
        // so we'll just iterate through the indices stored in uniques.
        for (auto itr = uniques.begin(); itr != uniques.end(); ++itr)
        {
            const string& word = words_[*itr];
            size_t lenWord = word.length();
            if (f_helperAreLengthsOk(lenWord, lenPre, lenSuf))
            {
                if (f_helperCheckPrefix(word, lenWord, prefix, lenPre))
                {
                    if (f_helperCheckSuffix(word, lenWord, suffix, lenSuf))
                    {
                        return *itr;
                    }
                }
            }
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

int main(void)
{
    /**********
    * Create a test case/suite here
    **********/

    return 0;
}