LIB=-lsfml-graphics -lsfml-window -lsfml-system 
PROJECTNAME=catAndMouse


ifeq ($(OS),Windows_NT)
	COPYCOMMAND=copy
	DELCOMMAND=del
	PATHSEP2=\
	LIBLOC=C:\bin\SFML\lib
	INCLUDE="C:\bin\SFML-2.4.1\include"

else
    UNAME_S := $(shell uname -s)
	COPYCOMMAND=cp
	DELCOMMAND=rm
	PATHSEP2=/

    ifeq ($(UNAME_S),Linux)

    endif
    ifeq ($(UNAME_S),Darwin)

    endif
endif
SRC=maze-map-collision$(PATHSEP2)maze-map-collision
#SRC=src


all: window

%.o: $(SRC)$(PATHSEP2)%.cpp 
	$(CC) -c $< -o $@


window: 
	$(CC)  -I $(INCLUDE) -O0 -g3 -Wall -c -fmessage-length=0 -o $(SRC)\main.o $(SRC)\main.cpp 
	$(LINK) -L $(LIBLOC) -o $(PROJECTNAME).exe $(SRC)\main.o $(LIB)
	$(COPYCOMMAND) $(LIBLOC)\*.dll .
	$(DELCOMMAND) *-d-2.dll
	@echo Success


linux: main.o
	@echo "Building the game"
	$(CC) -o $(PROJECTNAME) main.o $(LIB)
	rm main.o
	@echo "Success"


clean:
	$(DELCOMMAND) $(PROJECTNAME)* $(SRC)$(PATHSEP2)main.o *.dll 1 main.o
