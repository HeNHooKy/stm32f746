#include <gui/containers/MsgBox.hpp>
#include "configuration.h"

MsgBox::MsgBox()
{

}

void MsgBox::initialize()
{
    MsgBoxBase::initialize();
}

void MsgBox::Show(char* m)
{
	Unicode::strncpy(messageBuffer, m, MSG_SIZE - 1);
	message.invalidate();
}

void MsgBox::CloseMessage()
{
	this->setVisible(false);
	this->invalidate();
}
