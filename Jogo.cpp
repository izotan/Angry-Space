#include "Jogo.h"
#include <ctime>
#include <fstream>

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false, "Angry Space");

	gJanela.setIcone("assets/Artes/Icone/Icone.png");

	srand(time(0));

	if (!gRecursos.carregouAudio("somBotao"))
		gRecursos.carregarAudio("somBotao", "assets/Sons/Efeitos/Botao.wav");

	som.setAudio("somBotao");

	if (!gRecursos.carregouAudio("somPoder"))
		gRecursos.carregarAudio("somPoder", "assets/Sons/Efeitos/Cronometro.wav");

	if (!gRecursos.carregouSpriteSheet("tMenu"))
		gRecursos.carregarSpriteSheet("tMenu", "assets/Artes/Telas/Menu.png");

	if (!gRecursos.carregouSpriteSheet("tCreditos"))
		gRecursos.carregarSpriteSheet("tCreditos", "assets/Artes/Telas/Creditos.png");

	if (!gRecursos.carregouSpriteSheet("tTutorial"))
		gRecursos.carregarSpriteSheet("tTutorial", "assets/Artes/Telas/Tutorial.png");

	if (!gRecursos.carregouSpriteSheet("tGameover"))
		gRecursos.carregarSpriteSheet("tGameover", "assets/Artes/Telas/Gameover.png");

	if (!gRecursos.carregouSpriteSheet("tRecordes"))
		gRecursos.carregarSpriteSheet("tRecordes", "assets/Artes/Telas/Recordes.png");

	
	if (!gRecursos.carregouSpriteSheet("bMenu"))
		gRecursos.carregarSpriteSheet("bMenu", "assets/Artes/Botoes/Menu.png", 3, 1);
	botoes[bMenu].setSpriteSheet("bMenu");

	if (!gRecursos.carregouSpriteSheet("bComecar"))
		gRecursos.carregarSpriteSheet("bComecar", "assets/Artes/Botoes/Comecar.png", 3, 1);
	botoes[bComecar].setSpriteSheet("bComecar");

	if (!gRecursos.carregouSpriteSheet("bSair"))
		gRecursos.carregarSpriteSheet("bSair", "assets/Artes/Botoes/Sair.png", 3, 1);
	botoes[bSair].setSpriteSheet("bSair");

	if (!gRecursos.carregouSpriteSheet("bRecomecar"))
		gRecursos.carregarSpriteSheet("bRecomecar", "assets/Artes/Botoes/Recomecar.png", 3, 1);
	botoes[bRecomecar].setSpriteSheet("bRecomecar");

	if (!gRecursos.carregouSpriteSheet("bCreditos"))
		gRecursos.carregarSpriteSheet("bCreditos", "assets/Artes/Botoes/Creditos.png", 3, 1);
	botoes[bCreditos].setSpriteSheet("bCreditos");

	if (!gRecursos.carregouSpriteSheet("bAjuda"))
		gRecursos.carregarSpriteSheet("bAjuda", "assets/Artes/Botoes/Ajuda.png", 3, 1);
	botoes[bAjuda].setSpriteSheet("bAjuda");

	if (!gRecursos.carregouSpriteSheet("bVoltar"))
		gRecursos.carregarSpriteSheet("bVoltar", "assets/Artes/Botoes/Voltar.png", 3, 1);
	botoes[bVoltar].setSpriteSheet("bVoltar");

	if (!gRecursos.carregouSpriteSheet("bRecordes"))
		gRecursos.carregarSpriteSheet("bRecordes", "assets/Artes/Botoes/Recordes.png", 3, 1);
	botoes[bRecordes].setSpriteSheet("bRecordes");

	if (!gRecursos.carregouSpriteSheet("chao"))
		gRecursos.carregarSpriteSheet("chao", "assets/Artes/Chao/Chao.png");
	chao.setSpriteSheet("chao");

	if (!gRecursos.carregouSpriteSheet("fundo"))
		gRecursos.carregarSpriteSheet("fundo", "assets/Artes/Fundo/Fundo.png");

	if (!gRecursos.carregouMusica("musica"))
		gRecursos.carregarMusica("musica", "assets/Sons/Musicas/Jogo.wav");

	if (!gRecursos.carregouMusica("musicaCreditos"))
		gRecursos.carregarMusica("musicaCreditos", "assets/Sons/Musicas/Creditos.wav");

	if (!gRecursos.carregouMusica("musicaTutorial"))
		gRecursos.carregarMusica("musicaTutorial", "assets/Sons/Musicas/Tutorial.wav");

	if (!gRecursos.carregouMusica("musicaAngrySpace"))
		gRecursos.carregarMusica("musicaAngrySpace", "assets/Sons/Musicas/AngrySpace.wav");

	if (!gRecursos.carregouMusica("musicaTutorial"))
		gRecursos.carregarMusica("musicaTutorial", "assets/Sons/Musicas/Tutorial.wav");

	if (!gRecursos.carregouMusica("musicaGameover"))
		gRecursos.carregarMusica("musicaGameover", "assets/Sons/Musicas/Gameover.wav");

	if (!gRecursos.carregouFonte("fonte"))
		gRecursos.carregarFonte("fonte", "assets/fontes/fonte_padrao.ttf", 30);

	if (!gRecursos.carregouFonte("fonteJogo"))
		gRecursos.carregarFonte("fonteJogo", "assets/fontes/fonte_padrao.ttf", 22);

	posicaoChao[0].x = gJanela.getLargura() / 2;
	posicaoChao[0].y = gJanela.getAltura() - chao.getAltura() / 2;
	posicaoChao[1].x = gJanela.getLargura() / 2 + gJanela.getLargura(); ;
	posicaoChao[1].y = gJanela.getAltura() - chao.getAltura() / 2;

	velocidadeCenario = 2;


	telaAtual = tMenu;
	for (int m = 0; m < 3; m++)
	moeda[m].inicializar(tMoeda, velocidadeCenario);

	meteoro.inicializar(tMeteoro, velocidadeCenario);
	cronometro.inicializar(tCronometro, velocidadeCenario);

	tPontuacao.setAncora(0, 0.5);
	tPontuacao.setFonte("fonte");
	tPontuacao2.setAncora(0, 0.5);
	tPontuacao2.setFonte("fonteJogo");
	tPowerUp.setAncora(0, 0.5);
	tPowerUp.setFonte("fonteJogo");

	personagem.inicializar();
	gMusica.tocar("musicaAngrySpace", true);
 }

void Jogo::finalizar()
{
	//	O resto da finalização vem aqui (provavelmente, em ordem inversa a inicialização)!
	//	...
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::testarColisoes()
{
	if (uniTestarColisao(personagem.getSprite(),
		personagem.getX(),
		personagem.getY(),
		0,
		meteoro.getSprite(),
		meteoro.getX(),
		meteoro.getY(),
		0))
	{
		personagem.getDano();
	}
	for (int m = 0; m < 3; m++)
	{
		if (uniTestarColisao(personagem.getSprite(),
			personagem.getX(),
			personagem.getY(),
			0,
			moeda[m].getSprite(),
			moeda[m].getX(),
			moeda[m].getY(),
			0))
		{
			personagem.pegar(moeda[m].pegar(), 0);
		}
	}
	for (int m = 0; m < 3; m++)
	{
		if (uniTestarColisao(moeda[m].getSprite(), moeda[m].getX(), moeda[m].getY(), 0, meteoro.getSprite(), meteoro.getX(), meteoro.getY(), 0))
		{
			moeda[m].resetar();
		}
	}
	for (int m = 0; m < 3; m++)
	{
		if (uniTestarColisao(moeda[m].getSprite(), moeda[m].getX(), moeda[m].getY(), 0, cronometro.getSprite(), cronometro.getX(), cronometro.getY(), 0))
		{
			cronometro.resetar();
		}
	}
	for (int m = 0; m < 3; m++)
	{
		if (uniTestarColisao(moeda[m].getSprite(), moeda[m].getX(), moeda[m].getY(), 0, moeda[m+1].getSprite(), moeda[m+1].getX(), moeda[m+1].getY(), 0))
		{
			moeda[m].resetar();
		}
	}

	if (uniTestarColisao(personagem.getSprite(), personagem.getX(), personagem.getY(), 0, cronometro.getSprite(), cronometro.getX(), cronometro.getY(), 0))
	{
		personagem.pegar(0, cronometro.pegar());
	}
}

void Jogo::resetar()
{
	for (int m = 0; m < 3; m++)
		moeda[m].resetar();
	meteoro.resetar();
	cronometro.resetar();
	personagem.resetar();
	velocidadeCenario = 2;
}

void Jogo::executar()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair && telaAtual != tSair)
	{
		uniIniciarFrame();

		switch (telaAtual)
		{
		case tMenu: telaMenu();
			break;
		case tGameover: telaGameover();
			break;
		case tCreditos: telaCreditos();
			break;
		case tTutorial: telaTutorial();
			break;
		case tJogo: telaJogo();
			break;
		case tRecordes: telaRecordes();
		}
		

		uniTerminarFrame();
	}
}

void Jogo::telaGameover()
{
	telas.setSpriteSheet("tGameover");
	telas.desenhar(400, 300);

	tPontuacao.setString(to_string(personagem.getPontuacao()));
	tPontuacao.desenhar(385, 265);

	botoes[bRecomecar].setPos(200, 360);
	botoes[bMenu].setPos(200, 455);
	botoes[bSair].setPos(200, 540);

	botoes[bMenu].desenhar();
	botoes[bMenu].atualizar();

	botoes[bRecomecar].desenhar();
	botoes[bRecomecar].atualizar();

	botoes[bSair].desenhar();
	botoes[bSair].atualizar();



	if (botoes[bSair].estaClicado() && telaAtual == tGameover)
	{
		som.tocar();
		telaAtual = tSair;
	}
	if (botoes[bRecomecar].estaClicado() && telaAtual == tGameover)
	{
		gMusica.parar();
		gMusica.tocar("musica", true);
		som.tocar();
		telaAtual = tJogo;
		resetar();
	}
	if (botoes[bMenu].estaClicado() && telaAtual == tGameover)
	{
		gMusica.parar();
		gMusica.tocar("musicaAngrySpace", true);
		som.tocar();
		telaAtual = tMenu;
	}
}

void Jogo::telaMenu()
{
	telas.setSpriteSheet("tMenu");
	telas.desenhar(400, 300);
	botoes[bComecar].setPos(200, 360);
	botoes[bAjuda].setPos(200, 420);
	botoes[bCreditos].setPos(200, 480);
	botoes[bSair].setPos(200, 540);

	botoes[bComecar].desenhar();
	botoes[bComecar].atualizar();
	if (botoes[bComecar].estaClicado())
	{
		gMusica.parar();
		gMusica.tocar("musica", true);
		som.tocar();
		telaAtual = tJogo;
		resetar();
	}

	botoes[bAjuda].desenhar();
	botoes[bAjuda].atualizar();
	if (botoes[bAjuda].estaClicado())
	{
		gMusica.parar();
		gMusica.tocar("musicaTutorial", true);
		som.tocar();
		telaAtual = tTutorial;
	}

	botoes[bCreditos].desenhar();
	botoes[bCreditos].atualizar();
	if (botoes[bCreditos].estaClicado())
	{
		gMusica.parar();
		gMusica.tocar("musicaCreditos", true);
		som.tocar();
		telaAtual = tCreditos;
	}

	botoes[bSair].desenhar();
	botoes[bSair].atualizar();
	if (botoes[bSair].estaClicado())
	{
		telaAtual = tSair;
	}
}

void Jogo::telaJogo()
{
	if (personagem.getVidas())
	{
		fundo.setSpriteSheet("fundo");
		fundo.desenhar(400, 300); //céu
		testarColisoes();

		chao.desenhar(posicaoChao[0].x, posicaoChao[0].y);
		chao.desenhar(posicaoChao[1].x, posicaoChao[1].y);

		posicaoChao[0].x -= velocidadeCenario;
		if (posicaoChao[0].x < -gJanela.getLargura() / 2)
			posicaoChao[0].x = gJanela.getLargura() / 2 + gJanela.getLargura();
		posicaoChao[1].x -= velocidadeCenario;
		if (posicaoChao[1].x < -gJanela.getLargura() / 2)
			posicaoChao[1].x = gJanela.getLargura() / 2 + gJanela.getLargura();


		if (contador <= 180)
			contador++;
		else if (velocidadeCenario <= 10)
		{
			velocidadeCenario += aceleracao;
			contador = 0;

		}

		cronometro.atualizar(velocidadeCenario);
		for (int m = 0; m < 3; m++)
			moeda[m].atualizar(velocidadeCenario);


		cronometro.desenhar();
		for (int m = 0; m < 3; m++)
			moeda[m].desenhar();

		if (gTeclado.pressionou[TECLA_X] && personagem.getPowerUp() >= 1)
		{
			aceleracao = 0;
			som1.setAudio("somPoder");
			velocidadeCenario = 0.5;
			som1.tocar();
			personagem.usarPoder();
		}
		if (velocidadeCenario == 0.5)
		{
			if (contadorM < 300)
				contadorM++;
			else if (contadorM >= 300)
			{
				aceleracao = 0.1;
				velocidadeCenario = 3.5;
				contadorM = 0;
			}
		}
		meteoro.atualizar(velocidadeCenario);
		meteoro.desenhar();

		personagem.atualizar();
		personagem.desenhar();

		tPontuacao2.setString("Pontuação: " + to_string(personagem.getPontuacao()));
		tPontuacao2.desenhar(160, 30);
		tPowerUp.setString("PowerUps: " + to_string(personagem.getPowerUp()));
		tPowerUp.desenhar(420, 30);

	}
	else
		{
		gMusica.parar();
		personagem.morrer();

		int i = 0;
		do
		{
			if (personagem.getPontuacao() > recorde[i])
			{
				if (i < 9)
					recorde[i + 1] = recorde[i];
				recorde[i] = personagem.getPontuacao();

				ofstream arqS_recorde("Recordes.txt", ios::app);

				if (arqS_recorde.is_open())
				{
					arqS_recorde << i + 1 << ": " << recorde[i] << endl;
					arqS_recorde.close();
				}
				i = 10;
			}
			else
				i++;

		} while (i < 10);

			if (contadorV < 180)
				contadorV++;
			if (contadorV >= 180)
			{
				telaAtual = tGameover;
				gMusica.tocar("musicaGameover", true);
				contadorV = 0;
			}
		}
}

void Jogo::telaCreditos()
{
	telas.setSpriteSheet("tCreditos");
	telas.desenhar(400, 300);
	botoes[bVoltar].setPos(675, 560);
	botoes[bVoltar].desenhar();
	botoes[bVoltar].atualizar();
	if (botoes[bVoltar].estaClicado() && telaAtual == tCreditos)
	{
		gMusica.parar();
		gMusica.tocar("musicaAngrySpace", true);
		som.tocar();
		telaAtual = tMenu;
	}
}

void Jogo::telaTutorial()
{
	telas.setSpriteSheet("tTutorial");
	telas.desenhar(400, 300);
	botoes[bVoltar].setPos(675, 560);
	botoes[bVoltar].desenhar();
	botoes[bVoltar].atualizar();
	if (botoes[bVoltar].estaClicado() && telaAtual == tTutorial)
	{
		gMusica.parar();
		gMusica.tocar("musicaAngrySpace", true);
		som.tocar();
		telaAtual = tMenu;
	}
}

void Jogo::telaRecordes()
{
	string pontuacaoR = " ";

	ifstream arqE_recorde("Recordes.txt");

	if (!arqE_recorde.eof())
	{
		pontuacaoR += (char)arqE_recorde.get();
		tPontuacao.setString(pontuacaoR);
		tPontuacao.desenhar(160, 100);
		arqE_recorde.close();
	}

}
