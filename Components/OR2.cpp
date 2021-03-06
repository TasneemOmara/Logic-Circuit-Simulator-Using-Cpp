#include "OR2.h"

OR2::OR2(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut, "OR2")
{
}


void OR2::Operate()
{
	//caclulate the output status as the ORing of the two input pins
	STATUS n0, n1;
	n0 = m_InputPins[0].getStatus();
	n1 = m_InputPins[1].getStatus();

	if (n0 == 0 && n1 == 0)
	{
		m_OutputPin.setStatus(LOW);
		is_full_connect = true;
	}

	else if (n0 == 2 || n1 == 2)
	{
		m_OutputPin.setStatus(NCON);
		is_full_connect = false;
	}
	else {
		m_OutputPin.setStatus(HIGH);
		is_full_connect = true;
	}
	//Add you code here
}


// Function Draw
// Draws 2-input OR gate
void OR2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawOR2(*m_pGfxInfo, is_selected);
}

//returns status of outputpin
int OR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}


void OR2::SaveComponent(fstream& fileToSave)
{
	fileToSave << "OR2" << "   " << this->getID() << "   " << m_Label << "   " << m_pGfxInfo->PointsList[0].x << "   "
		<< m_pGfxInfo->PointsList[0].y << "   " << m_pGfxInfo->PointsList[1].x << "   " << m_pGfxInfo->PointsList[1].y << endl;
}
