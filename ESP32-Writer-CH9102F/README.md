# CH9102F 使用自動ダウンロード制御付き ESP32 書き込みツール

## features

- WCH CH9102F を使用
- 自動ダウンロード制御に、CH32V003 を使用して、確実なタイミングで制御する
- ボタンによるダウンロードモードへ切り替え
- ESP-Prog 互換 SP32 書き込み用 1.24mm 2x3 ボックスピンヘッダ搭載
- はんだジャンパで、ESP-Prog 互換ポートの電源電圧を、3.3V または 5V に切り替え可能

## v1.0.1

- Semantics/回路図 [PDF](./ESP-Writer-CH9102F-v1.0.1-semantics.pdf) [KiCanvas](https://kicanvas.org/?github=https%3A%2F%2Fgithub.com%2F74th%2Fesp32-dev-boards%2Fblob%2Fesp32-writer-ch9102f%2Fv1.0.1%2FESP32-Writer-CH9102F%2FESP-Writer-CH9102F.kicad_sch)
- PCB [KiCanvas](https://kicanvas.org/?github=https%3A%2F%2Fgithub.com%2F74th%2Fesp32-dev-boards%2Fblob%2Fesp32-writer-ch9102f%2Fv1.0.1%2FESP32-Writer-CH9102F%2FESP-Writer-CH9102F.kicad_pcb)

### BOM

| Reference | Name                              | Package         | Quantity |
| --------- | --------------------------------- | --------------- | -------- |
| C1-5      | Capacitor 100nF                   | SMD I0603 M1608 | 5        |
| C6-7      | Capacitor 10uF                    | SMD I0603 M1608 | 2        |
| D1        | LED RED                           | SMD I0805 M2012 | 1        |
| D2-3      | LED BLUE                          | SMD I0805 M2012 | 2        |
| D4        | LED YELLOW                        | SMD I0805 M2012 | 1        |
| F1        | PolyFuse 1812 KT6-1100SMDI        | I1206 M3216     | 1        |
| J1        | USB Type-C Receptacle             |                 | 1        |
| J2        | Box Pin Header 2x3 Pitch 1.27mm   |                 | 1        |
| JP1       | Jumper Jumper_3_Open              |                 | 1        |
| R1-3      | Register 5.1kΩ                    | SMD I0603 M1608 | 3        |
| R4-5,R7   | Register 10kΩ                     | SMD I0603 M1608 | 3        |
| R6        | Register 1kΩ                      | SMD I0603 M1608 | 1        |
| R8-9      | Register 10Ω                      | SMD I0603 M1608 | 2        |
| SW1       | Button SKRPABE010                 |                 | 1        |
| U1        | USB to Serial Port IC WCH CH9102F | QFN-24          | 1        |
| U2        | MCU WCH CH32V003J4M6              | SOIC-8          | 1        |
| U3        | USB Power Protection IC CH213K    | SOT-23          | 1        |
| U4        | Regulator 3.3V AMS1117-3.3        | SOT-89          | 1        |
