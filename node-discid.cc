#include <node.h>

void GenerateTocFromDevice(const v8::FunctionCallackInfo<v8::Value>& args) {
    v8::Isolate* isolate = args.GetIsolate();
    auto message = v8::String::NewFromUtf8(isolate, "TOC");
    args.GetReturnValue().Set(message);
}

void Initialize(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "generateTocFromDevice", GenerateTocFromDevice);
}

NODE_MODULE(module_name, Initialize);
