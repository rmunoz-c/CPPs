#!/bin/bash

# Limpia los archivos previos
rm -f file.txt file.txt.replace

# Crea un archivo de prueba
echo "Hello World!" > file.txt
echo "This is a test file." >> file.txt
echo "World World World!" >> file.txt

echo "Contenido original:"
cat file.txt
echo

# Ejecuta tu programa
echo "Ejecutando reemplazo: World -> Universe"
./replace file.txt World Universe

# Muestra el resultado
echo
echo "Contenido del archivo generado:"
cat file.txt.replace
