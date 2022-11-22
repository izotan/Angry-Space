#pragma once
#include "libUnicornio.h"

enum TipoObjeto { tMoeda, tMeteoro, tCronometro };
class Objeto
{
public:
	Objeto();
	~Objeto();
	void inicializar(TipoObjeto t, float vFase);
	void atualizar(float vFase);
	void desenhar();

	void setVelocidadeFase(float v) { velocidadeFase = v; }
	Sprite getSprite() { return sprite; }
	float getX() { return x; }
	float getY() { return y; }
	bool getViva() { return viva; }
	int pegar();
	void resetar();
	float Largura() { return sprite.getLargura(); }

protected:
	TipoObjeto tipo;
	Sprite sprite;
	float x, y, velocidade, velocidadeFase;
	Som som;
	int valor, altura, largura, rot, contador = 0;
	bool viva;
	int contadorC;
};
