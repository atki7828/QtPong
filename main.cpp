#include <QApplication>
#include "constants.h"
#include <QDebug>
#include "scene.h"
#include "paddle.h"
#include "ball.h"
#include <QLabel>
#include <QGraphicsRectItem>
#include <QGraphicsView>

Paddle *p1;
Paddle *p2;
Ball *ball;
Scene *gameScene;
QLabel *menu;

int main(int argc, char **argv) {
    //this makes the app itself
    QApplication a(argc, argv);

    //create Scene (window)
    gameScene = new Scene();

    //create paddles
    p1 = new Paddle(1);
    p2 = new Paddle(2);

    //add ball
    ball = new Ball();

    //create help/pause menus
    menu = new QLabel();
    menu->setText("<b><font size = 48>Pong</font>"
                     "<p>Up/Down arrows:   control left paddle."
                     "<br>SPACE:            begin/pause.</p>"
                     "<p>the ball's speed will increase every time"
                     "<br>it hits a paddle."
                     "<br>Score is kept in top left and right corners."
                     "<br>First to 7 points wins."
                     "<p>Press Space to begin</b>");
    menu->setStyleSheet("background:#aa888888;color:#000000;");
    menu->setGeometry(scnWidth/2-menuWidth/2,scnHeight/2-menuHeight/2,menuWidth,menuHeight);
    menu->setAlignment(Qt::AlignCenter);
    //add items to gameScene
    gameScene->addItem(p1);
    gameScene->addItem(p2);
    gameScene->addItem(ball);
    gameScene->addWidget(menu);

    //add view
    QGraphicsView *view = new QGraphicsView();
    //help menu
    QLabel *help = new QLabel("Press SPACE to begin/pause",view);
    help->setStyleSheet("background:#22000000;color:#cccccc;");
    help->setGeometry(scnWidth/2-210/2,scnHeight-21,210,20);
    help->show();
    view->setScene(gameScene);
    view->show();

    return a.exec();
}
