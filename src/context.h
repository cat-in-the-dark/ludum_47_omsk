#pragma once

#include "assets.h"
#include <memory>

class Context {
 public:
  const int width = 960;
  const int height = 544;
  std::unique_ptr<Assets> assets;

  Context();
  void Update();
  ~Context();
};

Context* GetContext();
void SetContext(Context* context);