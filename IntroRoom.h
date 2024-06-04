#ifndef INTROROOM_H
#define INTROROOM_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <vector>

class IntroRoom : public QWidget {
    Q_OBJECT

public:
    explicit IntroRoom(QWidget *parent = nullptr);

    signals:
        void startButtonClicked();

private:
    QLabel *roomLabel;
    QLabel *descriptionLabel;
    QPushButton *startButton;
};

#endif // INTROROOM_H
