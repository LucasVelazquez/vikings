# Vikingos

Juego rpg dibujado con caracteres ASCII.

![](https://media.giphy.com/media/QTxqLac8yDBsABUWAb/giphy.gif)

## Requisitos para jugar

* Windows.
* MinGW instalado.
* Una consola cmd y mucha imaginación.

## Para crear el ejecutable:

Ir a la carpeta raiz y ejecutar el siguiente comando:

```
gcc utils/utils.c structures/level.c structures/inventory.c structures/talk_box.c structures/character.c  main/main.c -o game
```
Esto creará un ejecutable (game.exe).
