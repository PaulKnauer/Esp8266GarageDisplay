#ifndef BiColorMatrix_h
#define BiColorMatrix_h

#include "UserConfig.h"

#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

class BiColorMatrix {
  public:
    BiColorMatrix();
    void loop();
    void reset();
    void openAnimation();
    void closedAnimation();
    void closingAnimation();
    void moving(int distance);
  private:
    int counter = 0;
    boolean closeAnimationDone;
    boolean closingAnimationDone;
    boolean openAnimationDone;
    void animation(int led);
    Adafruit_BicolorMatrix *matrix;
};

#endif
