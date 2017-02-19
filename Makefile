LIB=-lsfml-graphics -lsfml-window -lsfml-system 
PROJECTNAME=catAndMouse


ifeq ($(OS),Windows_NT)
	COPYCOMMAND=copy
	DELCOMMAND=del
	PATHSEP2=\\
	LIBLOC=C:\bin\SFML\lib
	INCLUDE=-I "C:\bin\SFML-2.4.1\include"

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
#SRC=maze-map-collision$(PATHSEP2)maze-map-collision
SRC=src

OBJS= alienattack.o attack.o bigMap.o character.o entity.o grid.o helper.o main.o

all: linux

%.o: $(SRC)$(PATHSEP2)%.cpp 
	
	$(CC) $(INCLUDE) -c $< -o $@ -std=c++11


window:  $(OBJS)
	
	$(CC) -L $(LIBLOC) -o $(PROJECTNAME).exe $(OBJS) $(LIB)
	$(COPYCOMMAND) $(LIBLOC)\*.dll .
	$(DELCOMMAND) *-d-2.dll
	@echo Success


linux: $(OBJS)
	@echo "Building the game"
	$(CC) -o $(PROJECTNAME) $(OBJS) $(LIB)
	@echo "Success"

run : linux
	./$(PROJECTNAME)

clean:
	$(DELCOMMAND) $(PROJECTNAME)* $(SRC)$(PATHSEP2)*.o *.dll 1 *.o
