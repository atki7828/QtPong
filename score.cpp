#include "score.h"
#include <QGraphicsScene>

Score::Score(int score, int player)
{
    setRect(0,0,scoreSize,scoreSize);

    if(player == 1) {
        setBrush(leftColor);
        setPos(margin*2+pWidth+score*rect().width()+score*margin/2,margin);
    }
    else if(player == 2) {
        setBrush(rightColor);
        setPos(scnWidth-(margin*2+pWidth+score*rect().width()+score*margin/2)-scoreSize,margin);
    }
}
