#include "Gestion.h"
#include <fstream>
#include <vector>
using namespace std;

void Gestion::lireFichier()
{
	ifstream entree = ifstream();
	entree.open("article.txt");
	string n;
	if (!entree.fail())
	{
		Article* art;
		do
		{
			entree >> n;
			
			art = new Article(n);
			if (entree.eof())
			{
				delete art;
				break;
			}
			entree >> art->prixHT;
			entree >> art->stock;
			listeArticle->push_back(art);
		} while (!entree.eof());
		entree.close();
	}
}

void Gestion::sauverFichier()
{
	ofstream sortie = ofstream();
	sortie.open("article.txt");
	for (int i = 0; i < listeArticle->size(); i++)
	{
		Article* art = listeArticle->at(i);
		sortie << art->getNom() << " " << art->prixHT << " " << art->stock << endl;
	}
	sortie.close();
}

Gestion::Gestion() // Constructeur
{
	listeArticle = new vector<Article*>();
	lireFichier();
}

Gestion::~Gestion() // Destructeur
{
	sauverFichier();
	// On libère tous les objets crées
	while (listeArticle->size() > 0)
	{
		Article* etud = listeArticle->at(listeArticle->size() - 1);
		//
		delete etud;
		listeArticle->pop_back();
	}

	// On libere la mémoire du Vector
	delete listeArticle;
}

int Gestion::getTaille()
{
	return (int)listeArticle->size();
}

Article* Gestion::Ajouter(string n)
{
	Article* temp = new Article(n);
	listeArticle->push_back(temp);
	return temp;
}

Article* Gestion::LireAt(int pos)
{
	Article* temp = NULL;
	if ((pos >= 0) && (pos < getTaille()))
	{
		temp = listeArticle->at(pos);
	}
	return temp;
}

bool Gestion::Supprimer(int pos)
{
	bool ok = false;
	if ((pos >= 0) && (pos < getTaille()))
	{
		Article* art = listeArticle->at(listeArticle->size() - 1);
		delete art;
		listeArticle->pop_back();
		ok = true;
	}
	return ok;
}

Article* Gestion::Commande(int deduis, int numArticle)
{
	Article* art;
	int stockrestant = 0;



	stockrestant = listeArticle->at(numArticle)->stock - deduis;

	listeArticle->at(numArticle)->stock = stockrestant;

	art = new Article(listeArticle->at(numArticle)->getNom());
	art->prixHT = listeArticle->at(numArticle)->prixHT;
	art->stock = deduis;

	return art;
}

