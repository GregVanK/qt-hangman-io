#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <vector>
#include <QString>
#include <QPushButton>

class QLabel;
namespace Ui {
class MainView;
}

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();
private slots:
    void onClick();
    void letterPressed();
private:
    void loadPhrases();
private:
    Ui::MainView *ui;
    QLabel* displayPhrase;
    std::vector<QString> phrases;
    std::vector<QPushButton*> buttons;
    std::vector<QChar> alphabet;
};

#endif // MAINVIEW_H
