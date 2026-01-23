#include "../../Header/Sounds/SoundManager.h"
#include <stdexcept>

namespace Sounds
{
	sf::Music SoundManager::background_music;
	sf::Sound SoundManager::sound_effect;
	sf::SoundBuffer SoundManager::ball_bounce_buffer;

	float SoundManager::background_music_volume = 50.0f;
	const std::string SoundManager::bgm_path = "Assets/Sounds/Pong_bgm.mp3";
	const std::string SoundManager::ball_bounce_path = "Assets/Sounds/Ball_Bounce.wav";

	void SoundManager::initialize()
	{
		loadSoundFromFile();
		playBackgroundMusic();
	}

	void SoundManager::loadSoundFromFile()
	{
		if (!ball_bounce_buffer.loadFromFile(ball_bounce_path))
		{
			throw std::runtime_error("Error loading sound file: " + ball_bounce_path);
		}
		if (!background_music.openFromFile(bgm_path))
		{
			throw std::runtime_error("Error loading background music file: " + bgm_path);
		}
	}

	void SoundManager::playSoundEffect(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BALL_BOUNCE:
			sound_effect.setBuffer(ball_bounce_buffer);
			break;
		default:
			return;
		}

		sound_effect.play();
	}

	void SoundManager::playBackgroundMusic()
	{
		background_music.setVolume(background_music_volume);
		background_music.setLoop(true);
		background_music.play();
	}
}
