#include <raylib.h>
#include "context.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

void Update() {
  GetContext()->Update();
}

int main() {
  Context ctx;
  SetContext(&ctx);

#if defined(PLATFORM_WEB)
  emscripten_set_main_loop(Update, 0, 1);
#else
  while (!WindowShouldClose()) {
    Update();
  }
#endif
  return 0;
}