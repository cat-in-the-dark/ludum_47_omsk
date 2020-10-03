#include "scene_manager.h"

#include <raylib.h>
void SceneManager::Update() {
  current_scene = next_scene;
  if (prev_scene != current_scene) {
    if (prev_scene != -1) {
      scenes[prev_scene]->Dispose();
    }
    scenes[current_scene]->Init();
    prev_scene = current_scene;
  }
  auto res = scenes[current_scene]->Update();

  if (res) {
    TraceLog(LOG_INFO, "Transition to next scene");
    next_scene = (current_scene + 1) % static_cast<int>(scenes.size());
  }
}
void SceneManager::Draw() {
  scenes.at(current_scene)->Draw();
}
