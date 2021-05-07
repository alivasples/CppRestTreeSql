# Common Ancestors in C++ + API Rest + SQLite

Este projecto es realizado como parte del examen técnico
de la empresa Aranda Software.
A pesar que el examen es en español, codificaré y colocaré los comentarios
de mis códigos en inglés debido que ésta es la mejor práctica.

## Consideraciones Previas:
1. Estamos usando **Pistache** como REST API, para instalar ver la [documentación oficial]{http://pistache.io/docs/} 
2. Estamos usando **SQLite** como gestor de base de datos, si está en un sistema operativo basado en ubuntu, debe haber instalado previamente el gestor con los comandos:
	```console
		dominio@usuario:~$ sudo apt-get install sqlite3 libsqlite3-dev
	```

## Compilación y Ejecución
1. Compilar el código a través del comando:
	```console
		dominio@usuario:~$ g++ -std=c++17 -o exam exam.cpp Tester.cpp Utils.cpp -lpistache -lsqlite3
	```

2. Executar el servidor con el comando:
	```console
		dominio@usuario:~$ ./exam 
	```

3. Deste otra terminal probar la funcionalidad de nuestro programa:
	1.  Insertar un nodo <numero> en el Árbol: 
		```console 
			dominio@usuario:~$ curl -X POST http://localhost:9080/addItem/<numero>
		```
	2.  Guardar el actual árbol en base de datos y crear uno vacío: 
		```console 
			dominio@usuario:~$ curl -X POST http://localhost:9080/newTree
		```
	3.  Mostrar los recorridos del árbol actual: 
		```console
			dominio@usuario:~$ curl http://localhost:9080/seeTree
		```
	4.  Buscar el ancestor común de dos elementos <numero1> y <numero2>: 
		```console
			dominio@usuario:~$ curl http://localhost:9080/commonAncestor/<numero1>,<numero2>
		```
