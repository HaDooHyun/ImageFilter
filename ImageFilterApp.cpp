//
// Created by hadoo on 18. 4. 3.
//
#include <ImageFilterApp.hpp>
#include <ImageFilter.hpp>

ImageFilterApp::ImageFilterApp() : wxApp()
{
    // empty.
}

ImageFilterApp::~ImageFilterApp()
{
    // empty.
}

bool ImageFilterApp::OnInit()
{
    ImageFilter * imgfilter = new ImageFilter();
    imgfilter->ShowModal();

    return true;
}