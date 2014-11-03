// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
   #include <wx/wx.h>
#endif

class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};
class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void SetupMenuBar();
    void DrawTurtle();
    void OnPaint(wxPaintEvent& event);
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};
class Turtle
{
public:
    Turtle(wxFrame* frame) : m_frame(frame), m_x(0), m_y(0), m_dir(0.0) {}
    void MoveTo(int x, int y);
    void LineTo(int x, int y);
    void Perform();
private:
    wxFrame* m_frame;
    int m_x;
    int m_y;
    double m_dir;
};

enum
{
    ID_Hello = 1
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
   EVT_PAINT  (MyFrame::OnPaint)
   EVT_MENU(ID_Hello, MyFrame::OnHello)
   EVT_MENU(wxID_EXIT, MyFrame::OnExit)
   EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame( "Hello World", wxPoint(50, 50), wxSize(450, 340) );
    frame->Show( true );
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    SetBackgroundColour(*wxWHITE);
    SetupMenuBar();
    CreateStatusBar();
    SetStatusText( "Welcome to wxWidgets!" );
}

void MyFrame::SetupMenuBar()
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
}

void MyFrame::DrawTurtle()
{
    Turtle turtle(this);
    turtle.Perform();
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void MyFrame::OnPaint(wxPaintEvent& event)
{
    DrawTurtle();
}


void Turtle::MoveTo(int x, int y)
{
    m_x = x;
    m_y = y;
}

void Turtle::LineTo(int x, int y)
{
    wxPaintDC dc(m_frame);
    dc.SetPen(*wxBLACK_PEN);
    dc.DrawLine(m_x, x, m_y, y);
    MoveTo(x, y);
}


void Turtle::Perform()
{
    const int origX = 100;
    const int sizeX = 100;
    const int origY = 100;
    const int sizeY = 100;
    MoveTo(origX, origY);
    LineTo(origX + sizeX, origY);
    LineTo(origX + sizeX, origY + sizeY);
    LineTo(origX, origY + sizeY);
    LineTo(origX, origY);
}
