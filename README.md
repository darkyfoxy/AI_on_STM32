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

![board](img/mnist.jpg)

Демонстрация работы нейронной сети для распознавания рукописных цифр на микроконтроллере STM32H743.

Нейронная сеть была обучена с помощью PyTorch на датасетe MNIST.

Код для обучения нейронной сети, нейронная сеть и выборки для валидации доступны в [репозиwqтории](https://github.com/darkyfoxy/AI_on_STM32/tree/main/network_MNIST).

С помощью генератора кода STM32CubeMX и расширения X-CUBE-AI нейронная сеть была реализована на микроконтроллер STM32H743.

[Видео демонстрации работы](https://www.youtube.com/watch?v=OYYefBLlM6g).

## Example with CIFAR10 Dataset

