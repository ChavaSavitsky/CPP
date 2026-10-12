#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Question.h"

TEST_CASE("Initialize Histogram and check bins") {
    Histogram hist(1.0, 1.6, 3);
    CHECK_EQ(hist.get(0), 0);
    CHECK_EQ(hist.get(1), 0);
    CHECK_EQ(hist.get(2), 0);
}

TEST_CASE("Add values to Histogram") {
    Histogram hist(1.0, 1.6, 3);
    hist.append(1.0);
    hist.append(1.1);
    CHECK_EQ(hist.get(0), 2);

    hist.append(1.3);
    CHECK_EQ(hist.get(1), 1);

    hist.append(1.7);  // This tests the upper out-of-range values going to last bin
    CHECK_EQ(hist.get(2), 1);
}

TEST_CASE("Histogram out-of-bounds access") {
    Histogram hist(1.0, 1.6, 3);
    CHECK_THROWS_AS(hist.get(-1), std::out_of_range);
    CHECK_THROWS_AS(hist.get(3), std::out_of_range);
}

TEST_CASE("Histogram initialization errors") {
    CHECK_THROWS_AS(Histogram(1.6, 1.0, 3), std::invalid_argument);
    CHECK_THROWS_AS(Histogram(1.0, 1.6, 0), std::invalid_argument);
}

TEST_CASE("Testing getBinIndex") {
    Histogram hist(1.0, 1.6, 3);
    CHECK_EQ(hist.getBinIndex(0.99), 0);
    CHECK_EQ(hist.getBinIndex(1.0), 0);
    CHECK_EQ(hist.getBinIndex(1.21), 1);
    CHECK_EQ(hist.getBinIndex(1.4), 1);
    CHECK_EQ(hist.getBinIndex(1.41), 2);
    CHECK_EQ(hist.getBinIndex(1.8), 2);
}