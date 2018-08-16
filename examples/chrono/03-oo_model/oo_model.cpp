#include <vector>

#include "oo_model.hpp"

#include <iostream>

#define GRAVITY -10

Corpo::Corpo(float massa, float velocidade, float posicao, float k_mola, float pos_equilibrio, float coef_atrito) {
  this->massa = massa;
  this->velocidade = velocidade;
  this->posicao = posicao;
  this->k_mola = k_mola;
  this->pos_equilibrio = pos_equilibrio;
  this->coef_atrito = coef_atrito;


}

void Corpo::update(float nova_velocidade, float nova_posicao) {
  this->velocidade = nova_velocidade;
  this->posicao = nova_posicao;
}

float Corpo::get_massa() {
  return this->massa;
}

float Corpo::get_velocidade() {
  return this->velocidade;
}

float Corpo::get_posicao() {
  return this->posicao;
}

float Corpo::get_k_mola() {
  return this->k_mola;
}

float Corpo::get_pos_equilibrio() {
  return this->pos_equilibrio;
}

float Corpo::get_coef_atrito() {
  return this->coef_atrito;
}


ListaDeCorpos::ListaDeCorpos() {
  this->corpos = new std::vector<Corpo *>(0);
}

void ListaDeCorpos::add_corpo(Corpo *c) {
  (this->corpos)->push_back(c);
  std::cout << "Agora tenho: " << this->corpos->size() << " elementos" << std::endl;
}

std::vector<Corpo*> *ListaDeCorpos::get_corpos() {
  return (this->corpos);
}

Fisica::Fisica(ListaDeCorpos *ldc) {
  this->lista = ldc;
}

void Fisica::update(float deltaT, float entrada) {
  // Atualiza parametros dos corpos!
  std::vector<Corpo *> *c = this->lista->get_corpos();
  for (int i = 0; i < (*c).size(); i++) {
	// Adicionando mais forças ao sistema além da gravidade:
	float forca = GRAVITY * (*c)[i]->get_massa() +
			-(*c)[i]->get_k_mola() * ((*c)[i]->get_posicao() - (*c)[i]->get_pos_equilibrio()) +
			-(*c)[i]->get_coef_atrito() * (*c)[i]->get_velocidade() +
			entrada;
    float new_vel = (*c)[i]->get_velocidade() + (float)deltaT *forca/(*c)[i]->get_massa()/1000;
    float new_pos = (*c)[i]->get_posicao() + (float)deltaT * new_vel/1000;
    (*c)[i]->update(new_vel, new_pos);
  }
}


