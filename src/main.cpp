#define SDL_MAIN_HANDLED 1
#include <SDL.h>
#include <SDL_opengl.h>


int main(int argc, char* args[]) {


    return 0;
}

#ifdef WIN32
#include <windows.h>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Your GUI application code here
    (void)hInstance;
    (void)hPrevInstance;
    (void)lpCmdLine;
    (void)nCmdShow;
    return main(0,nullptr);
}
#endif


