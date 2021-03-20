#include <iostream>
#include "Statystyki.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

Stats SetStats(bool is_corr, Stats sample)
{
  sample.current_ans_count++;
  if(is_corr == true)
    sample.correct_ans++;

  sample.correct_ans_prctg=100*sample.correct_ans/sample.current_ans_count;
  return sample;
}

void display_stats(Stats sample)
{
  std::cout<<"Wynik: "<<sample.correct_ans<<"/"<<sample.current_ans_count<<" - - - "<<sample.correct_ans_prctg<<"%";
}
