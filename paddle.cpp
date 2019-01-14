#include "paddle.h"
#include "scene.h"

extern bool stop;
extern bool pause;

Paddle::Paddle(int player) {
    dir = 0;
    speed = 8;
    setRect(0, 0, pWidth, pHeight);
    if(player == 1) {
        setPos(margin,scnHeight/2-pHeight/2);
        setBrush(leftColor);
    }

    else if(player == 2) {
        setPos(scnWidth-margin-pWidth,scnHeight/3-pHeight/2);
        setBrush(rightColor);
    }


    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(25);
}

void Paddle::move() {
    if(!pause) {
        if(this->dir > 0 && this->y() > margin) {
            setPos(x(),y()-speed);
        }
        else if(this->dir < 0 && this->y()+this->rect().height() < scnHeight-margin) {
            setPos(x(),y()+speed);
        }
    }
}
