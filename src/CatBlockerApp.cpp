#include "CatBlockerApp.h"

#include <cinder/gl/gl.h>

using ci::app::KeyEvent;
using ci::gl::clear;

bool KeyPressed(int key) {
  return GetAsyncKeyState(key) & 0x8000;
}

void CatBlockerApp::prepareSettings(Settings *settings)
{
  settings->setWindowSize(0, 0);
  settings->setBorderless(true);
  settings->setFrameRate(60.0f);
}

void CatBlockerApp::setup()
{
  current_color_ = ci::Color(255, 0, 0);
  is_hidden_ = false;
}

void CatBlockerApp::update()
{
  if (KeyPressed(VK_SPACE)) {
    setFullScreen(false);
  }
  else if (KeyPressed(VK_CONTROL)) {
    setFullScreen(true);
  }
}

void CatBlockerApp::draw()
{
  clear(current_color_, true);
}

void CatBlockerApp::keyDown(KeyEvent event)
{

}
