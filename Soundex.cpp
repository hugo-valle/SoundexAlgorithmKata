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
    return word + "000";
}
/**
 * @brief Encode string to Soundex Algorithm
 * @param word - string to code
 * @return - encoded string
 */
string Soundex::encode(const string& word) const
{
    return zeroPad(word);
}

