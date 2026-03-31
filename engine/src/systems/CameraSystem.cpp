#include "systems/CameraSystem.hpp"

#include "components/CCamera.hpp"
#include "components/CPosition.hpp"

void CameraSystem::Update(Scene &scene)
{
    for (auto &e : scene.SceneEntities())
    {
        CPosition *position = scene.ScenePosition(*e);
        CCamera *camera = scene.SceneCamera(*e);

        if (!position || !camera) continue;

        camera->m_camera.target = {position->m_position.x + 20, position->m_position.y + 20};
    }
}
