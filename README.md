# AI on STM32
Neural network implementation on STM32 with Cube-AI.

Проект для демонстрации работы нейронных сетей на микроконтроллерах STM32.

## Hardware

Для экспериментов был собран стенд:

![board](img/hardware.jpg)

Изображение снимается на камеру [OV2640](https://mcustore.ru/store/datchiki-i-sensory/kamera-ov2640-1600x1200/) (*Разрешение матрицы датчика изображения: 1600x1200*).

Камера через плату-коннектор подключена к отладочной плате от [DevEBox]( https://github.com/mcauser/MCUDEV_DEVEBOX_H7XX_M ) c микроконтроллером STM32H743VIT6 (*480 MHz,  2M Flash, 1M RAM*).

Изображение и результат выводиться на [TFT LCD дисплей](https://arduino-kit.ru/product/displey-144_-color-tft-128h128-spi) 1.44 дюйма с контроллером ili9163 (*Разрешение матрицы 128x128*).

## Example with MNIST Dataset

![mnist](img/mnist.jpg)

Демонстрация работы нейронной сети для распознавания рукописных цифр на микроконтроллере STM32H743.

Нейронная сеть была обучена с помощью PyTorch на датасетe MNIST.

Код для обучения нейронной сети, нейронная сеть и выборки для валидации доступны в [репозитории](https://github.com/darkyfoxy/AI_on_STM32/tree/main/network_MNIST).

С помощью генератора кода STM32CubeMX и расширения X-CUBE-AI нейронная сеть была реализована на микроконтроллер STM32H743.

Системные требования для вычисления нейронной сети (без сжатия): 

- Flash = 778.16 KB;

- RAM = 4.66 КВ.

Точность классификации: 91.60 %;

Время вычисления: 2.7 ms.

[Видео демонстрации работы](https://www.youtube.com/watch?v=OYYefBLlM6g) ![youtube](https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white).

## Example with CIFAR10 Dataset
![cifar10](img/cifar.png)

Демонстрация работы нейронной сети для распознавания образов на микроконтроллере STM32H743.

Нейронная сеть была обучена с помощью PyTorch на датасетe CIFAR10.
Классификация производиться на 10 классов:
 	1. airplane
 	2. automobile
 	3. bird
 	4. cat
 	5. deer
 	6. dog
 	7. frog
 	8. horse
 	9. ship
 	10. truck

Код для обучения нейронной сети, нейронная сеть и выборки для валидации доступны в [репозитории](https://github.com/darkyfoxy/AI_on_STM32/tree/main/network_CIFAR10).

С помощью генератора кода STM32CubeMX и расширения X-CUBE-AI нейронная сеть была реализована на микроконтроллер STM32H743.

Системные требования для вычисления нейронной сети (без сжатия): 

- Flash = 1.04 MB;

- RAM = 148.41 КВ.

Точность классификации: 81.30 %;

Время вычисления: 285.5 ms.

[Видео демонстрации работы](https://www.youtube.com/watch?v=fylVEovoXl0) ![youtube](https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white).
