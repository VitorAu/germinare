#include "Engine.h"

#include "components/CInput.h"
#include "ecs/Scene.h"

#include "raylib.h"

Scene m_scene;

Engine::Engine(const int screenWidth, const int screenHeight, const char *screenTitle)
    : m_screenWidth(screenWidth), m_screenHeight(screenHeight), m_screenTitle(screenTitle)
{
}

Engine::~Engine() = default;

void Engine::Init()
{
    InitWindow(m_screenWidth, m_screenHeight, m_screenTitle);
    SetTargetFPS(60);

    auto player = m_scene.SceneAddEntity("player");
    CInput input;

    m_scene.SceneAddInput(input, *player);

    m_running = true;
}

void Engine::Update()
{
    while (m_running)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        m_scene.Update();

        EndDrawing();

        if (WindowShouldClose())
        {
            m_running = false;
        }
    }
}

void Engine::Quit()
{
    CloseWindow();
}
