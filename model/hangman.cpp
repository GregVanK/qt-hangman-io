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

QString Hangman::getHidden()
{
    return hidden;
}

void Hangman::hidePhrase()
{
        for(int j = 0; j < phrase.length(); j++)
        {
            if(phrase.at(j) == " ")
            {
                hidden+= " ";
            }
            else //
            {
                bool found = false;
                for(int i = 0; i < letteresPressed.size(); i++)
                {
                    if(phrase.at(j) == letteresPressed[i])
                    {
                        hidden+=phrase.at(j);
                        found =  true;
                    }
                }
                if(!found)
                {
                        hidden+="_";
                }
            }


        }

}
