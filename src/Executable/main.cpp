/*
#include "MyLibrary.h"

int main() {
    MyLibrary lib;
    lib.hello();
    return 0;
}
*/
#include <TinyEngine.h>
class Sandbox : public Application {
public:
    Sandbox() {};
    ~Sandbox() {};
};

/*
int main() {
    Sandbox* sandbox = new Sandbox();
    sandbox->Run();
    delete sandbox;

    return 0;
}
*/

Application* CreateApplication() {
    return new Sandbox();
}
