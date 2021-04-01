#include <iostream>
#include <limits>
#include "BazaTestu.hh"





int main(int argc, char **argv)
{

  if (argc < 2) {
    std::cout << std::endl;
    std::cout << " Brak opcji okreslajacej rodzaj testu." << std::endl;
    std::cout << " Dopuszczalne nazwy to:  latwy, trudny." << std::endl;
    std::cout << std::endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    std::cerr << " Inicjalizacja testu nie powiodla sie." << std::endl;
    return 1;
  }



  std::cout << std::endl;
  std::cout << " Start testu arytmetyki zespolonej: " << argv[1] << std::endl;
  std::cout << std::endl;



  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona User_Ans;
  int err_count=0;


  Stats Curr_stats;
  Curr_stats.correct_ans=0;
  Curr_stats.current_ans_count=0;
  Curr_stats.correct_ans_prctg=0;



  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    std::cout << " Pytanie nr. "<< BazaT.IndeksPytania << " : ";
    std::cout << WyrZ_PytanieTestowe << '?' << std::endl;
    std::cout << " Podaj odpowiedz : ";



    while(err_count!=3 && !(std::cin>>User_Ans))
    {
      if(err_count<2)
        std::cout<<"Bledny format, prosze sporbowac ponownie: ";
      else
        std::cout<<"Zbyt duzo prob, opuszczono pytanie...             ";


      err_count++;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if(err_count!=3)
    {
      if(User_Ans==WyrZ_PytanieTestowe.Oblicz())
      {
        Curr_stats=SetStats(true, Curr_stats);
        std::cout<<"Odpowiedz poprawna"<< "             ";
        display_stats(Curr_stats);
        std::cout << std::endl;

        std::cin.clear();
        err_count=0;
      }
      else
      {
        Curr_stats=SetStats(false, Curr_stats);
        LZespolona corr_val=WyrZ_PytanieTestowe.Oblicz();
        std::cout << std::endl;
        std::cout << "Odpowiedz niepoprawna"<<"             ";
        display_stats(Curr_stats);
        std::cout << std::endl;
        std::cout << "Poprawna odpowiedz to : ";
        std::cout << corr_val << std::endl;
        std::cout << std::endl;

        err_count=0;
        std::cin.clear();
      }
    }
    else
    {
      Curr_stats=SetStats(false, Curr_stats);
      display_stats(Curr_stats);
      std::cout << std::endl;

      err_count=0;
      std::cin.clear();
    }
  }


  std::cout << std::endl;
  std::cout << " - - - Koniec testu - - - " << std::endl;
  std::cout << std::endl;
  display_stats(Curr_stats);


  LZespolona a1, a2;

  a1.re=1;
  a1.im=5;

  a2.re=1;
  a2.im=5;

  a1/=a2;

  std::cout<<a1;

}
