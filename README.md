# Конвертер

Эта программа обрабатывает JPEG-файлы, приводя их к одинаковому разрешению (640x480), и сохраняет нормализованные значения пикселей в текстовом формате.</br>

## Зависимости
- OpenCV 4.x
- CMake 3.15+
- C++17 or later
- vcpkg (for dependency management)

## Установка
1. Склонируйте этот репозиторий:
```bash
git clone https://github.com/xauvlad/MyProject.git
```
2. Установите OpenCV с помощью vcpkg:
```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.bat
./vcpkg install opencv
```
3. Добавьте тулчейн vcpkg в CMake:
```bash
-DCMAKE_TOOLCHAIN_FILE=<path_to_vcpkg>/scripts/buildsystems/vcpkg.cmake
```