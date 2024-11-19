#include "Game.h"
#include <SDL2/SDL_image.h>
#include <iostream>
bool Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen)
{
  int flags = 0;
  if (fullscreen)
  {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  // attempt to initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    std::cout << "SDL init success\n";
    // init the window
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (m_pWindow != 0) // window init success
    {
      std::cout << "window creation success\n";
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
      if (m_pRenderer != 0) // renderer init success
      {
        std::cout << "renderer creation success\n";
        SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 0);
        m_textureManager.load("src/assets/char9.png",
                              "animate", m_pRenderer);
      }
      else
      {
        std::cout << "renderer init fail\n";
        return false; // renderer init fail
      }
    }
    else
    {
      std::cout << "window init fail\n";
      return false; // window init fail
    }
  }
  else
  {
    std::cout << "SDL init fail\n";
    return false; // SDL init fail
  }
  std::cout << "init success\n";
  m_bRunning = true; // everything inited successfully, start the main loop
  return true;
}
void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  m_textureManager.draw("animate", 0, 0, 128, 82,
                        m_pRenderer);
  m_textureManager.drawFrame("animate", 100, 100, 128, 82,
                             1, m_currentFrame, m_pRenderer);
  SDL_RenderPresent(m_pRenderer);
}
void Game::update()
{
  m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
}
void Game::fps(int fps)
{
  const int FPS = fps;
  const int frameDelay = 1000 / FPS;
  Uint32 frameStart;
  int frameTime;
  frameStart = SDL_GetTicks();
  frameTime = SDL_GetTicks() - frameStart;
  if (frameDelay > frameTime)
  {
    SDL_Delay(frameDelay - frameTime);
  }
}
void Game::handleEvents()
{
  SDL_Event event;
  if (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:

      stop();
      break;
    default:
      break;
    }
  }
}

void Game::clean()
{
  std::cout << "cleaning game\n";
  if (m_pRenderer != nullptr)
  {
    std::cout << "renderer is not null\n";
    SDL_DestroyRenderer(m_pRenderer);
  }
  if (m_pWindow != nullptr)
  {
    std::cout << "window is not null\n";
    SDL_DestroyWindow(m_pWindow);
  }

    SDL_Quit();
}
