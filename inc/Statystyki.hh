#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH

/*
 * Tu nalezy zdefiniowac funkcje, ktore definiuja model statystyki
 */

 struct Stats{
   int    correct_ans;   // Dobre odpowiedzi
   int    current_ans_count;     // Wszystkie odpowiedzi
   int    correct_ans_prctg;   // wynik procentowy
 };

Stats SetStats(bool, Stats);

void display_stats(Stats);

#endif
