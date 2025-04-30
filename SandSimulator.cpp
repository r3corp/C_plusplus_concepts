#include <SDL2/SDL.h>
#include <vector>
#include <cstdlib> // for rand()

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Simple Particle structure
struct Particle {
    int x, y;
};

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Sand Simulator",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    SDL_Event event;

    std::vector<Particle> particles;

    auto mousedown = false;

    while (running) {
        // Event Handling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;

            // Drop new sand when mouse pressed
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                mousedown = true;               
            }
            if (event.type == SDL_MOUSEBUTTONUP) {
                mousedown = false;  
            }
            if (event.type == SDL_MOUSEMOTION && mousedown) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                particles.push_back({mouseX + rand() % 5 - 2, mouseY});
            }
        }
        if (mousedown) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            particles.push_back({mouseX + rand() % 5 - 2, mouseY});
        }

        // Update
        for (auto& p : particles) {
            if (p.y < SCREEN_HEIGHT - 1)
                p.y += 1; // Gravity: sand falls down
        }

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 215, 0, 255); // Golden sand color
        for (const auto& p : particles) {
            SDL_RenderDrawPoint(renderer, p.x, p.y);
        }

        SDL_RenderPresent(renderer);

        SDL_Delay(16); // ~60 FPS
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}