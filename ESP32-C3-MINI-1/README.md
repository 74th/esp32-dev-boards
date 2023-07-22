# ESP32-C3-Micro

ESP32-C3-MINI-1 を使った開発ボード

## v1.2.0

- 回路図 Semantics [pdf](ESP32-C3-MINI-1-dev-board-semantics.pdf) [kicanvas](https://kicanvas.org/?github=https%3A%2F%2Fgithub.com%2F74th%2Fesp32-dev-boards%2Fblob%2Fesp32c3micro%2Fv1.2.0%2FESP32-C3-MINI-1%2FESP32-C3-MINI-1-panelized.kicad_sch)
- PCB [pdf](ESP32-C3-MINI-1-dev-board-pcb.pdf) [kicanvas](https://kicanvas.org/?github=https%3A%2F%2Fgithub.com%2F74th%2Fesp32-dev-boards%2Fblob%2Fesp32c3micro%2Fv1.2.0%2FESP32-C3-MINI-1%2FESP32-C3-MINI-1-panelized.kicad_pcb)

### 部品表

BoxPinHeader は ESP-Prog の UART と接続できます。

| 指定子   | 部品                             | 数量 |
| -------- | -------------------------------- | ---- |
| J1       | BoxPinHeader                     | 1    |
| SW1,SW2  | Tactile Button SKRPABE010        | 2    |
| D1       | 0805 LED Blue                    | 1    |
| J2       | USB-C-12-Pin-SMD                 | 1    |
| R1,R2    | 0805 Register 10kR               | 2    |
| R3,R4    | 0805 Register 0R                 | 2    |
| R5       | 0805 Register 1kR                | 1    |
| R6,R7    | 0805 Register 5.1kR              | 2    |
| C1,C5    | 0805 Capacitor 10uF              | 2    |
| C2,C3,C4 | 0805 Capacitor 100nF             | 3    |
| U2       | SOT-89 LDO Regulator AMS1117-3.3 | 1    |
| U1       | ESP32-C3-MINI-1                  | 1    |
