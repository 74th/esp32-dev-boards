# CH32V003 Switch Firmware

- DTRのH→Lがあれば、EN、BOOTを使ってブートモードに入れる
- RTSのH→Lがあれば、ENを使ってリセットする
- SWが操作されれば、EN、BOOTを使ってブートモードに入れる

## flash

```
minichlink -w ./boot-switch.bin flash -b
```

OR

```
make
```

## debugging

SWDIOはLEDピンと兼用になっている、ボタンを押しながら電源を入れた場合のみ、SWDIOが有効になる。

開発中は、`#define ENABLE_DEBUGGING 0`を1に設定すると、LEDピンが無効になる。
