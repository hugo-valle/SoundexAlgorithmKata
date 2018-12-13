#include <iostream>
#include <string>
using namespace std;
class Soundex
{
    /**
     * @brief pad word to 4 digits
     * @param word - input string
     * @return - padded string
     */
    string zeroPad(const string& word)const
    {
        return word + "000";
    }
public:
    /**
     * @brief Encode string to Soundex Algorithm
     * @param word - string to code
     * @return - encoded string
     */
    string encode(const string& word) const
    {
       return zeroPad(word);
    }

};


#include "gmock/gmock.h"
using ::testing::Eq;
TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
   // Arrange
   Soundex soundex;
   // Act
   auto encode = soundex.encode("A");
   // Assert
   ASSERT_THAT(encode, Eq("A000"));
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    // Arrange
    Soundex soundex;
    // Act
    auto encode = soundex.encode("I");
    // Assert
    ASSERT_THAT(encode, Eq("I000"));
}
