LIB=-lsfml-graphics -lsfml-window -lsfml-system 
PROJECTNAME=catAndMouse
SRC=maze-map-collision\maze-map-collision

ifeq ($(OS),Windows_NT)
	COPYCOMMAND=copy
	DELCOMMAND=del
	LIBLOC=C:\bin\SFML\lib
	INCLUDE="C:\bin\SFML-2.4.1\include"

else
    UNAME_S := $(shell uname -s)
	#GXX=g++
	COPYCOMMAND=cp
	DELCOMMAND=rm
    ifeq ($(UNAME_S),Linux)
     
    endif
    ifeq ($(UNAME_S),Darwin)
       
    endif
endif



all:

	
	$(CC) -DSFML_STATIC -I $(INCLUDE) -O0 -g3 -Wall -c -fmessage-length=0 -o $(SRC)\main.o $(SRC)\main.cpp 
	$(CC) -L $(LIBLOC) -o $(PROJECTNAME).exe $(SRC)\main.o $(LIB)
	$(COPYCOMMAND) $(LIBLOC)\*.dll .
	$(DELCOMMAND) *-d-2.dll
	@echo Success
	
clean:
	$(DELCOMMAND) $(PROJECTNAME).exe $(SRC)\main.o *.dll 1