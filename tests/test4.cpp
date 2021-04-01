#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"

TEST_CASE("<< operator for WyrZespolone"){

    std::string expected = "(2-6i)+(1+1i)";
    std::stringstream buffer, tmp;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    WyrazenieZesp test1;

    tmp << "(2-6i)+(1+1i)";
    tmp >> test1;
    tmp << test1;

    std::cout << test1;
    std::string text = tmp.str();
    std::cout.rdbuf(prevcoutbuf);

    CHECK(text == expected);
}

TEST_CASE("<< operator for LZespolona"){

    std::string expected = "(5-5i)";
    std::stringstream buffer, tmp;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    LZespolona test1;

    tmp << "(5-5i)";
    tmp >> test1;

    std::cout << test1;
    std::string text = tmp.str();
    std::cout.rdbuf(prevcoutbuf);

    CHECK(text == expected);
}
