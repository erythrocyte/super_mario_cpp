#include <boost/test/included/unit_test.hpp>
using namespace boost::unit_test;

#include "unit_tests/lib/models/player_tests.hpp"

namespace utlm = sm::tests::unit_tests::lib::models;

test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[])
{
    test_suite* ts_player = BOOST_TEST_SUITE("PlayerTests");
    ts_player->add(BOOST_TEST_CASE(&utlm::player::case1));

    framework::master_test_suite().add(ts_player);

    return 0;
}
