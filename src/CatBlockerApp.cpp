#include "CatBlockerApp.h"

#include <cinder/gl/gl.h>

using ci::Color;
using ci::gl::clear;

void CatBlockerApp::prepareSettings(Settings *settings)
{
  settings->setWindowSize(0, 0);
  settings->setBorderless(true);
}

void CatBlockerApp::setup()
{

}

void CatBlockerApp::update()
{
  input_.update();
  if (input_.isSpaceDown() && input_.isLControlDown() && input_.isTabDown()) {
    setFullScreen(false);
  }
  else if (input_.countKeysDown() >= 4) {
    setFullScreen(true);
  }
}

void CatBlockerApp::draw()
{
  clear(Color(255, 0, 0), true);
}
