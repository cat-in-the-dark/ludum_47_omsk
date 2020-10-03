#include "context.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

void Update() {
  GetContext()->Update();
}

bool Run() {
  Context ctx;
  SetContext(&ctx);

#if defined(PLATFORM_WEB)
  emscripten_set_main_loop(Update, 0, 1);
#else
  while (!ctx.ShouldRestart()) {
    Update();
  }
#endif
  return !ctx.ShouldStop();
}

int main() {
  while (Run()) {
    ;
  }
  return 0;
}
