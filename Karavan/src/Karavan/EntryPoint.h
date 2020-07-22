extern Karavan::Application* Karavan::CreateApplication();
int main(int argc, char** argv)
{
    Karavan::Log::Init();
    KV_CORE_WARN("Initialized Log!");
    int a = 5;
    KV_INFO("Hello! Var={0}", a);
    auto app = Karavan::CreateApplication();
    app->Run();
    delete app;
}