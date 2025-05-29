#pragma once
#include <CtrlLib/CtrlLib.h>
using namespace Upp;

struct Metadata {
    String title, artist, album, year;
    Image thumbnail;

    String ToString() const {
        return Format("Title: %s\nArtist: %s\nAlbum: %s\nYear: %s", title, artist, album, year);
    }
};

Metadata ParseMetadata(const String& filepath);