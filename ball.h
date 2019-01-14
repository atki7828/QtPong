#ifndef BALL_H
#define BALL_H
#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>
#include "constants.h"
#include <math.h>


class Ball : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    Ball();
    float xComponent, yComponent;
    float speed;
    float angle;
    float setAngle();
public slots:
    void move();
};

#endif // BALL_H
