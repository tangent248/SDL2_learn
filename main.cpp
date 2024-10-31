#include <iostream>
#include <SDL2/SDL.h>
#include <glad/glad.h>

void checkSDLError(int line = -1) {
    const char* error = SDL_GetError();
    if (*error != '\0') {
        std::cerr << "SDL Error: " << error;
        if (line != -1)
            std::cerr << " at line " << line;
        std::cerr << std::endl;
        SDL_ClearError();
    }
}

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not be initialized: " << SDL_GetError() << std::endl;
        return -1;
    }
    std::cout << "SDL video system is ready to go\n";

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    SDL_Window *window = SDL_CreateWindow("C++ SDL2 Window", 0, 0, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (!window) {
        std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << std::endl;
        return -1;
    }
    checkSDLError(__LINE__);

    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (!context) {
        std::cerr << "SDL_GL_CreateContext failed: " << SDL_GetError() << std::endl;
        return -1;
    }
    checkSDLError(__LINE__);

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    std::cout << "GLAD initialized\n";

    glViewport(0, 0, 640, 480);

    bool gameIsRunning = true;
    while (gameIsRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                gameIsRunning = false;
            }
            // Other event handling code...
        }

        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
