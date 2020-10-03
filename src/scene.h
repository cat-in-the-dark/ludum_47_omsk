#pragma once

class IScene {
 public:
  virtual void Dispose() = 0;
  virtual void Init() = 0;
  virtual bool Update() = 0;
  virtual void Draw() = 0;
  virtual ~IScene() = default;
};