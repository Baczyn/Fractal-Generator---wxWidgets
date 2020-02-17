///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MYFRAME_H__
#define __MYFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/gauge.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/valgen.h>
#include <wx/checkbox.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel1;
		wxButton* Barnsley_Fern;
		wxButton* Sierpinski_tri;
		wxButton* Sierpinski_square;
		wxButton* Sierpinski_penta;
		wxButton* tree;
		wxButton* penta;
		wxButton* dragon;
		wxGauge* m_gauge1;
		wxStaticText* proces;
		wxStaticText* m_staticText3;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textCtrl2;
		wxButton* m_button11;
		wxButton* m_morph;
		wxCheckBox* m_checkBox1;
		wxCheckBox* m_checkBox2;
		wxCheckBox* m_checkBox3;
		wxCheckBox* m_checkBox4;
		wxCheckBox* m_checkBox5;
		wxCheckBox* m_checkBox6;
		wxCheckBox* m_checkBox7;
		wxButton* m_button8;
		wxTextCtrl* m_textCtrl4;
		wxStaticText* m_staticText31;
		wxButton* m_button9;
	
	public:
		
		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 900,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrame1();
	
};

#endif //__MYFRAME_H__
