
#include "SekaiEngine.h"
#include <array>
#include <algorithm>

#define CHECK_SAME_VALUE(FIRST, SECOND, THIRD) (\
    (m_values[(FIRST)] != ' ') && (m_values[(SECOND)] != ' ') && (m_values[(THIRD)] != ' ') && \
    (m_values[(FIRST)] == m_values[(SECOND)]) && (m_values[(THIRD)] == m_values[(SECOND)])\
    )

enum class GameState
{
    IN_GAME,
    OUT_OF_GRID,
    X_WIN,
    O_WIN
};

class TicTacToeLayer: public SekaiEngine::Layer::Layer
{
public:
    TicTacToeLayer()
        :Layer("TicTacToeLayer"), m_circle(SekaiEngine::Math::Vector2D(), 5.0f), m_state(GameState::IN_GAME)
    {
        for(std::size_t i = 0; i < m_grids.size(); ++i)
        {
            std::size_t row = i / 3;
            std::size_t col = i % 3;

            m_grids[i] = SekaiEngine::Shape::Rectangle(SekaiEngine::Math::Vector2D((float)row * 200, (float)col * 200), 200.0f, 200.0f);
            m_values[i] = ' ';
            m_currentValues = 'X';
        }
        m_offset.X() = SekaiEngine::Application::Instance()->Window().GetWidth() * 0.5f - 200 * 3 * 0.5f;
        m_offset.Y() = SekaiEngine::Application::Instance()->Window().GetHeight() * 0.5f - 200 * 3 * 0.5f;
    }

    TicTacToeLayer(const TicTacToeLayer& layer)
        :Layer(layer), m_circle(layer.m_circle), m_state(layer.m_state)
    {

    }

    ~TicTacToeLayer()
    {

    }


    void OnUpdate(const SekaiEngine::Timestep& elipse) override
    {
        if(m_state != GameState::IN_GAME)
        {
            if(SekaiEngine::Input::IsKeyPressed(SekaiEngine::Input::KEY_SPACE))
            {
                _reset();
            }

            return;
        }
        m_circle.Center.X() = SekaiEngine::Input::GetMouseX();
        m_circle.Center.Y() = SekaiEngine::Input::GetMouseY();

        for(std::size_t i = 0; i < m_isHovers.size(); ++i)
        {
            SekaiEngine::Math::Vector2D mouseOffset(
                m_circle.Center.X() - m_offset.X() - m_grids[i].Position.X(),
                m_circle.Center.Y() - m_offset.Y() - m_grids[i].Position.Y());
            m_isHovers[i] = mouseOffset.X() >= 0 && mouseOffset.Y() >= 0 && mouseOffset.X() <= m_grids[i].Width && mouseOffset.Y() <= m_grids[i].Height;
            //0 for check if mouse button left pressed see: https://github.com/hailiang194/NeoSekaiEngine/issues/8
            if(m_isHovers[i] && m_values[i] == ' ' && SekaiEngine::Input::IsButtonPressed(0))
            {
                _handleGridClicked(i);
            }
        }
    
    }

    void OnRender() override
    {
        for(std::size_t i = 0; i < m_grids.size(); ++i)
        {

            SekaiEngine::Render::RenderProperties rectProps;
            rectProps.Offset = m_offset;
            SekaiEngine::Render::RectangleRenderParams rectParams(rectProps, m_grids[i]);
            rectProps.Tint = static_cast<SekaiEngine::Render::Color>(
                m_values[i] == ' ' && m_isHovers[i] ? (uint32_t)0xffff00ff : (uint32_t)0x00ffffff);
            SekaiEngine::Render::RenderCommand::Render(rectParams);

            if(m_values[i] != ' ')
            {
                SekaiEngine::Math::Vector2D pos(
                    m_offset.X() + m_grids[i].Position.X() + 40.0f, 
                    m_offset.Y() + m_grids[i].Position.Y()
                );

                SekaiEngine::Render::API::DrawText(m_values[i] == 'X' ? "X" : "O", pos, 
                    (SekaiEngine::Render::Color)(m_values[i] == 'X' ? 0xff0000ff : 0x0000ffff), 200.0f
                );
            }
        }

        SekaiEngine::Render::RenderProperties props;
        SekaiEngine::Render::CircleRenderParams params(props, m_circle);
        SekaiEngine::Render::RenderCommand::Render(params);

        if(m_state != GameState::IN_GAME)
        {
            SekaiEngine::Shape::Rectangle overlay(
                SekaiEngine::Math::Vector2D(),
                (const float)SekaiEngine::Application::Instance()->Window().GetWidth(),
                (const float)SekaiEngine::Application::Instance()->Window().GetHeight()
            );

            SekaiEngine::Render::RenderProperties overlayProps;
            overlayProps.Tint = (SekaiEngine::Render::Color)0x0000ffe0;
            SekaiEngine::Render::RectangleRenderParams overlayParams(overlayProps, overlay);
            SekaiEngine::Render::RenderCommand::Render(overlayParams);

            SekaiEngine::Render::API::DrawText("Press <Space> to start new game",
                    SekaiEngine::Math::Vector2D(
                        700.0f, 
                        (const float)SekaiEngine::Application::Instance()->Window().GetHeight() - 20.0f
                        ), 
                    (SekaiEngine::Render::Color)0xffffffff, 20.0f
                );

            switch(m_state)
            {
                case GameState::OUT_OF_GRID:
                    SekaiEngine::Render::API::DrawText("OUT OF GRID",
                    SekaiEngine::Math::Vector2D(
                        700.0f,
                        (const float)SekaiEngine::Application::Instance()->Window().GetHeight() * 0.5f - 25.0f
                        ), (SekaiEngine::Render::Color)0xffffffff, 50.0f 
                    );
                    break;
                case GameState::X_WIN:
                    SekaiEngine::Render::API::DrawText("X WIN",
                    SekaiEngine::Math::Vector2D(
                        780.0f,
                        (const float)SekaiEngine::Application::Instance()->Window().GetHeight() * 0.5f - 25.0f
                        ), (SekaiEngine::Render::Color)0xffffffff, 50.0f 
                    );
                    break;
                case GameState::O_WIN:
                    SekaiEngine::Render::API::DrawText("O WIN",
                    SekaiEngine::Math::Vector2D(
                        780.0f,
                        (const float)SekaiEngine::Application::Instance()->Window().GetHeight() * 0.5f - 25.0f
                        ), (SekaiEngine::Render::Color)0xffffffff, 50.0f 
                    );
                    break;
            }
        }
    }
private:
    std::array<SekaiEngine::Shape::Rectangle, 9> m_grids;
    std::array<bool, 9> m_isHovers;
    std::array<char, 9> m_values;
    char m_currentValues;
    SekaiEngine::Shape::Circle m_circle;
    SekaiEngine::Math::Vector2D m_offset;
    GameState m_state;

    void _handleGridClicked(const std::size_t& gridPos)
    {
        m_values[gridPos] = m_currentValues;


        //Check win
        if(
            //diagonal
            CHECK_SAME_VALUE(0, 4, 8) ||
            CHECK_SAME_VALUE(2, 4, 6) ||
            //horizontal
            CHECK_SAME_VALUE(0, 1, 2) ||
            CHECK_SAME_VALUE(3, 4, 5) ||
            CHECK_SAME_VALUE(6, 7, 8) ||
            //vertical
            CHECK_SAME_VALUE(0, 3, 6) ||
            CHECK_SAME_VALUE(1, 4, 7) ||
            CHECK_SAME_VALUE(2, 5, 8)
        )
        {
            if(m_currentValues == 'X')
                m_state = GameState::X_WIN;
            else
                m_state = GameState::O_WIN;

            return;
        }

        m_currentValues = m_currentValues == 'X' ? 'O' : 'X';
        
        //Check if out of grid
        if(std::find(m_values.begin(), m_values.end(), ' ') == m_values.end())
        {
            m_state = GameState::OUT_OF_GRID;
        }
    }

    void _reset()
    {
        for(std::size_t i = 0; i < m_values.size(); ++i)
        {
            m_values[i] = ' ';
        }

        m_currentValues = 'X';
        m_state = GameState::IN_GAME;
    }
};


class TicTacToeApplication: public SekaiEngine::Application
{
public:
    TicTacToeApplication()
        :Application()
    {
        PushLayer(new TicTacToeLayer());
    }

    TicTacToeApplication(const TicTacToeApplication& TicTacToeApplication)
        :Application(TicTacToeApplication)
    {

    }

    ~TicTacToeApplication()
    {

    }
};

SekaiEngine::Application* SekaiEngine::CreateApplication()
{
    return new TicTacToeApplication();
}
    