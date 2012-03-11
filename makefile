    rever : main.o renderfunctions.o
	gcc -o rever main.o renderfunctions.o
    renderfunctions.o : renderfunctions.c renderfunctions.h
	gcc -c renderfunctions.c
    main.o : main.c renderfunctions.h
	gcc -c main.c
    clean :
	rm rever main.o renderfunctions.o