## Варіант #1. Пошук найкоротшого шляху

![Picture 1](https://github.com/DenBrun/a-star-path-finding/blob/main/screenshots/Screenshot1.png?raw=true)
![Picture 2](https://github.com/DenBrun/a-star-path-finding/blob/main/screenshots/Screenshot2.png?raw=true)

Знайти в заданому лабіринті найкоротший шлях між двома точками за допомогою алгоритму Дейкстри. Щоб написати цей алгоритм, треба скористатися структурою даних queue (черга), яку треба написати власноруч.

_Складніше завдання (+1 бал):_ Реалізувати [алгоритм А\*](https://en.wikipedia.org/wiki/A*_search_algorithm) з простою пріоритетною чергою – без написання binary heap (або з використанням 3rd party бібліотеки з binary heap. В цьому випадку вам все одно треба написати свою версію звичайної черги).

### Вхідні та вихідні дані

Вхідний лабіринт задається у файлі форматованою двовимірною матрицею. В коді задається точка початку пошуку шляху та кінцева точка. Приклад вхідних даних:

```
X X X X X X X X
X       X X   X
X   X   X X   X
X   X         X
X   X   X   X X
X   X   X   X X
X   X       X X
X X X X X X X X
```

Вивід – візуалзіація роботи алгоритму (у файл або на екран)

```
X X X X X X X X
X 5 6 7 X X e X
X 4 X 8 X X d X
X 3 X 9 a b c X
X 2 X   X   X X
X 1 X   X   X X
X   X       X X
X X X X X X X X
```

### Посилання

-   [Евристика](http://gamedev.stackexchange.com/questions/61850/in-a-star-how-does-the-heuristic-help-determine-your-path) в алгоритмах пошуку шляху в іграх
-   [Нормальний](http://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html) опис евристики в A\* від хлопців зі Стенфорду. Рекомендую почитати весь цикл
-   [Алгоритм А\*](https://en.wikipedia.org/wiki/A*_search_algorithm)
-   [Алгоритми BFS, Dijkstra, А\*](https://www.redblobgames.com/pathfinding/a-star/introduction.html)
-   [Бінарна купа](https://en.wikipedia.org/wiki/Binary_heap) – використовується як швидка пріоритетна черга в A\*, проте ще раз наголошую, в цій лабораторній роботі її писати не треба
-   [Пошук шляху](https://en.wikipedia.org/wiki/Pathfinding)

Пошук шляху дуже часто використовується для [трасування електричних плат](<https://en.wikipedia.org/wiki/Routing_(electronic_design_automation)>); для маршрутизації пакетів у [комп'ютерних мережах](https://en.wikipedia.org/wiki/Routing); для написання [AI в іграх](https://arongranberg.com/astar/). Черги та пріоритетні черги використовуються в ОС для контролю [доступу до ресурсів](https://github.com/torvalds/linux/blob/b3a3a9c441e2c8f6b6760de9331023a7906a4ac6/include/linux/prio_heap.h); для [імплементації](https://github.com/torvalds/linux/blob/master/include/linux/plist.h) м'ютексів та черги виконання процесів; в іграх та 3D-програмах для [рендерингу місцевості (terrain)](https://en.wikipedia.org/wiki/ROAM); в алгоритмах стискання зображень/музики/файлів – [кодування Хаффмана](https://en.wikibooks.org/wiki/JPEG_-_Idea_and_Practice/The_Huffman_coding).

_\*Написання алгоритму Дейкстри або A\* та черги (незалежно від обраного алгоритму) є обов'язковою умовою для здачі цього варіанту_
