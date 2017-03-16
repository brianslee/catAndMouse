

#include "Audio.h"


Audio::Audio(){

	if(!background.openFromFile("audio/background.wav"))
	{
	return;
	}

}
void Audio::playBackground(){

	background.play();

}

void Audio::playAlienIntro(){


	 if(!buffer.loadFromFile("audio/alien_start.wav"))
                return;

	sound.setBuffer(buffer);
	sound.play();
}

void Audio::playMarineIntro(){

        if(!buffer.loadFromFile("audio/marine_start.wav"))
	        return;
	
	sound.setBuffer(buffer);
	sound.play();
}

void Audio::playMarineAttack(){


	if(sound.getStatus()!=sf::Sound::Stopped)
		return;

	if(!buffer.loadFromFile("audio/marine_attack.wav"))
		return;
	sound.setBuffer(buffer);
	sound.play();
	isPlaying = true;

}

void Audio::playMarineWalk(){
	
	if(sound.getStatus()!=sf::Sound::Stopped)
		return;
	if(!buffer.loadFromFile("audio/marine_walk.wav"))
		return;
	sound.setBuffer(buffer);
	sound.play();

	
}

void Audio::playAlienAttack(){


        if(sound.getStatus()!=sf::Sound::Stopped)
                return;

        if(!buffer.loadFromFile("audio/alien_attack.wav"))
                return;
        sound.setBuffer(buffer);
        sound.play();
        isPlaying = true;

}

void Audio::playAlienWalk(){

        if(sound.getStatus()!=sf::Sound::Stopped)
                return;
        if(!buffer.loadFromFile("audio/alien_walk.wav"))
                return;
        sound.setBuffer(buffer);
        sound.play();


}





void Audio::stopAudio(){

	sound.pause();
	
	isPlaying = false;

}
