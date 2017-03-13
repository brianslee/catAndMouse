#include <SFML/Audio.hpp>
#include <SFML/System.hpp>



class Audio
{

public:

	
	//Constructor to load the audio files
	Audio();
	
	//play background music
	void playBackground();
	
	//stop playing sound effects
	void stopAudio();

	// Play Marine starting sound effect
	void playMarineIntro();

	// Play Alien starting sound effect
	void playAlienIntro();

	// Play Marine attacking sound effect
	void playMarineAttack();

	// Play Marine walking sound effect
	void playMarineWalk();

	
        // Play Marine attacking sound effect
        void playAlienAttack();

        // Play Marine walking sound effect
        void playAlienWalk();




	

private:

	sf::Music background;
	sf::Sound sound;
	sf::SoundBuffer buffer;
	bool isPlaying;

};








