// Laboratorio 1
// Arthur Moraes do Lago (157702)
// Vitor Saldanha da Silveira (158508)

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

#include "oo_model.hpp"

using namespace std::chrono;
uint64_t get_now_ms() {
  return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

int main ()
{
  Corpo *c1 = new Corpo(10, 0, 25, 20, 10, 5);
  Corpo *c2 = new Corpo(10, 0, 20, 20, 10, 0);
  Corpo *c3 = new Corpo(10, 0, 35, 20, 10, 2);
  Corpo *c4 = new Corpo(10, 0, 10, 20, 10, 0);
  Corpo *c5 = new Corpo(10, 0, 20, 0, 10, 0);
  Corpo *c6 = new Corpo(10, 0, 0, 0, 10, 0);

  ListaDeCorpos *l = new ListaDeCorpos();
  l->add_corpo(c1);
  l->add_corpo(c2);
  l->add_corpo(c3);
  l->add_corpo(c4);
  l->add_corpo(c5);
  l->add_corpo(c6);

  Fisica *f = new Fisica(l);

  Tela *tela = new Tela(l, 20, 20);
  tela->init();

  uint64_t t0;
  uint64_t t1;
  uint64_t deltaT;
  uint64_t T;

  int i = 0;

  T = get_now_ms();
  t1 = T;
  while (1) {
    // Atualiza timers
    t0 = t1;
    t1 = get_now_ms();
    deltaT = t1-t0;

    // Atualiza modelo
    f->update(deltaT, 0);

    // Atualiza tela
    tela->update();

    // Condicao de parada
    if ( (t1-T) > 30000 ) break;

    std::this_thread::sleep_for (std::chrono::milliseconds(20));
    i++;
  }
  tela->stop();
  return 0;
}
