#include "mainview.h"
#include "ui_mainview.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QFile>

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
    loadPhrases();
    //layouts
    auto vlmain = new QVBoxLayout(ui->centralWidget);
    auto hlmain = new QHBoxLayout();
    vlmain->addLayout(hlmain);

    //buttons
    auto newPhraseBtn =  new QPushButton();
    newPhraseBtn->setText("New Phrase");
    hlmain->addWidget(newPhraseBtn);
    //broken at this point
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

void MainView::onClick()
{
    displayPhrase->setText(phrases[qrand()%(phrases.size()+1)]);
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
