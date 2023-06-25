#pragma once
#include <Arduino.h>

class RTPinBoard {
public:
 RTPinBoard(byte pin = 0, byte range = 10, int sw1 = 0, int sw2 = 145, int sw3 = 306, int sw4 = 494, int sw5 = 786);
 boolean getSW1();
 boolean getSW2();
 boolean getSW3();
 boolean getSW4();
 boolean getSW5();
 int readPin();
 
 void update();
 
 void setSW1(int val);
 void setSW2(int val);
 void setSW3(int val);
 void setSW4(int val);
 void setSW5(int val);
 void setRange(byte val);
 void setPin(byte val);
private:
 byte _pin = 0;
 int _sw1 = 0;
 int _sw2 = 0;
 int _sw3 = 0;
 int _sw4 = 0;
 int _sw5 = 0;
 byte _range = 10;
 byte NumClicked = 0;
};
