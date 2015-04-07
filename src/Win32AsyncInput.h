#pragma once

#include <vector>

class Win32AsyncInput
{
public:
  Win32AsyncInput();
  ~Win32AsyncInput();

  bool isLControlDown();
  bool isTabDown();
  bool isSpaceDown();

  bool isAnyCharacterDown();
  bool isAnyNumberDown();

  std::vector<int> getNumbersDown();
  std::vector<char> getCharactersDown();

  int countKeysDown();

  void update();

  bool isKeyDown(int key);
  static bool isKeyDownAsync(int key);
private:
  bool keys_down_[256];
};
