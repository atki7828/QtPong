#ifndef SCORE_H
#define SCORE_H
#include "constants.h"
#include <QGraphicsRectItem>

class Score : public QGraphicsRectItem {
public:
    Score(int score, int player);
};

#endif // SCORE_H
