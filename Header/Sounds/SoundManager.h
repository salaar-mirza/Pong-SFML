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
    public:
        static void initialize();
        static void playSoundEffect(SoundType soundType);
        static void playBackgroundMusic();

    private:
        static sf::Music background_music;
        static sf::Sound sound_effect;
        static sf::SoundBuffer ball_bounce_buffer;

        static float background_music_volume;
        static const std::string bgm_path;
        static const std::string ball_bounce_path;

        static void loadSoundFromFile();
    };
}
