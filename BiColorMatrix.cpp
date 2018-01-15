#include "BiColorMatrix.h"

BiColorMatrix::BiColorMatrix() {
  matrix = new Adafruit_BicolorMatrix();
  matrix->begin(0x70);
  matrix->clear();
  matrix->writeDisplay();
  openAnimationDone = false;
  closingAnimationDone = true;
  closeAnimationDone = true;
}

void BiColorMatrix::openAnimation() {
  if (!openAnimationDone) {
    animation(LED_GREEN);
    openAnimationDone = true;
    closingAnimationDone = false;
    closeAnimationDone = false;
  }
}

void BiColorMatrix::closingAnimation() {
  if (!closingAnimationDone) {
    animation(LED_YELLOW);
    openAnimationDone = false;
    closingAnimationDone = true;
    closeAnimationDone = false;
  }
}

void BiColorMatrix::closedAnimation() {
  if (!closeAnimationDone) {
    animation(LED_RED);
    openAnimationDone = false;
    closingAnimationDone = false;
    closeAnimationDone = true;
  }
}

void BiColorMatrix::moving(int distance) {
  matrix->clear();
  int i = map(distance, DOOR_OPEN_DISTANCE, DOOR_CLOSED_DISTANCE, 0, 8);
  matrix->fillRect(0, 0, i, 8, LED_RED);
  matrix->writeDisplay();
}

void BiColorMatrix::animation(int led) {
  for (int i = 0 ; i < 3 ; i++) {
    matrix->fillRect(0, 0, 8, 8, led);
    matrix->writeDisplay();
    delay(1000);
    matrix->clear();
    matrix->writeDisplay();
    delay(1000);
  }
}

