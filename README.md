# Duck-Duck
Intro to Computer Graphics Final Project


Demo Video:
https://www.youtube.com/watch?v=HemGh0h-m_g




DuckDuck run:

Opens up window with a duck as the user. Goal of the game is to move through the levels while avoiding being shot by the hunters.

< key to move left
> key to move right
[space] key to jump

using the mouse, a right click will cause the duck to shoot back at whatever the icon is hitting


# Build and Compile (MacOS)
1. Install Homebrew
2. Install CMake via Homebrew
    ```
    brew install cmake
    ```
    check installation with:
    ```
    cmake
    ```
3. 
```
mkdir build && cd build
```
4. 
```
cmake ..
```
5. 
```
make
```
6. run
   ``` 
    ./DuckDuck
    ```

## About
This project uses OpenGL.

### Future Release
Future Release will include:
- Start option
- View stats
- Duck returns back

How to generate doctest.h with cmake?
How to integrate doctest into cmake?
How to make them an executable?

https://github.com/bsamseth/cpp-project/blob/master/src/example.cpp