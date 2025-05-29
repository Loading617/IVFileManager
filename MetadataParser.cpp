#include "MetadataParser.h"
#include <plugin/taglib/taglib.h>

Metadata ParseMetadata(const String& filepath) {
    Metadata meta;

    if (ToLower(GetFileExt(filepath)) == ".mp3") {
        meta.title = GetFileTitle(filepath);
        meta.artist = "Unknown";
        meta.album = "Unknown Album";
    } else if (ToLower(GetFileExt(filepath)) == ".mp4" || ToLower(GetFileExt(filepath)) == ".mkv") {
        meta.title = GetFileTitle(filepath);
        meta.year = "Unknown";
    } else {
        meta.title = GetFileTitle(filepath);
    }

    return meta;
}

