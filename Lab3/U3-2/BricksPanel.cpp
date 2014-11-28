#include <wx/wxprec.h>
#ifndef WX_PRECOMP
   #include <wx/wx.h>
#endif

#include "BricksPanel.h"
#include "BricksData.h"

BricksPanel::BricksPanel(wxFrame *parent, BricksData &data)
    : wxPanel(parent, wxID_ANY), model(data)
{
    CreateBricks();
	PositionBricks();
}

void BricksPanel::CreateBricks()
{
	// sizers for the layout of bricks and buttons
	wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);	// overall layout
	wxBoxSizer *vbox1 = new wxBoxSizer(wxVERTICAL);		// bricks
	wxBoxSizer *vbox2 = new wxBoxSizer(wxVERTICAL);		// button commands

	// an anonymous background panel with numbered bricks
	wxPanel *panel1 = new wxPanel(this, -1);
	m_brick[0] = nullptr;
    for (int i = 0; i < 15; i++) {
        m_brick[i+1] = CreateBrick(panel1, i+1, i/4, i%4);
		// install an event handler for "clicks" on a brick
        m_brick[i+1]->Bind(wxEVT_LEFT_UP, &BricksPanel::OnLeftUp, this);
    }

	// buttons commands
	// Check command
	wxButton *btn1 = new wxButton(this, ID_Check, wxT("Check"));
    btn1->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BricksPanel::OnCheck, this);
	// Shuffle command
	wxButton *btn2 = new wxButton(this, ID_Shuffle, wxT("Shuffle"));
    btn2->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BricksPanel::OnShuffle, this);
	// Reset command
	wxButton *btn3 = new wxButton(this, ID_Reset, wxT("Reset"));
    btn3->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BricksPanel::OnReset, this);
	// Close command
	wxButton *btn4 = new wxButton(this, ID_Close, wxT("Close"));
    btn4->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &BricksPanel::OnClose, this);

	vbox1->Add(panel1, 1, wxEXPAND);
	hbox->Add(vbox1, 0, wxALIGN_RIGHT | wxALL, 20);

	vbox2->Add(btn1, 1, wxEXPAND);
	vbox2->Add(btn2, 1, wxEXPAND);
	vbox2->Add(btn3, 1, wxEXPAND);
	vbox2->Add(btn4, 1, wxEXPAND);
	hbox->Add(vbox2, 0, wxALIGN_RIGHT | wxALL, 20);

	SetSizer(hbox);

}

void BricksPanel::PositionBricks()
{
	std::vector<int> bPos;
	model.Positions(bPos);
	if (bPos.size() != 16) {
		wxLogStatus(wxT("Positions returned %d bricks"), bPos.size());
		return;
	}
    for (int i = 0; i < 16; i++) {
		wxStaticBitmap *brick = m_brick[bPos[i]];
		if (brick != nullptr)
			brick->Move((i%4)*sz, (i/4)*sz);  // col, row
    }
	Refresh();
}

wxStaticBitmap *BricksPanel::CreateBrick(wxPanel *panel, int nbr, int row, int col)
{
    wxBitmap bitmap = wxBitmap(sz, sz);
    wxMemoryDC memDC;
    memDC.SelectObject(bitmap);
    memDC.SetPen(*wxWHITE_PEN);
    memDC.SetBrush(*wxLIGHT_GREY_BRUSH);  // Parent windows background color
    memDC.DrawRectangle(0, 0, sz, sz);
    memDC.SetPen(*wxBLACK_PEN);
    memDC.SetBrush(*wxWHITE_BRUSH);
    memDC.DrawRoundedRectangle(1, 1, sz-2, sz-2, 6);
    wxString str = wxString::Format(wxT("%d"), nbr);
    wxSize ext = memDC.GetTextExtent(str);
    memDC.DrawText(str, (sz - ext.GetWidth()) / 2, (sz - ext.GetHeight()) / 2);
    return new wxStaticBitmap(panel, ID_Bricks_Start+nbr, bitmap, wxPoint(col*sz,row*sz), wxSize(sz,sz));
}

void BricksPanel::OnLeftUp(wxMouseEvent &event)
{
    wxStaticBitmap *brick = dynamic_cast<wxStaticBitmap*> (event.GetEventObject());
    int id = event.GetId();
    if ((brick != nullptr) && (brick->GetId() == id)) {
        MoveBrick(id - ID_Bricks_Start);
    }
}

void BricksPanel::OnCheck(wxCommandEvent& WXUNUSED(event))
{
	if (model.Check())
		wxLogMessage(wxT("Solved"));
	else
		wxLogMessage(wxT("Not solved"));
}

void BricksPanel::OnShuffle(wxCommandEvent& WXUNUSED(event))
{
	model.Shuffle();
	PositionBricks();
}

void BricksPanel::OnReset(wxCommandEvent& WXUNUSED(event))
{
	model.Reset();
	PositionBricks();
}

void BricksPanel::OnClose(wxCommandEvent& WXUNUSED(event))
{
	GetParent()->Close(true);
}

void BricksPanel::MoveBrick(const int brickNbr, const int ms, const int steps)
{
	std::vector<int> brickList;
	BricksData::Movement moveDir = model.Move(brickNbr, brickList);
	if (moveDir != BricksData::None) {
		wxLogStatus(wxT("Move brick %d OK"), brickNbr);
		int nbrBricks = brickList.size();
		if (nbrBricks > 0) {
			wxStaticBitmap *brick = m_brick[brickList[0]];
			wxPoint start = brick->GetPosition();
			wxPoint dir(((0<moveDir)-(moveDir<0))*(abs(moveDir)%4), moveDir / 4);
			wxPoint inc(dir.x * sz / steps, dir.y * sz / steps);
			start = brick->GetPosition();
			for (int i = 1; i < steps; i++) {
				for (int j = 0; j < nbrBricks; j++) {
					brick = m_brick[brickList[j]];
					brick->Move(start - (dir * j * sz) + dir * (i * sz / steps));
				}
				wxMilliSleep(ms/steps);
			}
			for (int j = 0; j < nbrBricks; j++) {
				brick = m_brick[brickList[j]];
				brick->Move(start - (dir * j * sz) + dir * sz);
			}
		}
	}
	else {
		wxLogStatus(wxT("Move brick %d not OK"), brickNbr);
	}
}

