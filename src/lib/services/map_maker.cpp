#include "map_maker.hpp"

namespace sm::src::lib::services::map_maker {

std::string generate_roof(int col_count)
{
    return std::string(col_count, '0');
}

std::string generate_flour(int col_count)
{
    return std::string(col_count, 'P');
}

std::string generate_random_row(int col_count)
{
    return "";
}

std::vector<std::string> generate_random(int row_count, int col_count, int roof_count, int flour_count)
{
    std::vector<std::string> result;
    result.insert(result.end(), roof_count, generate_roof(col_count));
    for (int k = 0; k < col_count - (roof_count + flour_count); k++) {
        result.push_back(generate_random_row(col_count));
    }
    result.insert(result.end(), flour_count, generate_flour(col_count));

    return result;
}

std::vector<std::string> generate_sample()
{
    std::vector<std::string> result;
    result.push_back("000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    result.push_back("0                                                                                                                                                    0");
    result.push_back("0                                                                                    w                                                               0");
    result.push_back("0                   w                                  w                   w                                                                         0");
    result.push_back("0                                      w                                       kk                                                                    0");
    result.push_back("0                                                                             k  k    k    k                                                         0");
    result.push_back("0                      c                                                      k      kkk  kkk  w                                                     0");
    result.push_back("0                                                                       r     k       k    k                                                         0");
    result.push_back("0                                                                      rr     k  k                                                                   0");
    result.push_back("0                                                                     rrr      kk                                                                    0");
    result.push_back("0               c    kckck                                           rrrr                                                                            0");
    result.push_back("0                                      t0                           rrrrr                                                                            0");
    result.push_back("0G                                     00              t0          rrrrrr            G                                                               0");
    result.push_back("0           d    g       d             00              00         rrrrrrr                                                                            0");
    result.push_back("PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP");
    result.push_back("PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP");
    result.push_back("PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP");

    return result;
}
}
