#include <windows.h>
#include <iostream>

bool KeyPressed(int key) {
  return GetAsyncKeyState(key) & 0x8000;
}

int main()
{
  int currently_pressed = 0;
  while(true) {
    int pressed = 0;
    for (short key = 0; key < 256; ++key) {
      if (KeyPressed(key)) ++pressed;
    }
    if (pressed >= 0 && currently_pressed != pressed) {
      std::cout << "Key num pressed: " << pressed << std::endl;
      currently_pressed = pressed;
    }
  }
}