# AI on STM32
Neural network implementation on STM32 with Cube-AI.

Проект для демонстрации работы нейронных сетей на микроконтроллерах STM32.

## Hardware

Для экспериментов был собран стенд:

![board](img/hardware.jpg)

Изображение снимается на камеру [OV2640](https://mcustore.ru/store/datchiki-i-sensory/kamera-ov2640-1600x1200/) (*Разрешение матрицы датчика изображения: 1600x1200*).

Камера через плату-коннектор подключена к отладочной плате от [DevEBox]( https://github.com/mcauser/MCUDEV_DEVEBOX_H7XX_M ) c микроконтроллером STM32H743VIT6 (*480 MHz,  2M Flash, 1M RAM*).

Изображение и результат выводиться на [TFT LCD дисплей](https://arduino-kit.ru/product/displey-144_-color-tft-128h128-spi) 1.44 дюйма с контроллером ili9163 (*Разрешение матрицы 128x128*).

## STMicroelectronics.X-CUBE-AI

Для всех экспериментов использовался пакет программного обеспечения **STMicroelectronics.X-CUBE-AI.6.0.0**

## Example with MNIST Dataset

Демонстрация работы нейронной сети для распознавания рукописных цифр на микроконтроллере STM32H743.

Код для обучения нейронной сети, нейронная сеть и выборки для валидации доступны в [репозитории](https://github.com/darkyfoxy/AI_on_STM32/tree/main/network_MNIST).

С помощью генератора кода STM32CubeMX и расширения X-CUBE-AI нейронная сеть была реализована на микроконтроллер STM32H743.

![mnist](img/mnist.jpg)

**PyTorch and ONNX**

Нейронная сеть была обучена с помощью PyTorch на датасетe MNIST. После этого экспортирована в граф вычислений в формате **ONNX**.

**Keras**

Нейронная сеть была обучена с помощью TensorFlow на датасетe MNIST. После этого сохранена в формате **Keras** H5.

**TensorFlow Lite**

Нейронная сеть была обучена с помощью TensorFlow на датасетe MNIST. После этого сохранена в формате **TF Lite** без квантования и с квантованием весов до *int8* (**TF Lite (Quant)**).

---

**Flash comparison***

| Сompression*** |   ONNX    |   Keras   |  TF Lite  | TF Lite (Quant) |
| :------------- | :-------: | :-------: | :-------: | :-------------: |
| None           | 778.16 KB | 778.16 KB | 778.16 KB |    195.74 KB    |
| x4             | 203.60 KB | 203.60 KB | 203.60 KB |  Not supported  |
| x8             | 105.63 KB | 105.63 KB | 105.63 KB |  Not supported  |

**RAM comparison***

| Сompression |  ONNX   |  Keras  | TF Lite | TF Lite (Quant) |
| ----------- | :-----: | :-----: | :-----: | :-------------: |
| None        | 4.66 KB | 4.66 KB | 4.66 KB |     1.17 KB     |
| x4          | 4.66 KB | 4.66 KB | 4.66 KB |  Not supported  |
| x8          | 4.66 KB | 4.66 KB | 4.66 KB |  Not supported  |

**Time comparison***

| Сompression |   ONNX   |  Keras   | TF Lite  | TF Lite (Quant) |
| ----------- | :------: | :------: | :------: | :-------------: |
| None        | 2.702 ms | 2.702 ms | 2.702 ms |    0.873 ms     |
| x4          | 2.657 ms | 2.653 ms | 2.654 ms |  Not supported  |
| x8          | 2.513 ms | 2.513 ms | 2.513 ms |  Not supported  |

**Accuracy comparison***

| Сompression |      ONNX       |      Keras      |     TF Lite     | TF Lite (Quant) |
| ----------- | :-------------: | :-------------: | :-------------: | :-------------: |
| None        | 91.6% (91.6%)** | 93.8% (93.8%)** | 93.8% (93.8%)** | 95.4% (95.4%)** |
| x4          | 91.5% (91.5%)** | 93.9% (93.9%)** | 93.9% (93.9%)** |  Not supported  |
| x8          | 91.7% (91.7%)** | 93.8% (93.8%)** | 93.8% (93.8%)** |  Not supported  |

*Во всех вариантах использовались одинаковые граф вычислений и дадасет для валидации. **Веса моделей различны**;

**Validation on target (Validation on desktop).

Из [документации от STMicroelectronics](https://www.st.com/resource/en/user_manual/dm00570145-getting-started-with-xcubeai-expansion-package-for-artificial-intelligence-ai-stmicroelectronics.pdf) (п. 6.1) компрессия размера весов и смещений основана на методе [k-средних](https://ru.wikipedia.org/wiki/Метод_k-средних) и применима только к полносвязным слоям. В моделях со сверточными слоями Cube-Ai выдает предупреждение: WARNING: no weight was compressed.

 ![youtube](https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white)
[Видео демонстрации работы](https://www.youtube.com/watch?v=OYYefBLlM6g).

## Example with CIFAR10 Dataset

Демонстрация работы нейронной сети для распознавания образов на микроконтроллере STM32H743.
Классификация производиться на 10 классов: 0 - airplane; 1 - automobile; 2 - bird; 3 - cat; 4 - deer; 5 - dog; 6 - frog; 7 - horse; 8 - ship; 9 - truck.

Код для обучения нейронной сети, нейронная сеть и выборки для валидации доступны в [репозитории](https://github.com/darkyfoxy/AI_on_STM32/tree/main/network_CIFAR10).

С помощью генератора кода STM32CubeMX и расширения X-CUBE-AI нейронная сеть была реализована на микроконтроллер STM32H743.

![cifar10](img/cifar.png)

Нейронная сеть была обучена с помощью PyTorch на датасетe CIFAR10.

Системные требования для вычисления нейронной сети (без сжатия): 

- Flash = 1.04 MB;

- RAM = 148.41 КВ.

Точность классификации: 81.30 %;

Время вычисления: 285.5 ms.

![youtube](https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white)
[Видео демонстрации работы](https://www.youtube.com/watch?v=fylVEovoXl0).

## Copyright

Some parts of this code were taken from other repositories. 

For OV2640 driver from [OpenMV repository](https://github.com/openmv/openmv).

For TFT ili9163 display driver from [Spirit532 repository](https://github.com/Spirit532/ILI9163C_STM32_HAL_DMA).

Other drivers without special instructions from STMicroelectronics.
