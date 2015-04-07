#include "Win32AsyncInput.h"

#include <windows.h>

const int KEYS_NUM_ = 130;
int keys_to_check_ [KEYS_NUM_] = {
  VK_BACK,
  VK_TAB,
  VK_CLEAR,
  VK_RETURN,
  VK_LSHIFT,
  VK_RSHIFT,
  VK_LCONTROL,
  VK_RCONTROL,
  VK_LMENU,
  VK_RMENU,
  VK_PAUSE,
  VK_CAPITAL, // CapsLock
  VK_ESCAPE,
  VK_SPACE,
  VK_PRIOR, // PageUp
  VK_NEXT,  // PageDown
  VK_END,
  VK_HOME,
  VK_LEFT,
  VK_RIGHT,
  VK_DOWN,
  VK_UP,
  VK_SELECT,
  VK_PRINT,
  VK_EXECUTE,
  VK_SNAPSHOT,  // PrintScreen
  VK_INSERT,  // INS
  VK_DELETE,  // DEL
  VK_HELP,
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
  'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
  'U', 'V', 'W', 'X', 'Y', 'Z',
  VK_LWIN,
  VK_RWIN,
  VK_APPS,
  VK_SLEEP,
  VK_NUMPAD0,
  VK_NUMPAD1,
  VK_NUMPAD2,
  VK_NUMPAD3,
  VK_NUMPAD4,
  VK_NUMPAD5,
  VK_NUMPAD6,
  VK_NUMPAD7,
  VK_NUMPAD8,
  VK_NUMPAD9,
  VK_MULTIPLY,
  VK_ADD,
  VK_SEPARATOR,
  VK_SUBTRACT,
  VK_DECIMAL,
  VK_DIVIDE,
  VK_F1,
  VK_F2,
  VK_F3,
  VK_F4,
  VK_F5,
  VK_F6,
  VK_F7,
  VK_F8,
  VK_F9,
  VK_F10,
  VK_F11,
  VK_F12,
  VK_NUMLOCK,
  VK_SCROLL,
  VK_BROWSER_BACK,
  VK_BROWSER_FORWARD,
  VK_BROWSER_REFRESH,
  VK_BROWSER_STOP,
  VK_BROWSER_SEARCH,
  VK_BROWSER_FAVORITES,
  VK_BROWSER_HOME,
  VK_VOLUME_UP,
  VK_VOLUME_MUTE,
  VK_VOLUME_DOWN,
  VK_MEDIA_NEXT_TRACK,
  VK_MEDIA_PREV_TRACK,
  VK_MEDIA_STOP,
  VK_MEDIA_PLAY_PAUSE,
  VK_LAUNCH_MAIL,
  VK_LAUNCH_MEDIA_SELECT,
  VK_LAUNCH_APP1,
  VK_LAUNCH_APP2,
  VK_OEM_1,
  VK_OEM_PLUS,
  VK_OEM_COMMA,
  VK_OEM_MINUS,
  VK_OEM_PERIOD,
  VK_OEM_2,
  VK_OEM_3,
  VK_OEM_4,
  VK_OEM_5,
  VK_OEM_6,
  VK_OEM_7,
  VK_OEM_8,
  VK_OEM_102
};

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
  for (int i = 0; i < KEYS_NUM_; ++i) {
    int key = keys_to_check_[i];
    keys_down_[key] = isKeyDownAsync(key);
  }
}

bool Win32AsyncInput::isKeyDownAsync(int key)
{
  return GetAsyncKeyState(key) & 0x8000;
}

bool Win32AsyncInput::isLControlDown()
{
  return isKeyDown(VK_LCONTROL);
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
  // TempFix for #1
  if (keys_down_[VK_RMENU] && keys_down_[VK_LCONTROL]) --counter;
  return counter;
}
