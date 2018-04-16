#include <wx/wx.h>
#include "ImageFilter.hpp"
#include "ImageFilterApp.hpp"

wxIMPLEMENT_WX_THEME_SUPPORT;
IMPLEMENT_APP_NO_MAIN(ImageFilterApp)

int main(int argc, char ** argv)
{
    wxDISABLE_DEBUG_SUPPORT();
    return wxEntry(argc, argv);
}
