#pragma once

#include <cinder/app/KeyEvent.h>
#include <cinder/app/AppBasic.h>

class CatBlockerApp : public ci::app::AppBasic
{
public:
  void prepareSettings(Settings *settings);
  void setup();
  void update();
  void draw();
  void keyDown(ci::app::KeyEvent event);
private:
  ci::Color current_color_;
  bool is_hidden_;
};