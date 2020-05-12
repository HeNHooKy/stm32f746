#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "UartController.h"

Model::Model() : modelListener(0)
{

}

void Model::tick()
{

}

void Model::SendLeftTemp(int value)
{
	UC_GX_SEND_Decimical_2(value, leftTempAddress, 16);
}
