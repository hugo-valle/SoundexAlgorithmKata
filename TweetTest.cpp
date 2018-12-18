#include <gmock/gmock.h>
#include "Tweet.h"

using namespace std;
using namespace ::testing;

TEST(ATweet, DefaultUserNotNullWhenNotProvided)
{
    Tweet tweet("msg");

    ASSERT_THAT(tweet.getUser_(), Eq("@null"));
}

TEST(ATweet, IsEqualToAntherWhenMessageAndUserAreEqual)
{
    Tweet a("msg", "@user");
    Tweet b("msg", "@user");

    ASSERT_THAT(a, Eq(b));
}

TEST(ATweet, IsNotEqualToAnotherWhenMessageAreUnEqual)
{
    Tweet a("msgX", "@user");
    Tweet b("msgY", "@user");

    ASSERT_THAT(a, Ne(b));
}
