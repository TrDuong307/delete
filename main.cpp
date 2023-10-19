#include <cstdlib>
#include <ctime>
#include "Engine.h"

int main(int argc, char* argv[]) {
    
    Engine::GetInstance()->Init();
    cout << "Hello World";

    cout << "BTL CTDL&GT";


    Engine::GetInstance()->Clean();

    return 0;
}
