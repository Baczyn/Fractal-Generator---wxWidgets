#include <wx/wx.h>
#include <memory>
#include "GUI.h"

class MyApp : public wxApp {

public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	GUI *frame = new GUI();
	frame->Show(true);
	SetTopWindow(frame);
	return true;
}
