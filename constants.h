#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <QColor>

static const int scnWidth = 768;
static const float aspectRatio = (16.0/10.0);
static const int scnHeight = scnWidth/aspectRatio;

static const int winScore = 7;
static const int ballSize = scnWidth * 0.05;
static const QColor ballColor = QColor(255,0,0);

static const int pWidth = scnWidth * 0.02;
static const int pHeight = scnHeight * 0.2;
static const int margin = scnWidth * 0.025;
static const QColor leftColor = QColor(255,0,255);
static const QColor rightColor = QColor(0,255,255);

static const int menuWidth = scnWidth * 0.7;
static const int menuHeight = scnHeight * 0.7;

static const int scoreSize = 20;
#endif // CONSTANTS_H
