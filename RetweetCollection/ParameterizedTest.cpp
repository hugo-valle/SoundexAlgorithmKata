#include <gmock/gmock.h>
using namespace ::testing;

class Adder
{
public:
    static int sum(int a, int b)
    {
        return a + b;
    }
};

struct SumCase
{
    int a, b, expected;
    SumCase(int anA, int aB, int anExpected)
    : a(anA), b(aB), expected(anExpected) {}
};

class AnAdder : public TestWithParam<SumCase>
{};

TEST_P(AnAdder, GenerateLotsOfSumsFromTwoNumbers)
{
    SumCase input = GetParam();
    ASSERT_THAT(Adder::sum(input.a, input.b), Eq(input.expected));
}
SumCase sums [] = {
        SumCase(1, 1, 2),
        SumCase(1, 2, 3),
        SumCase(2, 4, 6),
        SumCase(9, 3, 11)
};
INSTANTIATE_TEST_CASE_P(Bulktest, AnAdder, ValuesIn(sums));

TEST(AnAdder, GenerateASumFromTwoNumbers)
{
    ASSERT_THAT(Adder::sum(1, 1), Eq(2));
}
