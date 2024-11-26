rm /home/monkey/Documents/RWP/CPP/Bananas/Plugins/Renderer/SDL2_Renderer/SDL2_Renderer.so
g++ -shared -o SDL2_Renderer.so main.cpp -I/usr/include/GL -lGL -lGLEW -lSDL2 -lSDL2_image -fPIC
mv ./SDL2_Renderer.so /home/monkey/Documents/RWP/CPP/Bananas/Plugins/Renderer/SDL2_Renderer/SDL2_Renderer.so