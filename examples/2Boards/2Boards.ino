/*
 * Пример библиотеки RTPinBoard V1.1
 * Подключение 2-х модулей клавиатуры с 5 кнопками к аналаговым портам Ардуины
 *
 * Распиновкой:
 * Клавиатура 1 - Ардуино
 * OUT - Аналоговый пин A0
 * VCC - VCC(5 Вольт)
 * GND - GND
 * 
 * Клавиатура 2 - Ардуино
 * OUT - Аналоговый пин A1
 * VCC - VCC(5 Вольт)
 * GND - GND
 * 
 * Создатель:
 * RootTool - https://youtube.com/@roottool0
 * Видео об этом:
 * https://youtube.com/
*/

#include <RTPinBoard.h> //Подключаем библиотеку

RTPinBoard board1(0, 10, 0, 145, 306, 494, 786); //Создаем обьект Board1
RTPinBoard board2(1, 10, 0, 145, 306, 494, 786); //Создаем обьект Board2
//               ^   ^  ^   ^    ^    ^    ^
//               1   2  3   4    5    6    7
//1 - Номер аналогового пина (В данном случае A1)
//2 - Диапазон погрешности (Из за аналогового измерения, могут 
//возникать погрешности, поэтому мы вводим диапазон погрешности)
//3 - значения измерения для кнопки SW1
//4 - значения измерения для кнопки SW2
//5 - значения измерения для кнопки SW3
//6 - значения измерения для кнопки SW4
//7 - значения измерения для кнопки SW5
//Записанные здесь значения являются стандартными, чтобы их изменить, посмотрите мое видео

void setup() {
  Serial.begin(9600); //Открываем порт на скорости 9600 бод
  delay(1000); //Ждем 1 секунду
}

void loop() {
  //Делаем все тоже самое, что с примером 1Board
  board2.update();
  board1.update(); //Эта функция измеряет данные с аналогового пина, 
  //и вычисляет состояние всех кнопок.
  for(int i = 1; i < 6; i++){ //Создаем цикл от 1 до 5 включительно 
    //Это будут номера наших кнопок (Кнопки подписаны SW1 - SW5 на плате)
    
    if(board1.isClick(i)) Serial.println("Board 1 SW" + String(i) + " clicked"); 
    //Если кликнули кнопкой (Нажали и отпустили)
    
    if(board1.isHold(i)) Serial.println("Board 1 SW" + String(i) + " hold"); 
    //Если нажали на кнопку и не отпустили
    
    if(board1.isRelease(i)) Serial.println("Board 1 SW" + String(i) + " released"); 
    //Выводит 1, когда отпустили кнопку, т.е. убрали палец с кнопки, 
    //Полезно в некоторых проектах
  }

  for(int i = 1; i < 6; i++){ //Создаем цикл от 1 до 5 включительно 
    //Это будут номера наших кнопок (Кнопки подписаны SW1 - SW5 на плате)
    
    if(board2.isClick(i)) Serial.println("Board 2 SW" + String(i) + " clicked"); 
    //Если кликнули кнопкой (Нажали и отпустили)
    
    if(board2.isHold(i)) Serial.println("Board 2 SW" + String(i) + " hold"); 
    //Если нажали на кнопку и не отпустили
    
    if(board2.isRelease(i)) Serial.println("Board 2 SW" + String(i) + " released"); 
    //Выводит 1, когда отпустили кнопку, т.е. убрали палец с кнопки, 
    //Полезно в некоторых проектах
  }
}
