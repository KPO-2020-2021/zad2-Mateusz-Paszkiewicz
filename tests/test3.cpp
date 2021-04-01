#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona Modul i Sprzezenie"){

  LZespolona x,y;

  x.re=2;
  x.im=1;

  y.re=2;
  y.im=-1;

CHECK(x.Sprzezenie()==y);
CHECK(x.ModulDoKwadratu()==5);
}

TEST_CASE("test LZespolona Modul i Sprzezenie dla 0i"){

  LZespolona x;

  x.re=5;
  x.im=0;

  CHECK(x.Sprzezenie()==x);

}
