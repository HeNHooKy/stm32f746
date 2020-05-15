#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "UartController.h"
#include "configuration.h"




extern int data;
unsigned int answer = 0;
int status = 0;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	modelListener->uartMsgRdy(status);
}

void Model::SendLeftTemp(int value)
{
	UC_SEND(SET_M, GROUP_M, ADDRESS_MANUAL_MODE_RIGHT, UC_SET, &answer, &status);
}

