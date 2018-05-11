#include "controller/mainview.h"
#include "ui_mainview.h"
#include "view/gamebutton.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QFile>
#include <iostream>

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
    loadPhrases();

    //layouts
    auto vlmain = new QVBoxLayout(ui->centralWidget);
    auto hlmain = new QHBoxLayout();
    auto* grid = new QGridLayout();
    vlmain->addLayout(grid);
    vlmain->addLayout(hlmain);

    alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int i = 0; i < 26; i++){
            QPushButton* btn = new GameButton(i);
            btn->setText(QString(alphabet[i]));
            grid->addWidget(btn, i/12, i%12);//connect a button to a section of the grid
            connect(btn,
                    &QPushButton::clicked,
                    this,
                    &MainView::letterPressed);
            buttons.push_back(btn);//adds button to vector
        }
    //newPhrase
    auto newPhraseBtn =  new QPushButton();
    newPhraseBtn->setText("New Phrase");
    hlmain->addWidget(newPhraseBtn);
    connect (newPhraseBtn,
             &QPushButton::clicked,
             this,
             &MainView::onClick);
    hlmain->addWidget(newPhraseBtn);
    displayPhrase = new QLabel();
    vlmain->addWidget(displayPhrase);
    displayPhrase->setText("DisplayPhrase");
}

MainView::~MainView()
{
    delete ui;
}

void MainView::letterPressed(){
    auto* btn = dynamic_cast<GameButton*>(sender()); // get button
    QChar letter = btn->getValue();
    displayPhrase->setText(QString(letter));
}

void MainView::onClick()
{
    displayPhrase->setText(phrases[qrand()%(phrases.size())]); //
}

void MainView::loadPhrases()
{
    QFile iFile(":/new/text/text/phrases.txt");
    if(!iFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qWarning() << "Error opening file\n";
        exit(EXIT_FAILURE);
    }
    QTextStream in(&iFile);
    QString line = in.readLine();
    while(!in.atEnd())
    {
        phrases.push_back(line);
        line = in.readLine();
    }
    iFile.close();
}
