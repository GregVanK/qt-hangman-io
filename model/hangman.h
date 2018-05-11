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
    QString getHidden();
    void hidePhrase();
private:
    std::vector<QString> phrases;
    std::vector<QChar> letteresPressed;
    QString phrase;
    QString hidden;
};

#endif // HANGMAN_H
