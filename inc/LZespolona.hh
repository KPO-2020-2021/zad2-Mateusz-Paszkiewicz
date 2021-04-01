#include <iostream>
#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH


/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  bool operator == (const LZespolona&) const ;

  LZespolona Sprzezenie();
  double ModulDoKwadratu();
  double arg();

  LZespolona operator + (const LZespolona&);
  LZespolona operator - (const LZespolona&);
  LZespolona operator * (const LZespolona&);
  LZespolona operator / (LZespolona&);
  LZespolona operator / (const double&);
  LZespolona operator += (const LZespolona&);
  LZespolona operator /= (LZespolona&);
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

std::ostream& operator << (std::ostream&, LZespolona&);

std::istream& operator >> (std::istream&, LZespolona&);

#endif
