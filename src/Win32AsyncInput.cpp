#include "Win32AsyncInput.h"

#include <windows.h>

Win32AsyncInput::Win32AsyncInput()
{
  for (unsigned i = 0; i < 256; ++i) {
    keys_down_[i] = false;
  }
}

Win32AsyncInput::~Win32AsyncInput()
{

}

void Win32AsyncInput::update()
{
  for (int i = 0; i < 256; ++i) {
    keys_down_[i] = isKeyDownAsync(i);
  }
}

bool Win32AsyncInput::isKeyDownAsync(int key)
{
  return GetAsyncKeyState(key) & 0x8000;
}

bool Win32AsyncInput::isShiftDown()
{
  return isKeyDown(VK_SHIFT);
}

bool Win32AsyncInput::isControlDown()
{
  return isKeyDown(VK_CONTROL);
}

bool Win32AsyncInput::isTabDown()
{
  return isKeyDown(VK_TAB);
}

bool Win32AsyncInput::isKeyDown(int key)
{
  return keys_down_[key];
}

bool Win32AsyncInput::isSpaceDown()
{
  return isKeyDown(VK_SPACE);
}

int Win32AsyncInput::countKeysDown()
{
  int counter = 0;
  for (unsigned i = 0; i < 256; ++i) {
    if (keys_down_[i]) ++counter;
  }
  return counter;
}
