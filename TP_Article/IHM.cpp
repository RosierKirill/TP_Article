#include "IHM.h"
#include <iostream>
#include <iomanip>
using namespace std;

IHM::IHM()
{

}

IHM::~IHM()
{

}

void IHM::Start(Gestion * g) {

	this->gest = g;
	int choix;
	int numArticle;
	Article* art;
	string leNom;
	do
	{
		choix = AfficheMenu();
		
		switch (choix)
		{
		case 1:
			cout << "Le nom : ";
			cin >> leNom;
			art = gest->Ajouter(leNom);
			Modifier(art);
			break;
		case 2:
			numArticle = this->ChoixArticle();
			if (numArticle > 0)
			{
				art = gest->LireAt(numArticle - 1);
				Modifier(art);
			}
			break;
		case 3:
			numArticle = this->ChoixArticle();
			if (numArticle > 0)
			{
				gest->Supprimer(numArticle - 1);
			}
			break;
		case 4:
			AfficherTout();
			break;
		case 5:
			AfficherToutHStock();
			break;
		case 6:
			Commande();
			break;
		}
	} while (choix != 0);
}

int IHM::AfficheMenu()
{
	int choix;
	cout << "1 : Ajouter un Article" << endl;
	cout << "2 : Modifier un Article" << endl;
	cout << "3 : Supprimer un Article" << endl;
	cout << "4 : Afficher tous les  Articlee" << endl;
	cout << "5 : Afficher les Articles hors stock" << endl;
	cout << "6 : Faire une commande" << endl;
	cout << "0 : Quitter" << endl;
	cout << "Choix :";
	cin >> choix;
	return choix;
}

int IHM::ChoixArticle()
{
	int numArticle = -1;
	if (gest->getTaille() > 0)
	{
		cout << "Quel Article ? (1/" << gest->getTaille() << ") :";
		cin >> numArticle;
		if (!((numArticle >= 1) && (numArticle <= gest->getTaille())))
		{
			numArticle = -1;
		}
	}
	return numArticle;
}

void IHM::Modifier(Article* art)
{
	string n;
	cout << " Article : " << art->getNom() << endl;
	cout << " Prix HT : ";
	cin >> art->prixHT;
	cout << " Stock : ";
	cin >> art->stock;
}


void IHM::AfficherTout()
{
		
	for (int j = 0; j < gest->getTaille(); j++)
	{
		Article* art = gest->LireAt(j);
		cout << setw(15) << left << art->getNom() << setw(15) << left << art->prixHT << setw(15) << left << art->stock << endl;
		
	}
}

void IHM::AfficherToutHStock()
{
	for (int j = 0; j < gest->getTaille(); j++)
	{
		Article* art = gest->LireAt(j);
		if (art->stock ==0)
		{
			cout << setw(15) << left << art->getNom() << setw(15) << left << art->prixHT << setw(15) << left << art->stock << endl;
		}
	}
}

void IHM::Commande()
{

	int numArticle;
	int nombreDeduis;
	Article* art;
	int sortie = 1;
	vector<Article*>* tabArt = new vector<Article*>();
	AfficherTout();
	cout << "Commande : " << endl;
	while (sortie != 0) {
		numArticle = this->ChoixArticle();
		art = new Article(gest->LireAt(numArticle-1)->getNom());
		if (numArticle > 0)
		{
			art = gest->LireAt(numArticle -1);
		}
		cout << "Combien vous en voulez ? (il y en a " << art->stock << " en stock)";
		cin >> nombreDeduis;
		cout << "0 pour arreter";
		cin >> sortie;
		tabArt->push_back(gest->Commande(nombreDeduis, numArticle - 1));

	}

	double total = NULL;
	cout << "Ticket : " << endl;
	// On affiche tous les objets cr�es
	for (int j = 0; j < tabArt->size(); j++)
	{
		Article* art = tabArt->at(j);
		cout << j + 1 << ": " << art->getNom() << " " << art->prixHT << "e    " << art->stock
			<< endl;
		total = total + (art->prixHT * art->stock);
	}
	cout << "prix total: " << total << endl;
}
