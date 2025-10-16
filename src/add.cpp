#include <napi.h>

Napi::Value Add(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  
  int32_t a = info[0].As<Napi::Number>().Int32Value();
  int32_t b = info[1].As<Napi::Number>().Int32Value();
  int32_t result = a + b;
  
  return Napi::Number::New(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "add"),
              Napi::Function::New(env, Add));
  return exports;
}

NODE_API_MODULE(addon, Init)