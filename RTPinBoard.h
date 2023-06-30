/*
 * RTPinBoard
 * Версия: 1.1
 * Создал: RootTool
 * https://www.youtube.com/@roottool0
 *
 * Видео
 * https://www.youtube.com/watch?v=Pe57_49BhEs
 */

#pragma once
#include <Arduino.h>

class RTPinBoard {
public:
 RTPinBoard(byte pin = 0, byte range = 10, int sw1 = 0, int sw2 = 145, int sw3 = 306, int sw4 = 494, int sw5 = 786);
 boolean isClick(byte button);
 boolean isRelease(byte button);
 boolean isHold(byte button);
 int readPin();
 
 void update();
 
 void setValue(byte button, int val);
 void setRange(byte val);
 void setPin(byte val);
private:
 byte _pin = 0;
 int _value[5] = {0, 0, 0, 0, 0};
 byte _range = 10;
 boolean _click[5] = {false, false, false, false, false};
 boolean _release[5] = {false, false, false, false, false};
 boolean _hold[5] = {false, false, false, false, false};
 
 boolean _flag[5] = {false, false, false, false, false};
 int _read = 0;
 boolean _btnState[5] = {false, false, false, false, false};
 uint32_t btnTimer[5] = {0,0,0,0,0};
};
