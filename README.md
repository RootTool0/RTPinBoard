# RTPinBoard
![](https://raw.githubusercontent.com/RootTool0/RTPinBoard/main/preview.png)
## Библиотека для удобной работы 5-ти клавишной клавиатурой
### Документация:

>     RTPinBoard board(0, 10, 1, 2, 3, 4);
>     Создаем обьект board класса RTPinBoard
>     0 - Номер аналогового порта Ардуины
>     10 - диапазон погрешности
>     1-4 - Номер аналогового порта Ардуины

>     boolean getSW1(); - boolean getSW5();
>     Выдает состояние клавишы 1 - 5

>     void update();
>     Функция, измеряющая сигнал с клавиатуры и
>     распределяет, какая кнопка нажата. 
>     Вызывать, если нужно получить актуальное 
>     состояние клавиатуры!! 

>     int readPin();
>     Выводит тоже самое, что analogRead()
>     С порта, который мы указали в начале.

>     void setSW1(int val); - setSW5(int val);
>     Задает кнопкам 1-5 их значение аналогового сигнала

>     void setRange(int val);
>     Задает диапазон погрешности

>     void setPin(int val);
>     Задает новый пин для клавиатуры.
>     После использование команды 
>     желательно использовать void update();
>     Для получения актуальной информации о клавиатуре.

### Обновления

##### 1.0 - Создание библиотеки RTPinBoard, ее выпуск в интернет и добавление документации со схемами.

### Схема подключения

##### Для Arduino Pro Micro
![](https://raw.githubusercontent.com/RootTool0/RTPinBoard/main/Схема%20Pro%20Micro.png)

##### Для Arduino Nano
![](https://raw.githubusercontent.com/RootTool0/RTPinBoard/main/Схема%20Nano.png)

### Ссылки

##### На мой канал: https://youtube.com/@roottool0
##### И видео об этом проекте: https://www.youtube.com/watch?v=Pe57_49BhEs
