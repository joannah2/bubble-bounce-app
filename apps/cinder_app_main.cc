#include "visualizer/bubble_bounce_app.h"

using bubblebounce::BubbleBounceApp;

void prepareSettings(BubbleBounceApp::Settings* settings) {
  settings->setResizable(false);
}

CINDER_APP(BubbleBounceApp, ci::app::RendererGl, prepareSettings);