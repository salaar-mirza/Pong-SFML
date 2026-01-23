#pragma once
#include <SFML/Audio.hpp>
#include <string>

namespace Sounds
{
    enum class SoundType
    {
        BALL_BOUNCE
    };

    class SoundManager
    {
    private:
        static sf::Music backgroundMusic;
        static sf::Sound soundEffect;
        static sf::SoundBuffer ballBounce;

        static float backgroundMusicVolume;
        static const std::string bgmPath;
        static const std::string ballBouncePath;
				
       
    
    public:
        static void Initialize();
        static void LoadSoundFromFile();

        
        static void PlaySoundEffect(SoundType soundType);
        static void PlayBackgroundMusic();
    };
}
