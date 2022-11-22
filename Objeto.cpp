#include "Objeto.h"
#include <ctime>


Objeto::Objeto()
{
}


Objeto::~Objeto()
{
	exit(0);
}

void Objeto::inicializar(TipoObjeto t, float vFase)
{
	velocidadeFase = vFase;
	tipo = t;
	srand(time(0));

	if (!gRecursos.carregouSpriteSheet("Moeda"))
		gRecursos.carregarSpriteSheet("Moeda", "assets/Artes/Moeda/Moeda.png", 1, 1);

	if (!gRecursos.carregouSpriteSheet("MoedaAzul"))
		gRecursos.carregarSpriteSheet("MoedaAzul", "assets/Artes/Moeda/MoedaAzul.png", 1, 1);

	if (!gRecursos.carregouSpriteSheet("MoedaVermelho"))
		gRecursos.carregarSpriteSheet("MoedaVermelho", "assets/Artes/Moeda/MoedaVermelha.png", 1, 1);

	if (!gRecursos.carregouAudio("somMoeda"))
		gRecursos.carregarAudio("somMoeda", "assets/Sons/Efeitos/Moeda.wav");

	if (!gRecursos.carregouAudio("somBotao"))
		gRecursos.carregarAudio("somBotao", "assets/Sons/Efeitos/Botao.wav");

	if (!gRecursos.carregouSpriteSheet("meteoro"))
		gRecursos.carregarSpriteSheet("meteoro", "assets/Artes/Asteroide/Asteroide.png");

	if (!gRecursos.carregouSpriteSheet("cronometro"))
		gRecursos.carregarSpriteSheet("cronometro", "assets/Artes/PowerUp/Cronometro.png", 1, 3);

	resetar();
}

void Objeto::atualizar(float vFase)
{
	if (velocidadeFase != vFase)
		velocidadeFase = vFase;

	/*rot += -3;
	rot = rot % 360;*/
	if (tipo == tMeteoro)
		x -= velocidade + velocidadeFase + 0.5;

	x -= velocidade + velocidadeFase;
	//sprite.avancarAnimacao();

		if (x < -sprite.getLargura() / 2)
		{
			resetar();
		}

	sprite.avancarAnimacao();
}

void Objeto::desenhar()
{
	/*if (tipo == tMeteoro)
	{
		sprite.desenhar(x, y, rot);
	}
	else*/
	if(viva)
		sprite.desenhar(x, y);
	
}

int Objeto::pegar()
{
	if (viva)
	{
		if (tipo == tMoeda)
		{
			som.setAudio("somMoeda");
			som.tocar();
			viva = false;
			return valor;
		}
		if (tipo == tCronometro)
		{
			som.setAudio("somBotao");
			som.tocar();
			viva = false;
			return valor;
		}
		return 0;
	}

	return 0;
}

void Objeto::resetar()
{

	switch (tipo)
	{
	case tMoeda:
		if (rand() % 100 <= 59)
		{
			sprite.setSpriteSheet("Moeda");
			viva = true;
			valor = 1;
		}
		else if (rand() % 100 <= 60 && rand() % 100 <= 89)
		{
			sprite.setSpriteSheet("MoedaAzul");
			viva = true;
			valor = 10;
		}
		else
		{
			sprite.setSpriteSheet("MoedaVermelho");
			viva = true;
			valor = 100;
		}
		velocidade = 0;

		break;

	case tMeteoro:
		sprite.setSpriteSheet("meteoro");
		velocidade = 0;
		break;

	case tCronometro:
		sprite.setSpriteSheet("cronometro");
		velocidade = 0;
		viva = true;
		valor = 1;
		break;
	}

	switch (tipo)
	{
	case tMoeda:
		if (rand() % 100 <= 59)
		{
			sprite.setSpriteSheet("Moeda");
			x = gJanela.getLargura() + sprite.getLargura() / 2;
			y = rand() % ((gJanela.getAltura() - 120) + sprite.getAltura() / 2);
			valor = 1;
		}
		else if (rand() % 100 <= 60 && rand() % 100 <= 89)
		{
			sprite.setSpriteSheet("MoedaAzul");
			x = gJanela.getLargura() + sprite.getLargura() / 2;
			y = rand() % ((gJanela.getAltura() - 120) + sprite.getAltura() / 2);
			valor = 10;
		}
		else
		{
			sprite.setSpriteSheet("MoedaVermelho");
			x = gJanela.getLargura() + sprite.getLargura() / 2;
			y = rand() % ((gJanela.getAltura() - 120) + sprite.getAltura() / 2);
			valor = -30;
		}
		break;

	case tMeteoro:
		sprite.setSpriteSheet("meteoro");
		x = gJanela.getLargura() + sprite.getLargura() / 2;
		y = rand() % ((gJanela.getAltura() - 120) - sprite.getAltura() / 2);

		break;

	case tCronometro:
		sprite.setSpriteSheet("cronometro");
		x = gJanela.getLargura() + sprite.getLargura() / 2 + 900;
		y = rand() % ((gJanela.getAltura() - 120) + sprite.getAltura() / 2);

		break;
	}
}

