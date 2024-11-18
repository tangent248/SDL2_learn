#include <SDL2/SDL.h>
#include "TextureManager.h"
#ifndef __Game__
#define __Game__

class Game {

public:
  Game() {}
  ~Game() {}

  bool init(const char *title, int xpos, int ypos, int width, int height,
            bool fullscreen);
  void render();
  void update();
  void handleEvents();
  void fps(int fps);
  void clean();
  // a function to access the private running variable
  bool running() { return m_bRunning; }

private:
  SDL_Window *m_pWindow;
  SDL_Renderer *m_pRenderer;
  bool m_bRunning;
  int m_currentFrame;
  TextureManager m_textureManager;

};
#endif /* defined(__Game__) */
