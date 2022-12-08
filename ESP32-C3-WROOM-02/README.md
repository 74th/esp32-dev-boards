# ESP32-C3 Dev Board

ESP32-C3-WROOM-02 を使った開発ボード

<img src="./esp32c3wroom02-board.jpg" width="300px">

- ピンヘッダは ESP-C3-DevKitC-02 互換の配置
- 10 ピンブレッドボードに挿しても、左右 1 ピン空いている
- ESP-Prog の USB シリアル変換のボックスピンヘッダを持つ
- USB Type-C をもつ

## 部品表

| 指定子   | パッケージ                | 数量 | 名称              |
| -------- | ------------------------- | ---- | ----------------- |
| R1       | Register_0805_2012        | 1    | 1k                |
| R2,R5    | Register_0805_2012        | 2    | 10k               |
| R3,R4    | Register_0805_2012        | 2    | 5.1k              |
| C1,C4,C6 | Capacitor_0805_2012       | 3    | 10u               |
| C2,C3,C7 | Capacitor_0805_2012       | 3    | 100n              |
| C5       | Capacitor_0805_2012       | 1    | 1u                |
| D1       | LED_0805_2012             | 1    | LED               |
| J3       | BoxPinHeader_2x03_P1.27mm | 1    | ESPProg-UART      |
| J4       | USB-C-12-Pin-MidMount     | 1    | USB2.0_C          |
| U1       | SOT-223-3_TabPin2         | 1    | AMS1117-3.3       |
| U2       | ESP32-C3-WROOM-02         | 1    | ESP32-C3-WROOM-02 |
| SW1,SW2  | SKRPABE010                | 2    | SW_Push           |
