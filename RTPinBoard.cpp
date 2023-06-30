/*
 * RTPinBoard
 * Версия: 1.1
 * Создал: RootTool
 * https://www.youtube.com/@roottool0
 *
 * Видео
 * https://www.youtube.com/watch?v=Pe57_49BhEs
 */

#include "RTPinBoard.h"

RTPinBoard::RTPinBoard(byte pin, byte range,int sw1,int sw2,int sw3,int sw4,int sw5) {
	_pin = pin;
	_value[0] = sw1;
	_value[1] = sw2;
	_value[2] = sw3;
	_value[3] = sw4;
	_value[4] = sw5;
	_range = range;
}

void RTPinBoard::setValue(byte button, int val) {
	switch(button){
		case 1: _value[0] = val; break;
		case 2: _value[1] = val; break;
		case 3: _value[2] = val; break;
		case 4: _value[3] = val; break;
		case 5: _value[4] = val; break;
	}
}

void RTPinBoard::setRange(byte val) {_range = val;}
void RTPinBoard::setPin(byte val) {_pin = val;}
int RTPinBoard::readPin() {return _read;}

boolean RTPinBoard::isClick(byte button){return _click[button-1];}
boolean RTPinBoard::isRelease(byte button){return _release[button-1];}
boolean RTPinBoard::isHold(byte button){return _hold[button-1];}

void RTPinBoard::update(){
	_read = analogRead(_pin);
	if(_read >= _value[0] - _range && _read <= _value[0] + _range){
	  memset(_btnState, false, 5);
    _btnState[0] = true;
  }
	else if(_read >= _value[1] - _range && _read <= _value[1] + _range){
	  memset(_btnState, false, 5);
    _btnState[1] = true;
  }
	else if(_read >= _value[2] - _range && _read <= _value[2] + _range){
	  memset(_btnState, false, 5);
    _btnState[2] = true;
  }
	else if(_read >= _value[3] - _range && _read <= _value[3] + _range){
	  memset(_btnState, false, 5);
    _btnState[3] = true;
  }
	else if(_read >= _value[4] - _range && _read <= _value[4] + _range)  {
    memset(_btnState, false, 5);
    _btnState[4] = true;
	}
	else {memset(_btnState, false, 5);}
	
	for(int i = 0; i < 5; i++){
		if (_btnState[i] && !_flag[i] && millis() - btnTimer[i] > 100) {
      _flag[i] = true;
      btnTimer[i] = millis();
      _click[i] = true;
      _release[i] = false;
      _hold[i] = false;
    }
    if (_btnState[i] && _flag[i] && millis() - btnTimer[i] > 200) {
      btnTimer[i] = millis();
      _click[i] = false;
      _release[i] = false;
      _hold[i] = true;
    }
    if (!_btnState[i] && !_flag[i]) {
      _click[i] = false;
      _release[i] = false;
      _hold[i] = false;
    }
    
    if (!_btnState[i] && _flag[i] && millis() - btnTimer[i] > 100) {
      _flag[i] = false;
      btnTimer[i] = millis();
      _click[i] = false;
      _release[i] = true;
      _hold[i] = false;
    }
  }
}
