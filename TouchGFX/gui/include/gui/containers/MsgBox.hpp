#ifndef MSGBOX_HPP
#define MSGBOX_HPP

#include <gui_generated/containers/MsgBoxBase.hpp>

class MsgBox : public MsgBoxBase
{
public:
    MsgBox();
    virtual ~MsgBox() {}

    virtual void initialize();
    virtual void Show(char* m);
    virtual void CloseMessage();
protected:
};

#endif // MSGBOX_HPP
