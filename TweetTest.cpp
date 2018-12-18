#include <gmock/gmock.h>
#include "Tweet.h"

using namespace std;
using namespace ::testing;

TEST(ATweet, DefaultUserNotNullWhenNotProvided)
{
    Tweet tweet("msg");

    ASSERT_THAT(tweet.getUser_(), Eq("@null"));
}
