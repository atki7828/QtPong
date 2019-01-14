#include "ball.h"
#include <QLabel>
#include <vector>
#include "score.h"
#include "scene.h"
#include "paddle.h"

extern Paddle *p1;
extern Paddle *p2;
extern bool stop;
extern bool pause;
extern Scene *gameScene;
extern QLabel *win;

int myScore = 0;
int aiScore = 0;
std::vector<Score*> scores;

float pi = 3.14159;

Ball::Ball() {
    speed = 8;
    setRect(0, 0, ballSize, ballSize);
    setBrush(ballColor);
    setPos(scnWidth/2-ballSize/2,scnHeight/2-ballSize/2);
    angle = setAngle();
    xComponent = speed * cos(angle);
    yComponent = speed * sin(angle);

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(25);
}

void Ball::move() {
    if(!pause && !stop) {
        srand(time(0));
        setPos(x()+xComponent,y()+yComponent);

        // increase speed and reverse direction when hit paddle.
        // also, to avoid ball getting stuck inside paddle
        // (when it hits bottom edge)
        // upon collision, move ball x position away from paddle towards center.
        if(this->collidesWithItem(p1) || this->collidesWithItem(p2)) {
            xComponent = -xComponent;
            if(x() < scnWidth/2)
                setPos(margin+pWidth,y());
            else
                setPos(scnWidth-margin-pWidth-ballSize,y());
            xComponent *= 1.05;
            yComponent *= 1.03;

        }
        // bounce off walls:
        if(this->y() < margin || this->y() > scnHeight-this->rect().height() - margin) {
            yComponent = -yComponent;
        }


        // out of bounds.
        // someone gets a point,
        // put ball back to center, reset speed,
        // get new random start angle.
        if(x() < 0 || x() > scnWidth) {
            if(x() < scnWidth/2) {
                Score *score = new Score(aiScore++,2);
                this->scene()->addItem(score);
                scores.push_back(score);
            }
            else {
                Score *score = new Score(myScore++,1);
                this->scene()->addItem(score);
                scores.push_back(score);
            }
            angle = setAngle();
            xComponent = speed*cos(angle);
            yComponent = speed*sin(angle);
            stop = 1;
            setPos(scnWidth/2-ballSize/2,scnHeight/2-ballSize/2);
            if(aiScore == winScore || myScore == winScore) {
                for(std::vector<Score*>::iterator s = scores.begin(); s != scores.end(); s++) {
                    this->scene()->removeItem(*s);
                }
                scores.clear();
                if(aiScore == winScore)
                    win->setText("Game Over!<br>You lose");
                if(myScore == winScore)
                    win->setText("Game Over!<br>You win");
                win->show();
                aiScore = 0;
                myScore = 0;
            }
        }

        // tell AI paddle to move:
        if(xComponent < 0)
            p2->speed = p1->speed/3;
        else
            p2->speed = p1->speed;
        if(this->y()+this->rect().height()  < p2->y() + p2->rect().height()/3)
            p2->dir = 1;
        else if(this->y() > p2->y() + 2*p2->rect().height()/3)
            p2->dir = -1;
        else
            p2->dir = 0;
    }
}

// set angle of trajectory to a random value
// in a range between 3pi/8 and pi/8,
// in either the NE or SE direction.
float Ball::setAngle() {
    srand(time(0));
    float r = (float)rand()/RAND_MAX;
    float a = 3*pi/8 - r * pi/4;
    srand(time(0));
    rand() % 2 == 0 ? a = 2*pi - a : a = a;
    return a;
}
