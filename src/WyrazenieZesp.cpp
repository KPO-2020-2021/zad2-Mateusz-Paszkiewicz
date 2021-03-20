#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

 std::ostream& operator << (std::ostream &StrmWyj, WyrazenieZesp &WyrZ)
 {
  if(WyrZ.Op==Op_Dodaj)
    StrmWyj << WyrZ.Arg1 << '+' << WyrZ.Arg2 << '=';
  if(WyrZ.Op==Op_Odejmij)
    StrmWyj << WyrZ.Arg1 << '-' << WyrZ.Arg2 << '=';
  if(WyrZ.Op==Op_Mnoz)
    StrmWyj << WyrZ.Arg1 << '*' << WyrZ.Arg2 << '=';
  if(WyrZ.Op==Op_Dziel)
    StrmWyj << WyrZ.Arg1 << '/' << WyrZ.Arg2 << '=';
   return StrmWyj;
 }

 std::istream& operator >> (std::istream &StrmWej, WyrazenieZesp &WyrZ)
 {
   char znak;
   StrmWej >> WyrZ.Arg1;
   if(StrmWej.fail())
     return StrmWej;
   StrmWej>>znak;
   if(znak=='+')
      WyrZ.Op=Op_Dodaj;
   if(znak=='-')
      WyrZ.Op=Op_Odejmij;
   if(znak=='*')
      WyrZ.Op=Op_Mnoz;
   if(znak=='/')
      WyrZ.Op=Op_Dziel;
   else
     {
       StrmWej.setstate(std::ios::failbit);
       return StrmWej;
     }
   StrmWej>>WyrZ.Arg2;
   if(StrmWej.fail())
     return StrmWej;

   return StrmWej;
 }


LZespolona Oblicz(WyrazenieZesp Wyrazenie)
{
  LZespolona Wynik;

  if(Wyrazenie.Op==Op_Dodaj)
    Wynik=Wyrazenie.Arg1+Wyrazenie.Arg2;
  if(Wyrazenie.Op==Op_Odejmij)
    Wynik=Wyrazenie.Arg1-Wyrazenie.Arg2;
  if(Wyrazenie.Op==Op_Mnoz)
    Wynik=Wyrazenie.Arg1*Wyrazenie.Arg2;
  if(Wyrazenie.Op==Op_Dziel)
    Wynik=Wyrazenie.Arg1/Wyrazenie.Arg2;
  return Wynik;
}
