LIB=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
PROJECTNAME=catAndMouse
SRC=src
BUILD=build
CC=g++



ifeq ($(OS),Windows_NT)
	COPYCMD=copy
	DELCMD=del
	MOVECMD=move
	PATHSEP2=\\
	LIBLOC=C:\bin\SFML\lib
	INCLUDE=-I "C:\bin\SFML-2.4.1\include"
	NULLDIR=nul

else
    UNAME_S := $(shell uname -s)
	COPYCMD=cp
	DELCMD=rm
	MOVECMD=mv
	PATHSEP2=/

    ifeq ($(UNAME_S),Linux)
	NULLDIR=/dev/null
    endif
    ifeq ($(UNAME_S),Darwin)

    endif
endif


OBJS= alienattack.o attack.o bigMap.o character.o chest.o damageTrap.o entity.o grid.o helper.o interactable.o network.o main.o trap.o   

all: makedir moveback linux moveto

%.o: $(SRC)$(PATHSEP2)%.cpp 	
	$(CC) $(INCLUDE) -c $< -o $@ -std=c++11

windows: makedir moveback window moveto

window:  $(OBJS)
	$(CC) -L $(LIBLOC) -o $(PROJECTNAME).exe $(OBJS) $(LIB)
	$(COPYCMD) $(LIBLOC)\*.dll .
	$(DELCMD) *-d-2.dll
	@echo Success


linux: $(OBJS)
	@echo "Building the game"
	$(CC) -o $(PROJECTNAME) $(OBJS) $(LIB)
	@echo "Success"
	
moveto:
	$(MOVECMD) *.o $(BUILD)
	
moveback:
	if [ -f $(BUILD)/main.o ]; then $(MOVECMD) $(BUILD)/*.o . ; fi
	
makedir:
	if [ ! -d "$(BUILD)" ]; then mkdir $(BUILD); fi

clean:
	$(DELCMD) $(PROJECTNAME)* $(BUILD)$(PATHSEP2)*.o *.dll 1 *.o 2>$(NULLDIR)

