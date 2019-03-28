OBJ = main.o screen.o
APPNAME = sound.out

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ)

%.o : %.c
	gcc -c -o $@ $< --std=c11

clean :
	rm $(OBJ) $(APPNAME)
zip :
	tar cf sound.tar *.c *.h makefile

