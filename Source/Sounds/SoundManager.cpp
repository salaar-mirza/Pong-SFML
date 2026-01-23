#include "../../Header/Sounds//SoundManager.h"
#include <iostream>

namespace Sounds
{

    sf::SoundBuffer SoundManager::ballBounce;
    sf::Sound SoundManager::soundEffect;

    const std::string SoundManager::ballBouncePath = "Assets/Sounds/Ball_Bounce.wav";

    void SoundManager::Initialize()
    {
        LoadSoundFromFile();
    }

    void SoundManager::LoadSoundFromFile()
    {
        if (!ballBounce.loadFromFile(ballBouncePath))
            std::cerr << "Error loading sound file: " << ballBouncePath << std::endl;
    }

    void SoundManager::PlaySoundEffect(SoundType soundType)
    {
        switch (soundType)
        {
        case SoundType::BALL_BOUNCE:
            soundEffect.setBuffer(ballBounce);
            break;
        default:
            std::cerr << "Invalid sound type" << std::endl;
            return;
        }

        soundEffect.play();
    }
    
}