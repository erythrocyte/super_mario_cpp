// #define BOOST_TEST_DYN_LINK
// #define BOOST_TEST_MODULE ShockFrontTests
#include <boost/test/unit_test.hpp>

#include <iostream>
#include <memory>

#include "lib/models/player.hpp"

namespace lbm = sm::src::lib::models;

namespace sm::tests::unit_tests::lib::models::player {

void case1()
{
    // arrange
    double expected = 1;

    // act
    double actual = 1;

    // assert
    BOOST_CHECK_CLOSE(expected, actual, 1e-8);
}

}