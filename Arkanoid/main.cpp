//#define PRCORE_IMPLEMENT_MAIN
#include <prcore/prcore.hpp>
#include "Window.h"

using namespace prcore;

int main(int argc, char** argv)
{
	Window w;
	w.MoveWindow(512, 234);
	w.MainLoop();
	return 0;
}
