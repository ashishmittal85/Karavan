extern Karavan::Application* Karavan::CreateApplication();
int main(int argc, char** argv)
{
    auto app = Karavan::CreateApplication();
    app->Run();
    delete app;
}