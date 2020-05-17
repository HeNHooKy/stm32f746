/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MSGBOXBASE_HPP
#define MSGBOXBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TiledImage.hpp>

class MsgBoxBase : public touchgfx::Container
{
public:
    MsgBoxBase();
    virtual ~MsgBoxBase() {}
    virtual void initialize();

    /*
     * Virtual Action Handlers
     */
    virtual void CloseMessage()
    {
        // Override and implement this function in MsgBox
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Image image1;
    touchgfx::ButtonWithLabel closeMessage;
    touchgfx::TextAreaWithOneWildcard message;
    touchgfx::TiledImage tiledImage1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t MESSAGE_SIZE = 256;
    touchgfx::Unicode::UnicodeChar messageBuffer[MESSAGE_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<MsgBoxBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // MSGBOXBASE_HPP
