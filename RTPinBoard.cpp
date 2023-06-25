#include <RTPinBoard.h>

RTPinBoard::RTPinBoard(byte pin, byte range,int sw1,int sw2,int sw3,int sw4,int sw5) {
  _pin = pin;
  _sw1 = sw1;
  _sw2 = sw2;
  _sw3 = sw3;
  _sw4 = sw4;
  _sw5 = sw5;
  _range = range;
}

void RTPinBoard::setSW1(int val) {_sw1 = val;}
void RTPinBoard::setSW2(int val) {_sw2 = val;}
void RTPinBoard::setSW3(int val) {_sw3 = val;}
void RTPinBoard::setSW4(int val) {_sw4 = val;}
void RTPinBoard::setSW5(int val) {_sw5 = val;}

void RTPinBoard::setRange(byte val) {_range = val;}
void RTPinBoard::setPin(byte val) {_pin = val;}

boolean RTPinBoard::getSW1() {return NumClicked == 1 ? true : false;}
boolean RTPinBoard::getSW2() {return NumClicked == 2 ? true : false;}
boolean RTPinBoard::getSW3() {return NumClicked == 3 ? true : false;}
boolean RTPinBoard::getSW4() {return NumClicked == 4 ? true : false;}
boolean RTPinBoard::getSW5() {return NumClicked == 5 ? true : false;}

int RTPinBoard::readPin() {return analogRead(_pin);}

void RTPinBoard::update(){
	int read = analogRead(_pin);
	if(read >= _sw1 - _range && read <= _sw1 + _range) NumClicked = 1;
	else if(read >= _sw2 - _range && read <= _sw2 + _range) NumClicked = 2;
	else if(read >= _sw3 - _range && read <= _sw3 + _range) NumClicked = 3;
	else if(read >= _sw4 - _range && read <= _sw4 + _range) NumClicked = 4;
	else if(read >= _sw5 - _range && read <= _sw5 + _range) NumClicked = 5;
	else NumClicked = 0;
}