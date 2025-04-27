#pragma once

#ifdef TMT_PLATFORM_WINDOWS

extern Tomato::APP* Tomato::CreateAPP();

int main(int argc, char** argv) {

	Tomato::Log::Init();
	TMT_CORE_WARN("Initialized Log!");
	int a = 5;
	TMT_INFO("Hello! Var={0}", a);

	auto app = Tomato::CreateAPP();
	app->Run();
	delete app;
}

#endif
