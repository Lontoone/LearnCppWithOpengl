#include <TinyEngine.h>

class ExampleLayer : public Layer {
public :
	ExampleLayer() :Layer("example") {}
	void OnUpdate()override {TE_INFO("example layer updated");}
	void OnEvent(Event& event) override {TE_TRACE("{0}" , event.ToString());}

};

class Sandbox : public Application {
public:
	Sandbox() { PushLayer(new ExampleLayer()); };
    ~Sandbox() {};
};


Application* CreateApplication() {
    return new Sandbox();
}
