#include "ImageFilter.hpp"
#include <wx/statline.h>

constexpr static int const BORDER = 5;

wxBEGIN_EVENT_TABLE(ImageFilter, wxDialog)
    EVT_BUTTON(ID::SEARCH, ImageFilter::onClickSearch)
    EVT_SLIDER(ID::BRSLIDER, ImageFilter::onMoveSlider)
    EVT_BUTTON(ID::CANCEL, ImageFilter::onClickCancel)
    EVT_CLOSE(ImageFilter::onClose)
wxEND_EVENT_TABLE()
ImageFilter::ImageFilter()
            : wxDialog(nullptr, wxID_ANY, wxT("IMAGE FILTER"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxSTAY_ON_TOP)
{
    wxBoxSizer * vsizer = new wxBoxSizer(wxVERTICAL);

    vsizer->Add(createSearchZone(this), 0, wxEXPAND | wxALL, BORDER);
    vsizer->AddSpacer(5);
    vsizer->Add(createButtonZone(this), 0, wxALL, BORDER);
    vsizer->AddSpacer(5);
    vsizer->Add(createBrightnessZone(this), 0, wxEXPAND | wxALL, BORDER);
    vsizer->AddSpacer(5);
    vsizer->Add(new wxStaticLine(this, wxID_ANY), 0, wxEXPAND | wxALL, BORDER);
    vsizer->Add(createCancelOkZone(this), 0, wxALIGN_RIGHT | wxALL, BORDER);

    SetSizerAndFit(vsizer);
}

ImageFilter::~ImageFilter()
{
    // empty.
}

wxPanel * ImageFilter::createSearchZone(wxWindow * parent)
{
    wxPanel * search_panel = new wxPanel(parent, wxID_ANY);
    wxBoxSizer * hsizer = new wxBoxSizer(wxHORIZONTAL);
    _search_btn = new wxButton(search_panel, ID::SEARCH, wxT("search"));
    _path_txt   = new wxTextCtrl(search_panel, ID::PATH);
    hsizer->Add(_search_btn);
    hsizer->AddSpacer(5);
    hsizer->Add(_path_txt, 1);

    search_panel->SetSizer(hsizer);

    return search_panel;
}

wxPanel * ImageFilter::createBrightnessZone(wxWindow * parent)
{
    wxPanel * br_panel = new wxPanel(parent, wxID_ANY);
    wxBoxSizer * hsizer = new wxBoxSizer(wxHORIZONTAL);
    _brightness_sld = new wxSlider(br_panel, ID::BRSLIDER, 5, 0, 10);
    _brightness_txt   = new wxTextCtrl(br_panel, ID::PATH, std::to_string(_brightness_sld->GetValue()));
    hsizer->Add(_brightness_sld, 1);
    hsizer->AddSpacer(5);
    hsizer->Add(_brightness_txt, 1);

    br_panel->SetSizer(hsizer);

    return br_panel;
}

wxPanel * ImageFilter::createButtonZone(wxWindow * parent)
{
    wxPanel * btn_panel = new wxPanel(parent, wxID_ANY);
    wxBoxSizer * hsizer = new wxBoxSizer(wxHORIZONTAL);
    _change_gray_btn = new wxButton(btn_panel, ID::GRAY, wxT("gray"));
    _more_btn = new wxButton(btn_panel, ID::MORE, wxT("more"));
    _less_btn = new wxButton(btn_panel, ID::LESS, wxT("less"));
    _clear_btn = new wxButton(btn_panel, ID::CLEAR, wxT("clear"));
    hsizer->Add(_change_gray_btn);
    hsizer->AddSpacer(5);
    hsizer->Add(_more_btn);
    hsizer->AddSpacer(5);
    hsizer->Add(_less_btn);
    hsizer->AddSpacer(5);
    hsizer->Add(_clear_btn);

    btn_panel->SetSizer(hsizer);

    return btn_panel;
}

wxPanel * ImageFilter::createCancelOkZone(wxWindow * parent)
{
    wxPanel * final_panel = new wxPanel(parent, wxID_ANY);
    wxBoxSizer * hsizer = new wxBoxSizer(wxHORIZONTAL);
    _cancel = new wxButton(final_panel, ID::CANCEL, wxT("cancel"));
    _ok = new wxButton(final_panel, ID::OK, wxT("ok"));
    hsizer->Add(_cancel);
    hsizer->AddSpacer(5);
    hsizer->Add(_ok);

    final_panel->SetSizer(hsizer);

    return final_panel;
}

void ImageFilter::onClickSearch(wxCommandEvent & event)
{
    wxFileDialog * fdialog = new wxFileDialog(this);
    if (fdialog->ShowModal() == wxID_OK) {
        wxString filename = fdialog->GetPath();
        _path_txt->SetValue(filename);
    }
}

void ImageFilter::onMoveSlider(wxCommandEvent & event)
{
    _brightness_txt->SetValue(std::to_string(_brightness_sld->GetValue()));
}

void ImageFilter::onClickCancel(wxCommandEvent & event)
{
    this->Close();
}

void ImageFilter::onClose(wxCloseEvent & event)
{
    int result = wxMessageBox(wxT("Do you want to close?"), wxT("EXIT"), wxYES_NO);
    if (result == wxYES) {
        exit(0);
    } else {
        event.Veto();
    }
}