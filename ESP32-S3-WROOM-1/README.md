# ESP32-S3 Dev Board

![](ESP32-S3-dev-board-v1.1.1.jpg)

ESP32-S3-WROOM-1 を使った開発ボード。

- ピンヘッダは ESP32-S3-DevKitC 互換の配置
- 10 ピンブレッドボードに挿しても、左右 1 ピン空いている
- ESP-Prog の USB シリアル変換のボックスピンヘッダを持つ
- USB Type-C を持つ

## なぜ、公式の ESP32-S3-DevKitC を使わず、これを必要になるか

- 10 ピンブレッドボードに刺すと、片方使えなくなるから。
- MicroUSB ではなく USB Type-C で使いたいから。
- USB シリアル変換 IC が別になっている方が、ボード単体で使う時に消費電力が下がるから。

## v1.1.1

ピンヘッダのアサインは ESP32-S3-DevKitC v1.1 互換のため、こちらを確認下さい。

https://docs.espressif.com/projects/esp-idf/en/v4.4.2/esp32s3/hw-reference/esp32s3/user-guide-devkitc-1.html#header-block

### 部品表

| ID  | 指定子   | パッケージ                             | 数量 |
| --- | -------- | -------------------------------------- | ---- |
| 1   | SW1      | SKRPABE010(BOOT)                       | 1    |
| 2   | SW2      | SKRPABE010(EN)                         | 1    |
| 3   | C2       | 0805 キャパシタ 1uF                    | 1    |
| 4   | D3       | 0805 LED(D+)                           | 1    |
| 5   | U1       | ESP32-S3-WROOM-1                       | 1    |
| 6   | J3       | UART 1.27mm ボックスピンヘッダ 2x3     | 1    |
| 7   | U2       | 3.3v レギュレータ AMS1117-3.3          | 1    |
| 8   | R4       | 0805 レジスタ 10kR                     | 1    |
| 9   | D5       | 0805 LED(PWR)                          | 1    |
| 10  | D2       | 0805 LED(D-)                           | 1    |
| 13  | C5,C3,C1 | 0805 キャパシタ 10uF(0805 レジスタ 0R) | 3    |
| 14  | D4       | 1A40V ショットキーダイオード 1N5819    | 1    |
| 15  | D1       | 0805 LED(5V)                           | 1    |
| 16  | C4,C6    | 0805 キャパシタ 100nF                  | 2    |
| 17  | R2,R1    | 0805 レジスタ 5.1kR                    | 2    |
| 18  | J4       | USB 2.0 Type-C ソケット                | 1    |
| 19  | R3       | 0805 レジスタ 1kR                      | 1    |

- D4 には、USB からの電源供給の場合、レジスタ 0R をセットします。booth で販売のセットには 0805 レジスタ 0R を付属しています。

[部品の調達先はこちらを確認下さい ../parts.md](../parts.md)

### ドキュメント

- [Semantics ESP32-S3-WROOM-1-v1.1.1-semantics.pdf](ESP32-S3-WROOM-1-v1.1.1-semantics.pdf)
- [PCB ESP32-S3-WROOM-1-v1.1.1-pcb.pdf](ESP32-S3-WROOM-1-v1.1.1-pcb.pdf)
