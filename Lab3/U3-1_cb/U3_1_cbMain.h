/***************************************************************
 * Name:      U3_1_cbMain.h
 * Purpose:   Defines Application Frame
 * Author:    Simon Wessel (simon.w.karlsson@gmail.com)
 * Created:   2014-11-19
 * Copyright: Simon Wessel (nllptr.github.io)
 * License:
 **************************************************************/

#ifndef U3_1_CBMAIN_H
#define U3_1_CBMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "U3_1_cbApp.h"

class U3_1_cbFrame: public wxFrame
{
    public:
        U3_1_cbFrame(wxFrame *frame, const wxString& title);
        ~U3_1_cbFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // U3_1_CBMAIN_H
