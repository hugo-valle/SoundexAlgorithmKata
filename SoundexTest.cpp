#include <iostream>
#include <string>
using namespace std;
class Soundex
{
public:
    string encode(const string& word) const
    {
       return word;
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
   ASSERT_THAT(encode, Eq("A"));
}

