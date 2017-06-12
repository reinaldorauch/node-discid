#include <node.h>
#include <discid/discid.h>

void GenerateTocFromDevice(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::Isolate* isolate = args.GetIsolate();

    DiscId *disc = discid_new();

    if (discid_read_sparse(disc, "/dev/cdrom", 0) == 0) {
        isolate->ThrowException(v8::Exception::Error(
            v8::String::NewFromUtf8(isolate, discid_get_error_msg(disc))
        ));
        discid_free(disc);
        return;
    }

    auto id = v8::String::NewFromUtf8(isolate, discid_get_id(disc));
    args.GetReturnValue().Set(id);
    discid_free(disc);
}

void Initialize(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "generateTocFromDevice", GenerateTocFromDevice);
}

NODE_MODULE(module_name, Initialize);
