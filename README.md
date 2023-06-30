# RTPinBoard
##### Версия: 1.1
![](https://raw.githubusercontent.com/RootTool0/RTPinBoard/main/preview.png)
## Библиотека для удобной работы 5-ти клавишной клавиатурой
### Документация:

>     RTPinBoard board(byte pin, byte range, int sw1, int sw2, int sw3, int sw4, int sw5);
>     Создаем обьект board класса RTPinBoard
>     pin - Номер аналогового порта Ардуины
>     range - Диапазон погрешности
>     sw1-sw5 - Значение для каждой кнопки, с которого она срабатывает

>     boolean isClick(byte button);
>     Возвращает true, если клавиша нажата
>     button - Номер кнопки SW (ОТ 1 ДО 5 ВКЛЮЧИТЕЛЬНО!!!!)

>     boolean isRelease(byte button);
>     Возвращает короткий true, когда клавиша была нажата и ее отпустили.
>     button - Номер кнопки SW (ОТ 1 ДО 5 ВКЛЮЧИТЕЛЬНО!!!!)

>     boolean isHold(byte button);
>     Возвращает true, если клавиша нажата более 200 мс.
>     button - Номер кнопки SW (ОТ 1 ДО 5 ВКЛЮЧИТЕЛЬНО!!!!)

>     void update();
>     Функция, измеряющая сигнал с клавиатуры и
>     вычисляет состояние каждой кнопки. 
>     Вызывать, если нужно получить актуальное 
>     состояние клавиатуры!! 

>     int readPin();
>     Выводит тоже самое, что analogRead()
>     С порта, который мы указали в начале.

>     void setValue(byte button, int val);
>     Задает кнопкам 1-5 их значение аналогового сигнала
>     button - Номер кнопки SW (ОТ 1 ДО 5 ВКЛЮЧИТЕЛЬНО!!!!)
>     val - значение для кнопки

>     void setRange(byte val);
>     Задает новый диапазон погрешности

>     void setPin(byte val);
>     Задает новый пин для клавиатуры.

>     После использований команд void setValue(byte button, int val);, void setRange(byte val); и void setPin(byte val);
>     желательно использовать void update();
>     Для получения обновленной и актуальной информации о клавиатуре.

### Обновления

##### 1.1 - Вместо "дубового" измерения, обновлено на измерение состояния кнопок (Нажата, Отпущена, Зажата)
##### 1.0 - Создание библиотеки RTPinBoard, ее выпуск в интернет и добавление документации со схемами.

### Схема подключения

##### Для Arduino Pro Micro
![](https://raw.githubusercontent.com/RootTool0/RTPinBoard/main/Схема%20Pro%20Micro.png)

##### Для Arduino Nano
![](https://raw.githubusercontent.com/RootTool0/RTPinBoard/main/Схема%20Nano.png)

### Ссылки

##### На мой канал: https://youtube.com/@roottool0
##### Видео об этом проекте: https://www.youtube.com/watch?v=Pe57_49BhEs
