#include "Application.h"

Application::Application() {}

int Application::OnExecute()
{
    return 0;
}

int main(int argc, char* argv[])
{
    Application application;

    return application.OnExecute();
}