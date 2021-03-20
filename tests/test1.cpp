#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;

CHECK(x+y == z);
}

TEST_CASE("test LZespolona Odejmowanie"){
    LZespolona x, y, z, c;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 0;
    z.im = 4;

    c.re= 0.0000001;
    c.im= 3.9999999;



CHECK(x-y == z);
CHECK(z==c);
}

TEST_CASE("test LZespolona Mnozenie"){

    LZespolona x, y, z;


    x.re = 2;
    x.im = 1;

    y.re = 2;
    y.im = 2;

    z.re = 2;
    z.im = 6;

CHECK(x*y == z);
}

TEST_CASE("test LZespolona dzielenie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 8;

    y.re = 2;
    y.im = 3;

    z.re = 2;
    z.im = 1;

CHECK(x/y == z);
}


TEST_CASE("test LZespolona Odejmowanie"){
  LZespolona x, z;
  double y;

    x.re = 4;
    x.im = 4;

    y=4;

    x=x/y;
    z.re=1;
    z.im=1;

CHECK(z==x);
}
