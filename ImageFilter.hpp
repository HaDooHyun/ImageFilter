#ifndef IMAGEFILTER_IMAGEFILTER_HPP
#define IMAGEFILTER_IMAGEFILTER_HPP

#include <wx/wx.h>

class ImageFilter : public wxDialog
{
public:
    wxDECLARE_EVENT_TABLE();

public:
    enum ID {
        SEARCH,
        PATH,
        GRAY,
        MORE,
        LESS,
        CLEAR,
        BRSLIDER,
        BRTEXT,
        CANCEL,
        OK
    };

private:
    wxButton * _search_btn;
    wxTextCtrl * _path_txt;

    wxSlider * _brightness_sld;
    wxTextCtrl * _brightness_txt;

    wxButton * _change_gray_btn;
    wxButton * _more_btn;
    wxButton * _less_btn;
    wxButton * _clear_btn;

    wxButton * _cancel;
    wxButton * _ok;
//    wxPanel  * _view_panel;

public:
    ImageFilter();
    ~ImageFilter();

public:
    wxPanel * createSearchZone(wxWindow * parent);
    wxPanel * createButtonZone(wxWindow * parent);
    wxPanel * createBrightnessZone(wxWindow * parent);
    wxPanel * createCancelOkZone(wxWindow * parent);

public:
    void onClickSearch(wxCommandEvent & event);
    void onMoveSlider(wxCommandEvent & event);
    void onClickCancel(wxCommandEvent & event);
    void onClose(wxCloseEvent & event);
};

#endif //IMAGEFILTER_IMAGEFILTER_HPP