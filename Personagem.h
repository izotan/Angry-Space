#pragma once
#include "libUnicornio.h"

enum Direcao { parado, baixo, cima};

class Personagem
{
public:
	Personagem();
	~Personagem();

	void inicializar();
	void atualizar();
	void desenhar();

	Sprite getSprite() { return sprite; }
	float getX() { return x; }
	float getY() { return y; }
	int getPontuacao() { return pontuacao; }
	int getPowerUp() { return powerUps; }
	void pegar(int pontos, int powerup);
	void getDano() { vidas--; }
	void vidasMais() { vidas++; }
	int getVidas() { return vidas; }
	void resetar();
	void morrer();
	void usarPoder() { powerUps--; }


protected:
	Sprite sprite;
	Som som;
	float x, y, aceleracao = 0;
	Direcao direcao;
	int pontuacao, vidas, powerUps;
	bool viva;
};

