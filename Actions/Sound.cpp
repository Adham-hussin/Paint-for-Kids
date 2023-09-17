#include "Sound.h"

Sound::Sound(ApplicationManager* app):Action(app)
{
}

void Sound::ReadActionParameters()
{
}

void Sound::Execute(bool readparams)
{
	UI.sound = !UI.sound;
}

void Sound::sound(bool on)
{
	
}