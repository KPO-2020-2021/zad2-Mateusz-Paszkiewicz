#include <iostream>
#include <cmath>
#include "LZespolona.hh"

#define PI 3.14159265
#define MIN_DIFF 0.00001

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  LZespolona::operator == (const LZespolona  &Skl) const {

  if (abs(this->re - Skl.re) <= MIN_DIFF && abs(this->im - Skl.im) <= MIN_DIFF)
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
 LZespolona  LZespolona::operator + (const LZespolona &Skl){
  LZespolona  Wynik;

  Wynik.re = Skl.re + this->re;
  Wynik.im = Skl.im + this->im;
  return Wynik;
}

LZespolona  LZespolona::operator += (const LZespolona &Skl){

 this->re+=Skl.re;
 this->im+=Skl.im;
 return (*this);
}

LZespolona  LZespolona::operator /= (LZespolona &Skl){

 (*this)=(*this)/Skl;

 return (*this);
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - ujemna
 *    Skl2 - ujemnik
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator - (const LZespolona &Skl){
  LZespolona  Wynik;

  Wynik.re = this->re - Skl.re;
  Wynik.im = this->im - Skl.im;
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
LZespolona  LZespolona::operator * (const LZespolona  &Skl){
  LZespolona  Wynik;

  Wynik.re = this->re * Skl.re - this->im * Skl.im;
  Wynik.im = this->re * Skl.im + this->im * Skl.re;
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
LZespolona  LZespolona::operator / (const double  &Skl2){
  LZespolona  Wynik;

  Wynik.re = this->re / Skl2;
  Wynik.im = this->im / Skl2;
  return Wynik;
}

/*!
 * Realizuje sprzezenie liczby zespolonej.
 * Argumenty:
 *    Skl1 - liczba zespolona do sprzezenia,
 * Zwraca:
 *    Sprzezenie liczby zesp. podanej jako argument
 */
LZespolona LZespolona::Sprzezenie()
{
  LZespolona Wynik;

  Wynik.re=this->re;
  Wynik.im=-this->im;

  return Wynik;
}

/*!
 * Liczy modul do kwadratu liczby zespolonej.
 * Argumenty:
 *    Skl1 - liczba zespolona
 * Zwraca:
 *    modul parametru podniesiony do kwadratu
 */
double LZespolona::ModulDoKwadratu()
{
  double Wynik;

  Wynik = (this->re*this->re)+(this->im*this->im);
  return Wynik;
}

LZespolona  LZespolona::operator / (LZespolona  &Skl){
  LZespolona  Wynik;

  Wynik = *this*Skl.Sprzezenie()/Skl.ModulDoKwadratu();
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


double LZespolona::arg()
{
  double arg;

  if(this->re==0 && this->im==0)
    return NAN;

  if(this->re!=0 && this->im!=0)
  {
    if(this->re>0)
      arg=atan2(this->im, this->re);
    else
      arg=atan2(this->im, this->re)+PI;
  }
  if(this->re==0)
  {
    if(this->im>0)
      arg=PI/2;
    else
      arg=-PI/2;
  if(this->im==0)
    {
    if(this->re>0)
      arg=0;
    else
      arg=PI;
    }
  }

  return arg; //arg w radianach
}
