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
			
			entree >> art->getNom();
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
	sortie.open("etudiant.txt");

}