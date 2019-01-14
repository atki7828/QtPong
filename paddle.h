#ifndef PADDLE_H
#define PADDLE_H

#include "constants.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

class Paddle : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    int dir;
    int speed;
    Paddle(int player);
public slots:
    void move();
};

#endif // PADDLE_H
