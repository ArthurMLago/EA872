// Laboratorio 1
// Arthur Moraes do Lago (157702)
// Vitor Saldanha da Silveira (158508)

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

#include "01-playback.hpp"
#include "oo_model.hpp"

using namespace std::chrono;
uint64_t get_now_ms() {
  return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

int main ()
{
  Corpo *c1 = new Corpo(10, 0, 15, 20, 10, 5);
  Corpo *c2 = new Corpo(10, 0, 20, 20, 10, 3);
  Corpo *c3 = new Corpo(10, 0, 15, 10, 10, 2);
  Corpo *c4 = new Corpo(10, 0, 10, 20, 10, 3);

  ListaDeCorpos *l = new ListaDeCorpos();
  l->add_corpo(c1);
  l->add_corpo(c2);
  l->add_corpo(c3);
  l->add_corpo(c4);

  Fisica *f = new Fisica(l);

  Tela *tela = new Tela(l, 20, 20);
  tela->init();
  
  Teclado *teclado = new Teclado();
  teclado->init();
  
  Audio::Sample *asample;
  asample = new Audio::Sample();
  asample->load("assets/blip.dat");

  Audio::Player *player;
  player = new Audio::Player();
  player->init();

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
    //f->update(deltaT, 0);

    // Atualiza tela
    tela->update();

    // Lê o teclado
    char c = teclado->getchar();
    if (c =='w') {
		f->update(deltaT, -1000);
		
  		asample->set_position(0);
  		player->play(asample);
    }else if (c == 's'){
		f->update(deltaT, +1000);

  		asample->set_position(0);
  		player->play(asample);
	}else{	
		f->update(deltaT, 0);
	}
    if (c=='q') {
      break;
    }

    // Condicao de parada
    if ( (t1-T) > 300000 ) break;

    std::this_thread::sleep_for (std::chrono::milliseconds(30));
    i++;
  }
  
  
  tela->stop();
  player->stop();
  
  return 0;
}
