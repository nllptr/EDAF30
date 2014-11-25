// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
   #include <wx/wx.h>
#endif

#include "BricksData.h"
#include "BricksPanel.h"

class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

class BricksPanel;

class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void SetupMenuBar();
    void CreatePanelItems();
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    BricksPanel *panel;
	BricksData model;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame( "15 Puzzle", wxPoint(50, 50), wxSize(450, 340) );
    frame->Show( true );
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    SetupMenuBar();
    CreatePanelItems();
    CreateStatusBar();
    SetStatusText( "Wlecome to the 15 Puzzle!" );
}

void MyFrame::SetupMenuBar()
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MyFrame::OnExit, this, wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MyFrame::OnAbout, this, wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
}

void MyFrame::CreatePanelItems()
{
    panel = new BricksPanel(this, model);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is the 15 Puzzle using wxWidgets",
                  "About the 15 Puzzle", wxOK | wxICON_INFORMATION );
}



