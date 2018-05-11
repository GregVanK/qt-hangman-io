#ifndef HANGMAN_H
#define HANGMAN_H
#include <vector>
#include <QString>
#include <cstdlib>
#include <time.h>

class Hangman
{
public:
    Hangman();
    void addPhrase(QString s);
    QString getRandPhrase(); // {phrases[return qrand()%(phrases.size())];}
private:
    std::vector<QString> phrases;
};

#endif // HANGMAN_H
