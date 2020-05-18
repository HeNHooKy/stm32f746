#include <gui/containers/MsgBox.hpp>
#include "configuration.h"

MsgBox::MsgBox()
{

}

void MsgBox::initialize()
{
    MsgBoxBase::initialize();
}

void MsgBox::Show(int num)
{
	switch(num)
	{
	case 1:
		Unicode::strncpy(messageBuffer, text1.getError1Buf(), MSG_SIZE - 1);
		break;
	case 2:
		Unicode::strncpy(messageBuffer, text1.getError2Buf(), MSG_SIZE - 1);
		break;
	case 3:
		Unicode::strncpy(messageBuffer, text1.getError3Buf(), MSG_SIZE - 1);
		break;
	case 4:
		Unicode::strncpy(messageBuffer, text1.getError4Buf(), MSG_SIZE - 1);
		break;
	}
	message.invalidate();
}

void MsgBox::CloseMessage()
{
	this->setVisible(false);
	this->invalidate();
}
