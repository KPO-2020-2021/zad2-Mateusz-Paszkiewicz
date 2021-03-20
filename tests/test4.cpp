#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"

TEST_CASE("<< operator for WyrZespolone"){

    std::string expected = "(2-6i)+(1+1i)";
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    WyrazenieZesp test1;

    buffer << "(2-6i)+(1+1i)";
    buffer >> test1;

    std::cout << test1;
    std::string text = buffer.str();
    std::cout.rdbuf(prevcoutbuf);

    CHECK(text == expected);
}
