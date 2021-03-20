#include "LZespolona.hh"

#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH




/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};

std::ostream& operator << (std::ostream &, WyrazenieZesp &);

std::istream& operator >> (std::istream &, WyrazenieZesp &);

/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */

LZespolona Oblicz(WyrazenieZesp  WyrZ);

#endif
