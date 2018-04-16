//
// Created by hadoo on 18. 4. 3.
//

#ifndef IMAGEFILTER_IMAGEFILTERAPP_HPP
#define IMAGEFILTER_IMAGEFILTERAPP_HPP

#include <wx/wx.h>
class ImageFilterApp : public wxApp
{
public:
    ImageFilterApp();
    ~ImageFilterApp();

public:
    virtual bool OnInit();
};
#endif //IMAGEFILTER_IMAGEFILTERAPP_HPP
