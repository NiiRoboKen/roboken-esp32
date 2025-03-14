# Roboken ESP32
新居浜高専ロボット研究部謹製ライブラリ

# 使用するにあたって
- このライブラリは`roboken-std`を継承したライブラリになっています
- `Arduino.h`を既にインクルードしているので`roboken-esp32.hpp`をインクルードするだけで良いです
- C++ 14の機能を使用しています。以下を`platformio.ini`に追記してください
```
build_flags = -std=gnu++14
build_unflags = -std=gnu++11
```
## Roboken STD
https://github.com/NiiRoboKen/roboken-std

## ライブラリの作りかた
https://docs.platformio.org/en/latest/librarymanager/creating.html
