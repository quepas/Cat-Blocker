#pragma once

#include "Win32AsyncInput.h"
#include <cinder/app/KeyEvent.h>
#include <cinder/app/AppBasic.h>

class CatBlockerApp : public ci::app::AppBasic
{
public:
  void prepareSettings(Settings *settings);
  void setup();
  void update();
  void draw();

private:
  Win32AsyncInput input_;
};
