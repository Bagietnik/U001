# U001
RP2040 + FreeRTOS + C/C++

**Introduction**

This project utilizes C/C++, and to set up the development environment, we chose Ubuntu for its built-in C/C++ compilers (gcc/g++). 
For an efficient development workflow, it is recommended to download Visual Studio Code (VSC) and CMake (search for them in VSC extensions).

To integrate the Raspberry Pi Pico SDK into our project, we can clone the following repository: https://github.com/raspberrypi/pico-sdk.
This SDK provides the necessary headers, libraries, and build system for writing programs for RP2040-based devices like the Raspberry Pi Pico, supporting languages such as C, C++, or assembly.

The simplest way to achieve this is by cloning the repository mentioned above.

Afterward, we need to set the PICO_SDK_PATH, which is essential for the Pico SDK environment. 
This can be done by specifying the path in the CMake file. 
pico_sdk_import.cmake provides all the necessary functions to configure the Pico SDK in CMake files and must be added to our CMake file.

Below is an example covering both of the steps mentioned above:

![image](https://github.com/Bagietnik/U001/assets/84154206/4b81423d-38bf-4422-88dc-c03a4ff7bbe6)

**How to run the code**
1. Clone the repository to the local environment
2. mkdir build
3. cd build
4. cmake ..
5. make
6. transfer the .uf2 file to the Raspberry Pi (press the button on board -> plug usb -> release -> copy)

**The summary**

- Hardware
  - RP2040 ARM Cortex M0+

- Software
  - VSC
  - CMake
  - C/C++
  - FreeRTOS
 
![Zrzut ekranu 2023-03-12 135435](https://github.com/Bagietnik/U001/assets/84154206/c6d8acc3-52cd-4ffe-bf4d-2bb4e09e55f5)



