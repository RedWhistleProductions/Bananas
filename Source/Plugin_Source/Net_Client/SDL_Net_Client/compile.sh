rm /home/monkey/Documents/RWP/CPP/Bananas/Plugins/Net_Client/SDL_Net_Client/SDL_Net_Client.so
g++ -shared -o SDL_Net_Client.so SDL_Net_Client.cpp -lSDL2 -lSDL2_net -fPIC
mv ./SDL_Net_Client.so /home/monkey/Documents/RWP/CPP/Bananas/Plugins/Net_Client/SDL_Net_Client/SDL_Net_Client.so
