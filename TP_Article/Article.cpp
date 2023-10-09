#include "Article.h"

Article::Article(string n) 
{
	this->nom = n;
}

string Article::getNom()
{
	return this->nom;
}