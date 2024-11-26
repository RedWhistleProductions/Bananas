rm /home/monkey/Documents/RWP/CPP/Bananas/Plugins/Input/SDL2_Input/SDL2_Input.so
g++ -shared -o SDL2_Input.so main.cpp -lSDL2 -fPIC
mv ./SDL2_Input.so /home/monkey/Documents/RWP/CPP/Bananas/Plugins/Input/SDL2_Input/SDL2_Input.so
