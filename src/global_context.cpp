#include "context.h"

static Context* global_context = nullptr;

Context* GetContext() {
  return global_context;
}
void SetContext(Context* context) {
  global_context = context;
}
