LabAutoMakER
============

Утилита для автоматизированного создание Makefile для лабораторных по C++  
*by z4p*

------------
# Установка  
* скачать и распаковать архив с исходниками
* выполнить в директории исходников make -f install (с правами администратора)


Деинсталляция производится выполнением make -f install remove

------------
# Использование
automaker [-r] [-cl]  
 -r  - после создания Makefile выполнить make и запустить проект  
 -cl - очистить проект (после выполнения всех прочих действий)  
