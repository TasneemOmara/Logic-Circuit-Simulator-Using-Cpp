#include "AND2.h"

AND2::AND2(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut, "AND")
{
}


void AND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	STATUS n0, n1;

	n0 = m_InputPins[0].getStatus();
	n1 = m_InputPins[1].getStatus();



	if (n0 == 1 && n1 == 1)
	{
		m_OutputPin.setStatus(HIGH);
		is_full_connect = true;

	}
	else if (n0 == 2 || n1 == 2) {
		m_OutputPin.setStatus(NCON);
		is_full_connect = false;
	}
	else {
		m_OutputPin.setStatus(LOW);
		is_full_connect = true;

	}
}

	//Add you code here
	/*
	for (int i = 0; i < m_Inputs; i++)
	{	
	}*/



// Function Draw
// Draws 2-input AND gate
void AND2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawAND2(*m_pGfxInfo, is_selected);
}

//returns status of outputpin
int AND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}


void AND2::SaveComponent(fstream& fileToSave)
{
	fileToSave << "AND2" << "   " << this->getID() << "   " << m_Label << "   " << m_pGfxInfo->PointsList[0].x << "   "
		<< m_pGfxInfo->PointsList[0].y << "   " << m_pGfxInfo->PointsList[1].x << "   " << m_pGfxInfo->PointsList[1].y << endl;
}
