#include <SDL2/SDL.h>
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
  void stop() { m_bRunning = false; }

private:
  SDL_Window *m_pWindow;
  SDL_Renderer *m_pRenderer;
  bool m_bRunning;
  int m_currentFrame;
};
#endif /* defined(__Game__) */
