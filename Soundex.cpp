//
// Created by hugovalle1 on 12/13/2018.
//

#include "Soundex.h"
/**
 * @brief pad word to 4 digits
 * @param word - input string
 * @return - padded string
 */
string Soundex::zeroPad(const string& word)const
{
    auto zerosNeeded = 4 - word.length();
    return word + string(zerosNeeded, '0');
}

/**
 * @brief Encode string to Soundex Algorithm
 * @param word - string to code
 * @return - encoded string
 */
string Soundex::encode(const string& word) const
{
    return zeroPad(head(word) + encodeDigits(word));
}

/**
 * @brief Extract the first char of the string
 * @param word - input string
 * @return - first letter of string "head"
 */
string Soundex::head(const string &word) const
{
    return word.substr(0, 1);
}

/**
 * @brief Encode the string into digits using Soundex Algorithm
 * @param word - input string
 * @return - encoded string
 */
string Soundex::encodeDigits(const string &word) const
{
    if(word.length() > 1)
        return "1";

    return "";
}

