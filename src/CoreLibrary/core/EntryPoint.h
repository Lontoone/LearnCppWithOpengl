#pragma once

#ifdef TE_PLATFORM_WINDOES

extern Application* CreateApplication();
int main(int argc, char** argv) {
	printf("Start engine\n");
	Log::Init();
	//Log::GetCoreLogger()->warn("Init log");
	TE_CORE_WARN("Init log");
	int a = 5;
	TE_WARN("Init Client {0}" , a);
	auto app = CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#else
	#error Only support Windows
#endif // TE_PLATFORM_WINDOES
