cripto:
	gcc -o cripto main.c
 
install: cripto
	mv  cripto /bin/cripto
 
clean: cripto
	rm -rf cripto