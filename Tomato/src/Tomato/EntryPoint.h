#pragma once

#ifdef TMT_PLATFORM_WINDOWS

extern Tomato::APP* Tomato::CreateAPP();

int main(int argc, char** argv) {
	printf("Tomato Engine! ");
	auto app = Tomato::CreateAPP();
	app->Run();
	delete app;
}

#endif
