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

TEST(ATweet, IsLessThanWhenUserAndMessgeAre)
{
    Tweet a("msg", "@user1");
    Tweet b("msg", "@user2");

    // Lt: less than
    ASSERT_THAT(a, Lt(b));
}

TEST(ATweet, IsLessThanWhenUserEqualAndMessgIsLessThan)
{
    Tweet a("msgA", "@user");
    Tweet b("msgB", "@user");

    // Lt: less than
    ASSERT_THAT(a, Lt(b));
}

TEST(ATweet, CanCopyConstructed)
{
    Tweet a("msgA", "@user");
    Tweet b(a);

    ASSERT_THAT(a, Eq(b));
}

TEST(ATweet, RequireUserToStartWithAtSign)
{
    string invalidUser("notStaringWith@");

    // For any exception
    //ASSERT_ANY_THROW(Tweet tweet("msg", invalidUser));

    //If you know the exception
    ASSERT_THROW(Tweet tweet("msg", invalidUser), InvalidUserException);
}

TEST(ATweet, RequireUserToStartWithAtSign2)
{
    string invalidUser("notStaringWith@");
    try {

        Tweet tweet("msg", invalidUser);
        FAIL();
    }
    catch (const InvalidUserException& expected) {}
}
