#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "WyrazenieZesp.hh"

TEST_CASE("test for WyrZesp operaotrs"){

  WyrazenieZesp x;
  LZespolona a1, a2, z;

  a1.re=1;
  a1.im=5;

  a2.re=1;
  a2.im=5;

  x.Arg1=a1;
  x.Arg2=a2;

  x.Op=Op_Dodaj;

  z.re=2;
  z.im=10;

  CHECK(x.Oblicz() == z);

  x.Op=Op_Odejmij;

  z.re=0;
  z.im=0;

  CHECK(x.Oblicz() == z);

  x.Op=Op_Mnoz;

  z.re=-24;
  z.im=10;

  CHECK(x.Oblicz() == z);

  x.Op=Op_Dziel;

  z.re=1;
  z.im=0;

  CHECK(x.Oblicz() == z);
}

TEST_CASE("New operators += and /= for LZespolona"){

  LZespolona a1, a2, z;

  a1.re=1;
  a1.im=5;

  a2.re=1;
  a2.im=5;

  z.re=2;
  z.im=10;

  a1+=a2;

  CHECK(a1==z);

  z.re=1;
  z.im=0;

  a1.re=1;
  a1.im=5;

  a2.re=1;
  a2.im=5;

  a1/=a2;

  CHECK(a1==z);
}
