// Laboratorio 1
// Arthur Moraes do Lago (157702)
// Vitor Saldanha da Silveira (158508)

#ifndef OO_MODEL_HPP
#define OO_MODEL_HPP

#define GRAVITY 0

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
    void hard_copy(ListaDeCorpos *ldc);
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

struct ponto {
	int i;
	int j;
};
typedef struct ponto ponto;

class Tela {
  private:
    ListaDeCorpos *lista;
	std::vector<ponto> listaPontos;
    int maxI, maxJ;
    float maxX, maxY;

  public:
    Tela(ListaDeCorpos *ldc, float maxX, float maxY);
    ~Tela();
    void stop();
    void init();
    void update();
};



#endif
