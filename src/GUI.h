#pragma once
#include "MyFrame.h"
#include "BarnsleyFern.h"
#include "Triangle_Sierpinski.h"
#include "Square_Sierpinski.h"
#include "Pentagon_Sierpinski.h"
#include "RecursiveTree.h"
#include "Pentadentrite.h"
#include "GoldenDragon.h"
#include <wx/dcbuffer.h>
#include <cmath>
#include <wx/dc.h>
#include <wx/rawbmp.h>
#include <windows.h>
#include <vector>


class GUI : public MyFrame1{
public:
	GUI() : MyFrame1(NULL),  MyDC(m_panel1){
		panel_sizeX = m_panel1->GetSize().x;
		panel_sizeY = m_panel1->GetSize().y;
		m_fern = new BarnsleyFern(panel_sizeX, panel_sizeY);
		m_sierp_tri = new SierpinskiTriangle(panel_sizeX, panel_sizeY);
		m_sierp_squ = new SierpinskiSquare(panel_sizeX, panel_sizeY);
		m_sierp_pent = new SierpinskiPentagon(panel_sizeX, panel_sizeY);
		m_tree = new RecursiveTree(panel_sizeX, panel_sizeY);
		m_penta = new Pentadentrite(panel_sizeX, panel_sizeY);
		m_dragon = new GoldenDragon(panel_sizeX, panel_sizeY);
		


		Bind(wxEVT_BUTTON, &GUI::Draw, this, 1000);
		Bind(wxEVT_BUTTON, &GUI::Draw, this, 1001);
		Bind(wxEVT_BUTTON, &GUI::Draw, this, 1002);
		Bind(wxEVT_BUTTON, &GUI::Draw, this, 1003);
		Bind(wxEVT_BUTTON, &GUI::Draw, this, 1004);
		Bind(wxEVT_BUTTON, &GUI::Draw, this, 1005);
		Bind(wxEVT_BUTTON, &GUI::Draw, this, 1006);

		Bind(wxEVT_BUTTON, &GUI::Save_to_File, this, 1020);

		Bind(wxEVT_BUTTON, &GUI::Morph_button, this, 1011);

		Bind(wxEVT_BUTTON, &GUI::Reset_button, this, 110);
		Bind(wxEVT_BUTTON, &GUI::Clear, this, 111);

		Bind(wxEVT_SIZE, &GUI::Form_Resize, this);
		
		Bind(wxEVT_TEXT, &GUI::Update_iter,this, 21);
		Bind(wxEVT_TEXT, &GUI::Update_frame, this, 22);

		Bind(wxEVT_CHECKBOX, &GUI::Checkbox, this,101);
		Bind(wxEVT_CHECKBOX, &GUI::Checkbox, this, 102);
		Bind(wxEVT_CHECKBOX, &GUI::Checkbox, this, 103);
		Bind(wxEVT_CHECKBOX, &GUI::Checkbox, this, 104);
		Bind(wxEVT_CHECKBOX, &GUI::Checkbox, this, 105);
		Bind(wxEVT_CHECKBOX, &GUI::Checkbox, this, 106);
		Bind(wxEVT_CHECKBOX, &GUI::Checkbox, this, 107);
		
	}


	~GUI() {
		delete m_fern;
		delete m_sierp_tri;
		delete m_sierp_squ;
		delete m_sierp_pent;
		delete m_tree;
		delete m_penta;
		delete m_dragon;
	}



	void Draw(wxCommandEvent& event);

	void MorphInto_file(Fractal& fracToMorph, const Fractal& finalFrac, int steps);

	void MorphInto(Fractal& fracToMorph,const Fractal& finalFrac,int steps);
	void Checkbox(wxCommandEvent& event);
	void Reset_button(wxCommandEvent& event);
	void Form_Resize(wxSizeEvent & e);
	void Morph_button(wxCommandEvent& event);
	void Clear(wxCommandEvent& event);
	void Reset();

	void Save_to_File(wxCommandEvent& event);

	void Update_iter(wxCommandEvent& event);
	void Update_frame(wxCommandEvent& event);
	
private:
	BarnsleyFern *m_fern;
	SierpinskiTriangle *m_sierp_tri;
	SierpinskiSquare *m_sierp_squ;
	SierpinskiPentagon *m_sierp_pent;
	RecursiveTree *m_tree;
	Pentadentrite *m_penta;
	GoldenDragon *m_dragon;
	int frame_count = 50;
	

	int panel_sizeX;
	int panel_sizeY;
	wxClientDC MyDC;
	int order = 0;
	std::vector<Fractal*> order_tab;
	
	bool wasResize = false;

};

int ilosc_bitmap = 0;

void GUI::Draw(wxCommandEvent& event) {
	if (wasResize) {
		m_fern = new  BarnsleyFern(panel_sizeX, panel_sizeY);
		m_sierp_tri = new  SierpinskiTriangle(panel_sizeX, panel_sizeY);
		m_sierp_squ = new  SierpinskiSquare(panel_sizeX, panel_sizeY);
		m_sierp_pent = new  SierpinskiPentagon(panel_sizeX, panel_sizeY);
		m_tree = new  RecursiveTree(panel_sizeX, panel_sizeY);
		m_penta = new  Pentadentrite(panel_sizeX, panel_sizeY);
		m_dragon = new  GoldenDragon(panel_sizeX, panel_sizeY);
	}
	wasResize = false;
	MyDC.Clear();
	proces->SetLabelText(wxString("                      Processing"));
	MyDC.SetPen(wxPen(*wxRED));
	for (int i = 0; i < ITERATION_MAX; i++) {
		m_gauge1->SetValue(i*(100.0/ITERATION_MAX)+1);
		if(event.GetId()==1000)
			MyDC.DrawPoint(m_fern->m_xy[i].first, m_fern->m_xy[i].second);
		if(event.GetId() == 1001)
			MyDC.DrawPoint(m_sierp_tri->m_xy[i].first, m_sierp_tri->m_xy[i].second);
		if (event.GetId() == 1002)
			MyDC.DrawPoint(m_sierp_squ->m_xy[i].first, m_sierp_squ->m_xy[i].second);
		if (event.GetId() == 1003)
			MyDC.DrawPoint(m_sierp_pent->m_xy[i].first, m_sierp_pent->m_xy[i].second);
		if (event.GetId() == 1004)
			MyDC.DrawPoint(m_tree->m_xy[i].first, m_tree->m_xy[i].second);
		if (event.GetId() == 1005)
			MyDC.DrawPoint(m_penta->m_xy[i].first, m_penta->m_xy[i].second);
		if (event.GetId() == 1006)
			MyDC.DrawPoint(m_dragon->m_xy[i].first, m_dragon->m_xy[i].second);

				
	}
	
	proces->SetLabelText(wxString("Please choose Fractal to generate"));

}


	
void GUI::MorphInto(Fractal& fracToMorph, const Fractal& finalFrac, int steps) {


	std::pair<double, double>* copy = new std::pair<double, double>[ITERATION_MAX];
	std::pair<double, double>* step = new std::pair<double, double>[ITERATION_MAX];
	for (int j = 0; j < ITERATION_MAX; j++) {
		copy[j].first = fracToMorph.m_xy[j].first;
		copy[j].second = fracToMorph.m_xy[j].second;
		step[j].first = (finalFrac.GetX(j) - fracToMorph.GetX(j)) / (steps);
		step[j].second = (finalFrac.GetY(j) - fracToMorph.GetY(j)) / (steps);
	}
	
	wxMemoryDC memdc;
	memdc.SetPen(*wxRED);
	wxImage image;

	for (int iteration = 0; iteration < steps; ++iteration) {
	
		wxBitmap bitmap(panel_sizeX, panel_sizeY);
		memdc.SelectObject(bitmap);

		m_gauge1->SetValue(ilosc_bitmap*(100.0 / (frame_count*(order - 1))) + 4);
		ilosc_bitmap++;
		
		for (int j = 1; j <ITERATION_MAX; j+=4) {

			copy[j].first += step[j].first;
			copy[j].second += step[j].second;
			memdc.DrawPoint(copy[j].first, copy[j].second);
			
			}
			memdc.SelectObject(wxNullBitmap);
			image = bitmap.ConvertToImage();

			bitmap=wxBitmap(image);

	
			
			MyDC.DrawBitmap(bitmap,0,0);


		}
	

	}


void GUI::Form_Resize(wxSizeEvent & e)
{
	wasResize = true;
	Layout();
	MyDC.Clear();
	Reset();
	panel_sizeX = m_panel1->GetSize().x;
	panel_sizeY = m_panel1->GetSize().y;

	}
	




void GUI::Checkbox(wxCommandEvent& event) {
	if (event.IsChecked()) {
		if (event.GetId() == 101) { m_checkBox1->Disable(); m_checkBox1->SetLabelText(wxString(std::to_string(++order))); m_fern = new  BarnsleyFern(panel_sizeX, panel_sizeY); order_tab.push_back(m_fern); }
		if (event.GetId() == 102) {
			m_checkBox2->Disable(); m_checkBox2->SetLabelText(wxString(std::to_string(++order))); m_sierp_tri = new  SierpinskiTriangle(panel_sizeX, panel_sizeY); order_tab.push_back(m_sierp_tri);
			}
			if (event.GetId() == 103) {
				m_checkBox3->Disable(); m_checkBox3->SetLabelText(wxString(std::to_string(++order))); m_sierp_squ = new  SierpinskiSquare(panel_sizeX, panel_sizeY);  order_tab.push_back(m_sierp_squ);
			}
			if (event.GetId() == 104) {
				m_checkBox4->Disable(); m_checkBox4->SetLabelText(wxString(std::to_string(++order))); m_sierp_pent = new  SierpinskiPentagon(panel_sizeX, panel_sizeY); order_tab.push_back(m_sierp_pent);
			}
			if (event.GetId() == 105) {
				m_checkBox5->Disable(); m_checkBox5->SetLabelText(wxString(std::to_string(++order))); m_tree = new  RecursiveTree(panel_sizeX, panel_sizeY); order_tab.push_back(m_tree);
			}
			if (event.GetId() == 106) {
				m_checkBox6->Disable(); m_checkBox6->SetLabelText(wxString(std::to_string(++order))); m_penta = new  Pentadentrite(panel_sizeX, panel_sizeY);  order_tab.push_back(m_penta);
			}
			if (event.GetId() == 107) { m_checkBox7->Disable(); m_checkBox7->SetLabelText(wxString(std::to_string(++order))); m_dragon = new GoldenDragon(panel_sizeX, panel_sizeY); order_tab.push_back(m_dragon);
			}
	}

		
}

void GUI::Reset_button(wxCommandEvent& event) {
	Reset();
}


void GUI::Morph_button(wxCommandEvent& event) {
	m_gauge1->SetValue(0);
	if(ITERATION_MAX>=100000) proces->SetLabelText(wxString("       To morphing in real time,\n please type iterations < 100000"));
	else {
		proces->SetLabelText(wxString("         Morphing ...   Please wait"));
		if (order > 1) {
			for (int i = 0; i < order - 1; i++) {
				MorphInto(*order_tab.at(i), *order_tab.at(i + 1), frame_count);
				Sleep(500);

			}
		}
		ilosc_bitmap = 0;
		proces->SetLabelText(wxString("Please choose Fractal to generate"));
	}
}
void GUI::Clear(wxCommandEvent& event) {
	MyDC.Clear();
}


void GUI::Reset() {
	m_gauge1->SetValue(0);
	m_checkBox1->Enable();
	m_checkBox2->Enable();
	m_checkBox3->Enable();
	m_checkBox4->Enable();
	m_checkBox5->Enable();
	m_checkBox6->Enable();
	m_checkBox7->Enable();
	m_checkBox1->SetValue(false);
	m_checkBox2->SetValue(false);
	m_checkBox3->SetValue(false);
	m_checkBox4->SetValue(false);
	m_checkBox5->SetValue(false);
	m_checkBox6->SetValue(false);
	m_checkBox7->SetValue(false);
	order = 0;
	m_checkBox1->SetLabelText(wxString("-"));
	m_checkBox2->SetLabelText(wxString("-"));
	m_checkBox3->SetLabelText(wxString("-"));
	m_checkBox4->SetLabelText(wxString("-"));
	m_checkBox5->SetLabelText(wxString("-"));
	m_checkBox6->SetLabelText(wxString("-"));
	m_checkBox7->SetLabelText(wxString("-"));
	order_tab.clear();

}


void GUI::Update_iter(wxCommandEvent& event){
	
	if (m_textCtrl2->GetValue().IsNumber() && wxAtoi(m_textCtrl2->GetValue()) != 0) {
		wasResize = true;
		m_staticText4->SetLabel("");
		Reset();
		long int new_iter = wxAtoi(m_textCtrl2->GetValue());
		ITERATION_MAX = new_iter;
}
	else
		m_staticText4->SetLabel("                Please write a number !!!");
}

void GUI::Update_frame(wxCommandEvent& event) {
	
	if (m_textCtrl4->GetValue().IsNumber() && m_textCtrl4 && wxAtoi(m_textCtrl4->GetValue())!=0) {
		m_staticText4->SetLabel("");
		Reset();
		frame_count = wxAtoi(m_textCtrl4->GetValue());
	}
	else
		m_staticText4->SetLabel("                Please write a number !!!");
	
}

void GUI::Save_to_File(wxCommandEvent& event) {
	m_gauge1->SetValue(0);
	proces->SetLabelText(wxString("   Saving to File ... Please wait"));
	if (order > 1) {
		for (int i = 0; i < order - 1; i++) {
			MorphInto_file(*order_tab.at(i), *order_tab.at(i + 1), frame_count);
			Sleep(500);

		}
	}
	ilosc_bitmap = 0;
	proces->SetLabelText(wxString("Please choose Fractal to generate"));


}




void GUI::MorphInto_file(Fractal& fracToMorph, const Fractal& finalFrac, int steps) {

	std::pair<double, double>* copy = new std::pair<double, double>[ITERATION_MAX];
	std::pair<double, double>* step = new std::pair<double, double>[ITERATION_MAX];
	for (int j = 0; j < ITERATION_MAX; j++) {
		copy[j].first = fracToMorph.m_xy[j].first;
		copy[j].second = fracToMorph.m_xy[j].second;
		step[j].first = (finalFrac.GetX(j) - fracToMorph.GetX(j)) / (steps);
		step[j].second = (finalFrac.GetY(j) - fracToMorph.GetY(j)) / (steps);
	}

	wxMemoryDC memdc;
	memdc.SetPen(*wxRED);
	wxImage image;

	image.AddHandler(new wxBMPHandler);
	for (int iteration = 0; iteration < steps+1; ++iteration) {
	
		wxBitmap bitmap(panel_sizeX, panel_sizeY);
		memdc.SelectObject(bitmap);
		

		for (int j = 1; j < ITERATION_MAX; j++) {
			if(iteration==0){ 
				memdc.DrawPoint(copy[j].first, copy[j].second); }
			else {
				copy[j].first += step[j].first;
				copy[j].second += step[j].second;
				memdc.DrawPoint(copy[j].first, copy[j].second);
			}
		}

		m_gauge1->SetValue(ilosc_bitmap*(100.0 / (frame_count*(order - 1)))+1);

		memdc.SelectObject(wxNullBitmap);
		image = bitmap.ConvertToImage();
		
		ilosc_bitmap++;
		wxString mystring;
		mystring << ilosc_bitmap;
		if(iteration<10)
		image.SaveFile("000" + mystring + ".bmp", wxBITMAP_TYPE_BMP);
		else if(iteration<100)
			image.SaveFile("00" + mystring + ".bmp", wxBITMAP_TYPE_BMP);
		else if (iteration < 1000)
			image.SaveFile("0" + mystring + ".bmp", wxBITMAP_TYPE_BMP);



	}
	

}
