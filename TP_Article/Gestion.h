#pragma once
#include "Article.h"
#include <vector>

using namespace std;

class Gestion
{
	vector<Article*>* listeArticle;
	vector<Article*>* ticket;
	void lireFichier();
	void sauverFichier();


public:
	Gestion();
	~Gestion();

	int getTaille();

	Article* Ajouter(string n);
	Article* LireAt(int pos);
	bool Supprimer(int pos);
	Article* Commande(int deduis, int numArticle);
};

