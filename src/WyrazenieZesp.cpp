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


LZespolona WyrazenieZesp::Oblicz()
{
  LZespolona Wynik;

  if(this->Op==Op_Dodaj)
    Wynik=this->Arg1+this->Arg2;
  if(this->Op==Op_Odejmij)
    Wynik=this->Arg1-this->Arg2;
  if(this->Op==Op_Mnoz)
    Wynik=this->Arg1*this->Arg2;
  if(this->Op==Op_Dziel)
    Wynik=this->Arg1/this->Arg2;
  return Wynik;
}
