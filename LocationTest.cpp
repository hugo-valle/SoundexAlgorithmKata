#include <gmock/gmock.h>
#include <sstream>

#include "Location.h"

using namespace std;
using namespace ::testing;

class ALocation : public Test
{
public:
    const double TOLERANCE{0.01};
    const Location ARBITRARY_LOCATION{38.2, -104.5};
};

TEST_F(ALocation, AnswersLatitudeAndLongitude)
{
    Location location{10, 20};

    ASSERT_THAT(location.latitude(), Eq(10));
    ASSERT_THAT(location.longitude(), Eq(20));
}

TEST_F(ALocation, IsNotUnknownWhenLattidueAndLongitudeProvided)
{
    Location location{1, 1};

    ASSERT_FALSE(location.isUnknown());
}

TEST_F(ALocation, IsUnknownWhenLattidueAndLongitudeProvided)
{
    Location location;

    ASSERT_TRUE(location.isUnknown());
}

TEST_F(ALocation, IsNotEqualToAnotherWhenLatDifrent)
{
    Location point1{10, 11};
    Location point2{11, 11};

    ASSERT_TRUE(point1 != point2);
}
TEST_F(ALocation, IsNotEqualToAnotherWhenLongDifrent)
{
    Location point1{10, 11};
    Location point2{10, 12};

    ASSERT_TRUE(point1 != point2);
}

TEST_F(ALocation, AnswersDistanceFromAnotherInMeters)
{
    Location point1{38.017, -104.84};
    Location point2{38.025, -104.99};

    // Validate with: https://andrew.hedges.name/experiments/haversine/
    // distance = 13174 meters
    ASSERT_THAT(point1.distanceInMeters(point2), DoubleNear(13173, 3));
}

TEST_F(ALocation, AnswersNewLocationGivenDistanceandBearing)
{
    double distance{100};
    Location start{38, -78};

    auto end = start.go(distance, 35);
    ASSERT_THAT(distance, DoubleNear(start.distanceInMeters(end), TOLERANCE));
}

TEST_F(ALocation, IsVeryCloseToAnotherWhenSmallDistanceApart)
{
    Location threeMetersAway {ARBITRARY_LOCATION.go(3, South)};

    ASSERT_TRUE(ARBITRARY_LOCATION.isVeryCloseTo(threeMetersAway));
}
