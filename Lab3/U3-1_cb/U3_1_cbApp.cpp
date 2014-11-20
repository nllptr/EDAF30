/***************************************************************
 * Name:      U3_1_cbApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Simon Wessel (simon.w.karlsson@gmail.com)
 * Created:   2014-11-19
 * Copyright: Simon Wessel (nllptr.github.io)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "U3_1_cbApp.h"
#include "U3_1_cbMain.h"

IMPLEMENT_APP(U3_1_cbApp);

bool U3_1_cbApp::OnInit()
{
    U3_1_cbFrame* frame = new U3_1_cbFrame(0L, _("wxWidgets Application Template"));
    
    frame->Show();
    
    return true;
}
