#include <iostream>
#include <cmath>
#include "LZespolona.hh"

#define MIN_DIFF 0.00001

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2){
  /*if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
    return true;
  else
    return false;*/
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  if (abs(Skl1.re - Skl2.re) <= MIN_DIFF && abs(Skl1.im - Skl2.im) <= MIN_DIFF)
    return true;
  else
    return false;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - ujemna
 *    Skl2 - ujemnik
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - mnozna
 *    Skl2 - mnoznik
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}


/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}

/*!
 * Realizuje sprzezenie liczby zespolonej.
 * Argumenty:
 *    Skl1 - liczba zespolona do sprzezenia,
 * Zwraca:
 *    Sprzezenie liczby zesp. podanej jako argument
 */
LZespolona Sprzezenie(LZespolona Skl1)
{
  LZespolona Wynik;

  Wynik.re=Skl1.re;
  Wynik.im=-Skl1.im;

  return Wynik;
}

/*!
 * Liczy modul do kwadratu liczby zespolonej.
 * Argumenty:
 *    Skl1 - liczba zespolona
 * Zwraca:
 *    modul parametru podniesiony do kwadratu
 */
double ModulDoKwadratu(LZespolona Skl1)
{
  double Wynik;

  Wynik = (Skl1.re*Skl1.re)+(Skl1.im*Skl1.im);
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  LZespolona Skl2){
  LZespolona  Wynik;

  Wynik = Skl1*Sprzezenie(Skl2)/ModulDoKwadratu(Skl2);
  return Wynik;
}

std::ostream& operator << (std::ostream &StrmWyj, LZespolona &LZesp)
{
  StrmWyj << "(" << LZesp.re << std::showpos << LZesp.im << std::noshowpos << "i)";
  return StrmWyj;
}

std::istream& operator >> (std::istream &StrmWej, LZespolona &LZesp)
{
  char nawias, litera;
  StrmWej >> nawias;
  if(StrmWej.fail())
    return StrmWej;
  if(nawias!='(')
    {
      StrmWej.setstate(std::ios::failbit);
      return StrmWej;
    }
  StrmWej>>LZesp.re;
  if(StrmWej.fail())
    return StrmWej;
  StrmWej>>LZesp.im;
  if(StrmWej.fail())
    return StrmWej;
  StrmWej>>litera;
  if(StrmWej.fail())
    return StrmWej;
  if(litera!='i')
    {
      StrmWej.setstate(std::ios::failbit);
      return StrmWej;
    }
  StrmWej>>nawias;
  if(StrmWej.fail())
    return StrmWej;
  if(nawias!=')')
  {
    StrmWej.setstate(std::ios::failbit);
    return StrmWej;
  }
  return StrmWej;
}
