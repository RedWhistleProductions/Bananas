rm /home/monkey/Documents/RWP/CPP/Bananas/Plugins/Audio/SDL2_Audio/SDL2_Audio.so
g++ -shared -o SDL2_Audio.so Audio.cpp -lSDL2 -lSDL2_mixer -fPIC
mv ./SDL2_Audio.so /home/monkey/Documents/RWP/CPP/Bananas/Plugins/Audio/SDL2_Audio/SDL2_Audio.so
