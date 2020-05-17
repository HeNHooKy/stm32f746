/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef LISTTABLEBASE_HPP
#define LISTTABLEBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class ListTableBase : public touchgfx::Container
{
public:
    ListTableBase();
    virtual ~ListTableBase() {}
    virtual void initialize();

    /*
     * Virtual Action Handlers
     */
    virtual void deleteAction()
    {
        // Override and implement this function in ListTable
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
    touchgfx::TextAreaWithOneWildcard list;

    /*
     * Wildcard Buffers
     */
    static const uint16_t LIST_SIZE = 64;
    touchgfx::Unicode::UnicodeChar listBuffer[LIST_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<ListTableBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // LISTTABLEBASE_HPP