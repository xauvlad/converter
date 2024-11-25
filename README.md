# Конвертер

Эта программа обрабатывает JPEG-файлы, приводя их к одинаковому разрешению (640x480), переводит цвета в оттенки серого и сохраняет нормализованные значения пикселей в текстовом формате.</br>

## Зависимости
- OpenCV 4.x
- CMake 3.15+
- C++17 +
- vcpkg

## Установка
1. Склонируйте этот репозиторий:
```bash
git clone https://github.com/xauvlad/converter.git
```
2. Установите OpenCV с помощью vcpkg:
```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.bat
./vcpkg install opencv
./vcpkg integrate install
```
3. Добавьте тулчейн vcpkg в CMake:
```bash
-DCMAKE_TOOLCHAIN_FILE=<path_to_vcpkg>/scripts/buildsystems/vcpkg.cmake
```
4. Замените переменную CMAKE_TOOLCHAIN_FILE в файле CMakeLists.txt на свое расположение пакета vcpkg
```
set(CMAKE_TOOLCHAIN_FILE "C:/<path>/<to>/vcpkg/scripts/buildsystems/vcpkg.cmake")
```
## Сборка
1. Создайте папку build и перейдите в неё:
```bash
mkdir build && cd build
```
2. Запустите CMake:
```bash
cmake .. -DCMAKE_TOOLCHAIN_FILE=<path_to_vcpkg>/scripts/buildsystems/vcpkg.cmake
cmake --build .
```
3. Запустите программу:
```bash
./Debug/convert.exe <путь к папке с картинками> <путь к итоговому файлу>
```