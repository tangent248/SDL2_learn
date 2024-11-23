#include <SDL2/SDL.h>
#include <iostream>
#include <map>

class TextureManager {
public:
  static TextureManager& Instance() {
    static TextureManager instance; 
     return s_pInstance;
  }
  std::map<std::string, SDL_Texture *> m_textureMap;
  bool load(std::string fileName, std::string id, SDL_Renderer *pRenderer);
  // draw
  void draw(std::string id, int x, int y, int width, int height,
            SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  // drawframe
  void drawFrame(std::string id, int x, int y, int width, int height,
                 int currentRow, int currentFrame, SDL_Renderer *pRenderer,
                 SDL_RendererFlip flip = SDL_FLIP_NONE);

  typedef TextureManager TheTextureManager;

private:
  TextureManager() {}
  static TextureManager s_pInstance;
};
