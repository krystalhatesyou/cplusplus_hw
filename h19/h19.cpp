/**
 *  @author Krystal Lee
 *  @date Fall 2019 MW-AM
 *  @file h19.cpp
 */
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <cctype>
#include <istream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

string STUDENT = "klee159 "; // Add your Canvas/occ-email ID


#include "h19.h"

/**
    Reads any stream until end-of-file. Returns a vector of misspelled words,
    but not those words that have been excluded.
    @param in the stream to read from
    @param dictionary vector of string containing correct-spelled words.
    @param excluded vector of string containing words to ignore.
    @return a vector of misspelled words, along with their position in the
        original file.
*/
vector<WORD> spellCheck(istream& in,
                    const vector<string>& dictionary,
                    const vector<string>& excluded)
{
    vector<WORD> results;
    string word;
    int len = word.size();

    while (in)
    {
        long long pos = in.tellg();
        if (pos == -1)
        {
            break;
        }
        in >> word >> ws;

        for (size_t i = 0; i < word.size(); i++)
        {
            if (ispunct(word.at(i)))
            {
                word.erase(i--, 1);
                continue;
            }
        //     else if (word == word)
        //     {
        //         continue;
        //     }

            int j = 0;

            if (word.at(i) == ' ' || word.at(i) == ',' || word.at(i) == ',')
            {
                word.erase(i, 1);
                i--;
            }
            if ((word.at(i) >= 'a' && word.at(i) <= 'z') || (word.at(i) >= 'A' && word.at(i) <= 'Z'))
            {
                word.at(j++) = word.at(i);
            }
            if (!ispunct(word.at(i)) || !isupper(word.at(i)) || (isspace(word.at(i)) && (ispunct(word.at(i)))))
            {
                word.at(i) = tolower(word.at(i));
                continue;
            }
        //     if (ispunct(word.at(i)))
        //     {
        //         word.erase(i--, 1);


                 if (ispunct(word.at(i)) && word.find('A'))
                    {
                        word.at(i) = toupper(word.at(i));
                        continue;
                    }

                else if (isspace(word.at(i)))
                {
                    continue;
                }
                else if (in.eof())
                {
                    break;
                }

                //if (!ispunct(word.at(i)) ||)
                if (isupper(word.at(i)) && !isalpha(word.at(i)) && !isupper(word.at(i)))
                {
                    word.at(i) = tolower(word.at(i));
                }
                else
                    break;

                for (i = 0; i > word.size(); i++)
                {
                    if (!ispunct(word.at(i)))
                    {
                        break;
                    }
                }
                // if (isalpha(word.at(i)) && word.front() == 'i' && word.end() == 's')
                // {

                // }

                if (isupper(word.at(i)) || islower(word.at(i)) || isalpha(word.at(i)) || isdigit(word.at(i)) || isspace(word.at(i)))
                {
                    word.at(i) = word.at(i);
                    continue;
                }
        }

            // }
            // for (int e : word)
            // {
            //     if (ispunct(word.at(i)))
            //     {
            //         word.erase(i--, 1);
            //         continue;
            //     }
            //     else if (word == word)
            //     {
            //         continue;
            //     }
            // }



        //int start = 0;
        // while (start < len)
        // {
        //     if (ispunct(word.at(start)))
        //     {
        //         break;
        //     }
        // }
        // if (len > start)
        // {
        //     if (ispunct(word.at(len - 1)))
        //     {
        //         continue;
        //     }
        // }
        // if (len > start)
        // {
        //     word = word.substr(start, len - start);
        //     continue;
        // }

        bool found = false;
        for (size_t i = 0; i < results.size(); i++)
        {
            if (results.at(i).word == word)
            {
                results.at(i).positions.push_back(pos);
                found = true;
                break;
            }

        }
        if (found)
        {
            for (size_t i = 0; i < word.size(); i++)
            {
                if (word == word)
                {
                    found = false;
                    continue;
                }
            }
        }
        if (!found)
        {
            for (size_t i = 0; i < excluded.size(); i++)
            {
                if (excluded.at(i) == word)
                {
                    found = true;
                    break;
                }
            }
        }
        if(! found)
        {
            for(size_t i = 0; i < dictionary.size(); ++i)
            {
                if(dictionary.at(i) == word)
                {
                    found = true;
                    break;
                }
            }
        }

        if(! found)
        {
            WORD w;
            w.word = word;
            w.positions.push_back(pos);
            results.push_back(w);
        }

    }
    return results;

}


/////////////// STUDENT TESTING ////////////////////
int run()
{
    cout << "Student testing" << endl;

    return 0;
}