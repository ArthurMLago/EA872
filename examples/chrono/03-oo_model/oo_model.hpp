
#ifndef OO_MODEL_HPP
#define OO_MODEL_HPP

class Corpo {
  private:
  float massa;
  float velocidade;
  float posicao;
  float k_mola;
  float pos_equilibrio;
  float coef_atrito;

  public:
  Corpo(float massa, float velocidade, float posicao,
		  float k_mola, float pos_equilibrio, float coef_atrito);
  void update(float nova_velocidade, float nova_posicao);
  float get_massa();
  float get_velocidade();
  float get_posicao();
  float get_k_mola();
  float get_pos_equilibrio();
  float get_coef_atrito();
};

class ListaDeCorpos {
 private:
    std::vector<Corpo*> *corpos;

  public:
    ListaDeCorpos();
    void add_corpo(Corpo *c);
    std::vector<Corpo*> *get_corpos();
};

class Fisica {
  private:
    ListaDeCorpos *lista;

  public:
    Fisica(ListaDeCorpos *ldc);
    void add_corpo(Corpo *c);
    void update(float deltaT, float entrada);
};
#endif
