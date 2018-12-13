//
// Created by hugovalle1 on 12/13/2018.
//

#ifndef FIRSTEXAMPLE_SOUNDEX_H
#define FIRSTEXAMPLE_SOUNDEX_H

#include <iostream>
#include <string>
using namespace std;
/**
 * Soundex Algorithm Class
 */
class Soundex
{
private:
    string zeroPad(const string& word) const;
    string head(const string& word) const;
    string encodeDigits(const string& word)const;
public:
    string encode(const string& word) const;
};


#endif //FIRSTEXAMPLE_SOUNDEX_H
