/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CUSTOMLISTELEMENTBASE_HPP
#define CUSTOMLISTELEMENTBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class CustomListElementBase : public touchgfx::Container
{
public:
    CustomListElementBase();
    virtual ~CustomListElementBase() {}
    virtual void initialize();

    /*
     * Virtual Action Handlers
     */
    virtual void deleteAction()
    {
        // Override and implement this function in CustomListElement
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Image fon;
    touchgfx::Button deletebt;
    touchgfx::TextAreaWithOneWildcard dayText;
    touchgfx::TextAreaWithOneWildcard hourText;
    touchgfx::TextAreaWithOneWildcard minuteText;
    touchgfx::TextAreaWithOneWildcard tempText;
    touchgfx::TextAreaWithOneWildcard durationLeftText;
    touchgfx::TextAreaWithOneWildcard durationRightText;

    /*
     * Wildcard Buffers
     */
    static const uint16_t DAYTEXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar dayTextBuffer[DAYTEXT_SIZE];
    static const uint16_t HOURTEXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar hourTextBuffer[HOURTEXT_SIZE];
    static const uint16_t MINUTETEXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar minuteTextBuffer[MINUTETEXT_SIZE];
    static const uint16_t TEMPTEXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar tempTextBuffer[TEMPTEXT_SIZE];
    static const uint16_t DURATIONLEFTTEXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar durationLeftTextBuffer[DURATIONLEFTTEXT_SIZE];
    static const uint16_t DURATIONRIGHTTEXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar durationRightTextBuffer[DURATIONRIGHTTEXT_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<CustomListElementBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // CUSTOMLISTELEMENTBASE_HPP