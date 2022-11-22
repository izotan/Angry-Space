#include "Personagem.h"



Personagem::Personagem()
{
}


Personagem::~Personagem()
{
}

void Personagem::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("personagem"))
		gRecursos.carregarSpriteSheet("personagem", "assets/Artes/Personagem/Personagem.png", 3, 2);

	sprite.setSpriteSheet("personagem");


	if (!gRecursos.carregouAudio("somMorte"))
		gRecursos.carregarAudio("somMorte", "assets/Sons/Efeitos/Explosao.mp3");

	resetar();

}

void Personagem::atualizar()
{
	direcao = parado;
	
	if (y > 500 - sprite.getAltura() / 2)
	{
		y = 500 - sprite.getAltura() / 2;
		aceleracao = 0;
	}
	if (y < sprite.getAltura() / 2)
	{
		y = sprite.getAltura() / 2;
		aceleracao = 0;
	}
	if (gTeclado.segurando[TECLA_ESPACO]) // subir
	{
		if (y > sprite.getAltura() / 2 )
		{
			aceleracao -= 0.12;
			y += aceleracao;
			direcao = cima;
		}
		else
			direcao = cima;
	}
	else								 // descer
	{
		if (y < 500 - sprite.getAltura() / 2 )
		{
			aceleracao += 0.12;
			y += aceleracao;
			direcao = baixo;
		}
		else
		{
			y = 500 - sprite.getAltura() / 2;
			direcao = parado;
		}
	}

	if (direcao == parado)
	{
		sprite.setAnimacao(parado);
		sprite.avancarAnimacao();
	}
	else
	{
		sprite.setAnimacao(direcao);
		sprite.avancarAnimacao();
	}

}

void Personagem::desenhar()
{
	sprite.desenhar(x, y);
}

void Personagem::pegar(int pontos, int powerup)
{
	pontuacao += pontos;
	if (pontuacao < 0)
		pontuacao = 0;
	powerUps += powerup;
	if (powerUps < 0)
		powerUps = 0;
}

void Personagem::resetar()
{
	x = 50 + sprite.getLargura() / 2;
	y = 500 - sprite.getAltura() / 2;
	direcao = parado;
	pontuacao = 0;
	powerUps = 0;
	vidas = 1;
}

void Personagem::morrer()
{
	som.setAudio("somMorte");
	som.tocar();
}
