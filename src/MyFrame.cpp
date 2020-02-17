///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MyFrame.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 400,560 ), wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel1->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );
	m_panel1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	
	bSizer2->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer1->Add( bSizer2, 20, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	Barnsley_Fern = new wxButton( this, 1000, wxT("Barnsley Fern"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( Barnsley_Fern, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	Sierpinski_tri = new wxButton( this, 1001, wxT("Sierpinski Triangle"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( Sierpinski_tri, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	Sierpinski_square = new wxButton( this, 1002, wxT("Sierpinski Square"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( Sierpinski_square, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	Sierpinski_penta = new wxButton( this, 1003, wxT("Sierpinski Pentagon"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( Sierpinski_penta, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	tree = new wxButton( this, 1004, wxT("Recursive Tree"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( tree, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	penta = new wxButton( this, 1005, wxT("Pentadentrite"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( penta, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	dragon = new wxButton( this, 1006, wxT("Golden Dragon"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( dragon, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	m_gauge1 = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	m_gauge1->SetValue( 0 ); 
	bSizer4->Add( m_gauge1, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	proces = new wxStaticText( this, wxID_ANY, wxT("Please choose Fractal to generate\n"), wxDefaultPosition, wxDefaultSize, 0 );
	proces->Wrap( -1 );
	bSizer4->Add( proces, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("          If you want to morph \nplease select more than one Fractal\n    by clicking on the Check-box "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer4->Add( m_staticText3, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizer4->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer4->Add( m_staticText4, 0, wxALL, 5 );
	
	m_textCtrl2 = new wxTextCtrl( this, 21, wxT("               Iterations = 30000"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_textCtrl2, 0, wxALL|wxEXPAND, 5 );
	
	m_button11 = new wxButton( this, 1020, wxT("Save to File"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button11, 0, wxALL|wxEXPAND, 5 );
	
	m_morph = new wxButton( this, 1011, wxT("Let's Morph !"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_morph, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer4, 5, wxEXPAND, 17 );
	
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );
	
	m_checkBox1 = new wxCheckBox( this, 101, wxT("-"), wxDefaultPosition, wxSize( -1,30 ), 0 );
	bSizer41->Add( m_checkBox1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_checkBox2 = new wxCheckBox( this, 102, wxT("-"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	bSizer41->Add( m_checkBox2, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_checkBox3 = new wxCheckBox( this, 103, wxT("-"), wxDefaultPosition, wxSize( -1,30 ), 0 );
	bSizer41->Add( m_checkBox3, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_checkBox4 = new wxCheckBox( this, 104, wxT("-"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	bSizer41->Add( m_checkBox4, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_checkBox5 = new wxCheckBox( this, 105, wxT("-"), wxDefaultPosition, wxSize( -1,30 ), 0 );
	bSizer41->Add( m_checkBox5, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_checkBox6 = new wxCheckBox( this, 106, wxT("-"), wxDefaultPosition, wxSize( -1,30 ), 0 );
	bSizer41->Add( m_checkBox6, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_checkBox7 = new wxCheckBox( this, 107, wxT("-"), wxDefaultPosition, wxSize( -1,20 ), 0 );
	bSizer41->Add( m_checkBox7, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_button8 = new wxButton( this, 110, wxT("Reset"), wxPoint( -1,-1 ), wxSize( 50,-1 ), 0 );
	bSizer41->Add( m_button8, 0, wxALIGN_CENTER, 5 );
	
	
	bSizer41->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_textCtrl4 = new wxTextCtrl( this, 22, wxT(" Frame"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	m_textCtrl4->SetMinSize( wxSize( 50,-1 ) );
	m_textCtrl4->SetMaxSize( wxSize( 50,-1 ) );
	
	bSizer41->Add( m_textCtrl4, 0, wxALL|wxFIXED_MINSIZE, 5 );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("max 100"), wxDefaultPosition, wxSize( -1,30 ), 0 );
	m_staticText31->Wrap( -1 );
	m_staticText31->SetMinSize( wxSize( -1,30 ) );
	m_staticText31->SetMaxSize( wxSize( -1,30 ) );
	
	bSizer41->Add( m_staticText31, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_button9 = new wxButton( this, 111, wxT("Clear"), wxPoint( -1,-1 ), wxSize( 50,-1 ), 0 );
	m_button9->SetMinSize( wxSize( 50,-1 ) );
	m_button9->SetMaxSize( wxSize( 50,-1 ) );
	
	bSizer41->Add( m_button9, 0, wxALL|wxEXPAND, 4 );
	
	
	bSizer1->Add( bSizer41, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

MyFrame1::~MyFrame1()
{
}
