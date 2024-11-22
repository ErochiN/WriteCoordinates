### Документация к классу `ConsolControl`

#### Описание

Класс `ConsolControl` предназначен для работы с двумерным массивом строк и вывода его на экран. Он позволяет записывать текст в произвольные координаты, а также управлять размером массива при необходимости. Массив автоматически увеличивается при записи в новые координаты.

#### Метод: `WriteСoordinatesXY`

```cpp
static void WriteСoordinatesXY(std::string newText, int ThisX, int ThisY);
```

**Описание:**  
Этот метод записывает текст в массив строк по указанным координатам (ThisX, ThisY). Если координаты выходят за пределы текущего размера массива, массив будет автоматически расширен.

**Параметры:**  
- `newText` — строка, которая будет записана в массив.
- `ThisX` — координата по оси X, в которой будет записан текст.
- `ThisY` — координата по оси Y, в которой будет записан текст.

**Пример использования:**

```cpp
ConsolControl::WriteСoordinatesXY("Hello", 2, 3);
```

**Описание работы:**  
1. Метод сначала очищает экран с помощью команды `system("cls")`.
2. Затем проверяет, был ли уже инициализирован массив (по значению ID).
3. Вычисляет новые размеры массива в зависимости от максимальных значений X и Y.
4. Если необходимо, увеличивает размеры массива.
5. Записывает новый текст в указанную ячейку массива.
6. Печатает обновленный массив на экран.
7. Увеличивает значение ID для следующего вызова.

---

#### Метод: `FillArray`

```cpp
static void FillArray();
```

**Описание:**  
Этот метод инициализирует массив строк `ARRAYCONSOL`. Он создает массив строк размером, определенным значениями `XSIZE` и `YSIZE`. Вызывается при первом обращении к методу `WriteСoordinatesXY`.

**Пример использования:**  
Этот метод вызывается автоматически внутри `WriteСoordinatesXY`, поэтому его не нужно вызывать напрямую.

---

#### Метод: `PrintArray`

```cpp
static void PrintArray();
```

**Описание:**  
Метод выводит содержимое двумерного массива строк на экран. Каждая строка массива выводится на новой строке в консоли.

**Пример использования:**

```cpp
ConsolControl::PrintArray();
```

**Описание работы:**  
1. Метод итерирует по всем строкам и столбцам массива.
2. Каждый элемент массива выводится с пробелом.
3. После окончания строки выполняется переход на новую строку.

---

#### Метод: `CopeArray`

```cpp
static void CopeArray(std::string** newArr);
```

**Описание:**  
Этот метод копирует содержимое текущего массива `ARRAYCONSOL` в новый массив `newArr`. Он используется внутри метода `AddElement` для переноса данных в новый массив с измененным размером.

**Пример использования:**  
Этот метод вызывается автоматически внутри метода `AddElement`, поэтому его не нужно вызывать напрямую.

---

#### Метод: `AddElement`

```cpp
static void AddElement(int xAdd, int yAdd);
```

**Описание:**  
Метод увеличивает размер массива строк `ARRAYCONSOL` и копирует в него старые данные. Новый массив создается с размерами `xAdd` и `yAdd`, затем старые данные переносятся в новый массив.

**Параметры:**  
- `xAdd` — новое количество элементов по оси X.
- `yAdd` — новое количество элементов по оси Y.

**Пример использования:**  
Этот метод вызывается автоматически внутри метода `WriteСoordinatesXY`, поэтому его не нужно вызывать напрямую.

---

### Инструкция по использованию

1. **Подключение заголовочного файла:**

   Для использования класса `ConsolControl`, включите заголовочный файл в ваш проект:

   ```cpp
   #include "ConsolControl.h"
   ```

2. **Запись текста в массив:**

   Для записи текста в заданные координаты (например, в строку 3, столбец 2), вызовите метод `WriteСoordinatesXY`:

   ```cpp
   ConsolControl::WriteСoordinatesXY("Text", 2, 3);
   ```

   Этот вызов записывает строку "Text" в ячейку с координатами X=2 и Y=3.

3. **Автоматическое увеличение массива:**

   Если вы попытаетесь записать текст в координаты, которые выходят за пределы текущего размера массива, то массив автоматически увеличится. Например:

   ```cpp
   ConsolControl::WriteСoordinatesXY("New Text", 5, 7);
   ```

   Если массив был до этого размером 1x1, он будет увеличен до 5x7 для размещения нового текста.

4. **Печать массива на экран:**

   Чтобы вывести текущий массив на экран, вызовите метод `PrintArray`:

   ```cpp
   ConsolControl::PrintArray();
   ```

5. **Очистка экрана:**

   При каждом вызове `WriteСoordinatesXY` экран будет очищен с помощью команды `system("cls")`. Это делает отображение обновлений в реальном времени более наглядным.

---

### Примечания:

- **Работа с памятью:** В классе используется динамическое выделение памяти для двумерного массива. Это позволяет динамически изменять размер массива по мере необходимости.
- **Ограничения:** Метод не проверяет, находятся ли переданные координаты внутри допустимого диапазона. Например, если вы передадите отрицательные значения для X или Y, программа может выйти за пределы массива.
- **Очистка экрана:** Использование `system("cls")` работает только в средах Windows. В других операционных системах этот метод может не работать или требовать изменений.

---

Этот класс подходит для задач, где нужно динамически изменять размер массива и выводить его на экран, например, для простых текстовых интерфейсов или отображения данных в консоли.
