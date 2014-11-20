#ifndef BRICKSPANEL_H
#define BRICKSPANEL_H

#include <vector>

class BricksData;

// window id's for handling of bricks and buttons events
const int ID_Bricks_Start = 10000; // First window id for the bricks
const int ID_Bricks_End = ID_Bricks_Start + 15; // Last window id for the bricks

const int ID_Buttons_Start = ID_Bricks_End + 1;
const int ID_Check   = ID_Buttons_Start + 1;
const int ID_Shuffle = ID_Buttons_Start + 2;
const int ID_Reset   = ID_Buttons_Start + 3;
const int ID_Close   = ID_Buttons_Start + 4;


class BricksPanel: public wxPanel
{
public:
    BricksPanel(wxFrame *parent, BricksData &data);
private:
    void CreateBricks();
    wxStaticBitmap *CreateBrick(wxPanel *panel, int nbr, int row, int col);
	void PositionBricks();
	void MoveBrick(const int brickNbr, const int ms = 200, const int steps = sz);
    void OnLeftUp(wxMouseEvent& event);
	void OnCheck(wxCommandEvent& WXUNUSED(event));
	void OnShuffle(wxCommandEvent& WXUNUSED(event));
	void OnReset(wxCommandEvent& WXUNUSED(event));
	void OnClose(wxCommandEvent& WXUNUSED(event));
    wxStaticBitmap *m_brick[16]; // index by brick number, position 0 empty
    static const int sz = 50;

	BricksData &model;
};


#endif // BRICKSPANEL_H
