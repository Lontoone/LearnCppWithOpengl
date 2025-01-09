#pragma once

#ifdef TE_PLATFORM_WINDOES

extern Application* CreateApplication();
int main(int argc, char** argv) {
	printf("Start engine\n");
	auto app = CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#else
	#error Only support Windows
#endif // TE_PLATFORM_WINDOES
