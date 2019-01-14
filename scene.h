#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include "constants.h"
#include "paddle.h"

extern Paddle *p1;

class Scene : public QGraphicsScene
{
public:
    Scene();
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);

    ~Scene();
};

#endif // SCENE_H
