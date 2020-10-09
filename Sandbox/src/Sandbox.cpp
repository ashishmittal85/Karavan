#include "Karavan.h"

class ExampleLayer : public Karavan::Layer
{
public:
    ExampleLayer()
        : Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
    {
        m_VertexArray.reset(Karavan::VertexArray::Create());

        float vertices[3 * 7] = {
            -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
             0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
             0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
        };

        std::shared_ptr<Karavan::VertexBuffer> vertexBuffer;
        vertexBuffer.reset(Karavan::VertexBuffer::Create(vertices, sizeof(vertices)));

        Karavan::BufferLayout layout = {
            { Karavan::ShaderDataType::Float3, "a_Position"},
            { Karavan::ShaderDataType::Float4, "a_Color"},
        };

        vertexBuffer->SetLayout(layout);
        m_VertexArray->AddVertexBuffer(vertexBuffer);

        uint32_t indices[3] = {0, 1, 2};
        std::shared_ptr<Karavan::IndexBuffer> indexBuffer;
        indexBuffer.reset(Karavan::IndexBuffer::Create(indices, sizeof(indices)/sizeof(uint32_t)));
        m_VertexArray->SetIndexBuffer(indexBuffer);

        m_SquareVA.reset(Karavan::VertexArray::Create());
        float squareVertices[3 * 4] = {
            -0.75f, -0.75f, 0.0f,
             0.75f, -0.75f, 0.0f,
             0.75f,  0.75f, 0.0f,
            -0.75f,  0.75f, 0.0f
        };

        std::shared_ptr<Karavan::VertexBuffer> squareVB;
        squareVB.reset(Karavan::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
        squareVB->SetLayout({
            { Karavan::ShaderDataType::Float3, "a_Position" }
        });
        m_SquareVA->AddVertexBuffer(squareVB);

        uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
        std::shared_ptr<Karavan::IndexBuffer> squareIB;
        squareIB.reset(Karavan::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
        m_SquareVA->SetIndexBuffer(squareIB);

        std::string vertexSrc = R"(
         #version 330 core

         layout(location = 0) in vec3 a_Position;
         layout(location = 1) in vec4 a_Color;

         uniform mat4 u_ViewProjection;

         out vec3 v_Position;
         out vec4 v_Color;

         void main()
         {
             v_Position = a_Position;
             v_Color = a_Color;
             gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
         }
         )";
         std::string fragmentSrc = R"(
          #version 330 core

          layout(location = 0) out vec4 color;

          in vec3 v_Position;
          in vec4 v_Color;

          void main()
          {
              color = vec4(v_Position * 0.5 + 0.5, 1.0);
              color = v_Color;
          }
        )";
        m_Shader.reset(new Karavan::Shader(vertexSrc, fragmentSrc));

        std::string blueShaderVertexSrc = R"(
          #version 330 core

          layout(location = 0) in vec3 a_Position;

          uniform mat4 u_ViewProjection;
 
          out vec3 v_Position;

          void main()
          {
               v_Position = a_Position;
               gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
          }
         )";

         std::string blueShaderFragmentSrc = R"(
           #version 330 core

           layout(location = 0) out vec4 color;

           in vec3 v_Position;

           void main()
           {
               color = vec4(0.2, 0.3, 0.8, 1.0);
           }
          )";

          m_BlueShader.reset(new Karavan::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
    }

    void OnUpdate(Karavan::Timestep ts) override
    {
        if (Karavan::Input::IsKeyPressed(KV_KEY_LEFT))
        {
            m_CameraPosition.x -= m_CameraMoveSpeed * ts;
        } else if (Karavan::Input::IsKeyPressed(KV_KEY_RIGHT)) {
            m_CameraPosition.x += m_CameraMoveSpeed * ts;
        } 

        if (Karavan::Input::IsKeyPressed(KV_KEY_UP)) {
            m_CameraPosition.y += m_CameraMoveSpeed * ts;
        } else if (Karavan::Input::IsKeyPressed(KV_KEY_DOWN)) {
            m_CameraPosition.y -= m_CameraMoveSpeed * ts;
        }

        if (Karavan::Input::IsKeyPressed(KV_KEY_A)) {
            m_CameraRotation += m_CameraRotationSpeed * ts;
        } else if (Karavan::Input::IsKeyPressed(KV_KEY_D)) {
            m_CameraRotation -= m_CameraRotationSpeed * ts;
        }

        Karavan::RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1});
        Karavan::RenderCommand::Clear();

        m_Camera.SetPosition(m_CameraPosition);
        m_Camera.SetRotation(m_CameraRotation);

        Karavan::Renderer::BeginScene(m_Camera);
        Karavan::Renderer::Submit(m_BlueShader, m_SquareVA);

        Karavan::Renderer::Submit(m_Shader, m_VertexArray);

        Karavan::Renderer::EndScene();
    }

    void OnEvent(Karavan::Event& e) override
    {
    }

private:
    std::shared_ptr<Karavan::Shader> m_Shader;
    std::shared_ptr<Karavan::VertexArray> m_VertexArray;

    std::shared_ptr<Karavan::Shader> m_BlueShader;
    std::shared_ptr<Karavan::VertexArray> m_SquareVA;

    Karavan::OrthographicCamera m_Camera;
    glm::vec3 m_CameraPosition;
    float m_CameraMoveSpeed = 5.0f;

    float m_CameraRotation = 0.0f;
    float m_CameraRotationSpeed = 180.0f;
};

class Sandbox : public Karavan::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {
    }
};

Karavan::Application* Karavan::CreateApplication()
{
    return new Sandbox();
}