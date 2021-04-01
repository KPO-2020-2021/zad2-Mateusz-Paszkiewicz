#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test for << operator for LZespolona"){

    std::string expected = "(2-6i)";
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    LZespolona x;
    x.re=2;
    x.im=-6;

    std::cout << x;
    std::string text = buffer.str();
    std::cout.rdbuf(prevcoutbuf);

    CHECK(text == expected);
}
