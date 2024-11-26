rm /home/monkey/Documents/RWP/CPP/Bananas/Plugins/Input/Test_Input/Test_Input.so
g++ -shared -o Test_Input.so main.cpp -fPIC
mv ./Test_Input.so /home/monkey/Documents/RWP/CPP/Bananas/Plugins/Input/Test_Input/Test_Input.so
