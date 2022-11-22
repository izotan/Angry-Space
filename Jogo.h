#pragma once
#include "libUnicornio.h"
#include "Personagem.h"
//#include "Moeda.h"
#include "Objeto.h"

enum Telas {tMenu, tGameover, tCreditos, tTutorial, tJogo, tRecordes, tSair};
enum Botoes {bComecar, bRecomecar, bCreditos, bAjuda, bMenu, bRecordes, bSair, bVoltar};

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void testarColisoes();
	void resetar();
	void executar();

protected:
	Personagem personagem;
	Telas telaAtual;
	BotaoSprite botoes[8];
	Som som,som1;
	Sprite fundo, chao, telas;
	float velocidadeCenario, aceleracao = 0.1;
	void telaGameover();
	void telaMenu();
	void telaJogo();
	void telaCreditos();
	void telaTutorial();
	void telaRecordes();
	int contador = 0, contadorM = 0, contadorC = 0, contadorV = 0, lista[600][800], recorde[10] = { 0 };
	Vetor2D posicaoChao[2];
	//Moeda moedas[3];
	Texto tPontuacao, tPontuacao2, tPowerUp;
	Objeto moeda[4], cronometro, meteoro;
	//Powerup powerup;
};

