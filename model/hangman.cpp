#include "hangman.h"

Hangman::Hangman()
{
    srand(time(NULL));
}

void Hangman::addPhrase(QString s)
{
    phrases.push_back(s);
}

QString Hangman::getRandPhrase()
{
    return phrases[qrand()%(phrases.size())];
}
