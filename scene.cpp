#include "scene.h"
#include <QLabel>
#include <math.h>
#include <QPen>
#include <QTimer>

bool stop = true;
bool pause = true;
extern QLabel *menu;
QLabel *win;

Scene::Scene()
{
    setSceneRect(0,0,scnWidth,scnHeight);

    setBackgroundBrush(QColor(0,127,0));

    win = new QLabel;
    win->setGeometry(scnWidth/2-scnWidth*0.1,scnHeight/3-scnHeight*0.1,scnWidth*0.2,scnHeight*0.2);
    win->setStyleSheet("background:#aa888888;color:#000000;");
    win->setAlignment(Qt::AlignCenter);
    win->raise();
    addWidget(win);
    win->hide();

    QPen pen = QPen(QColor(255,255,255),5,Qt::DashLine);
    QGraphicsLineItem *centerLine = new QGraphicsLineItem();
    centerLine->setLine(scnWidth/2,margin,scnWidth/2,scnHeight- margin);
    centerLine->setPen(pen);
    centerLine->setZValue(-1);
    addItem(centerLine);
    QGraphicsRectItem *bounds = new QGraphicsRectItem();
    bounds->setRect(margin,margin,scnWidth-2*margin,scnHeight-2*margin);
    bounds->setPen(pen);
    bounds->setZValue(-1);
    addItem(bounds);
}

void Scene::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_Up)
        p1->dir = 1;
    else if(e->key() == Qt::Key_Down)
        p1->dir = -1;

    else if(e->key() == Qt::Key_Space) {
        if(win->isVisible())
            win->hide();
        if(menu->isVisible() && stop) {
            menu->hide();
            stop = false;
        }
        else {
            if(stop)
                stop = false;
            else if(pause) {
                pause = false;
                menu->hide();
            }
            else {
                pause = true;
                menu->show();
            }
        }
    }

}
void Scene::keyReleaseEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_Up || e->key() == Qt::Key_Down)
        p1->dir = 0;
}

Scene::~Scene() {}
