#include "UI.h"
#include "MetadataParser.h"

IVFileManagerUI::IVFileManagerUI() {
    Title("IV File Manager").Sizeable();
    Add(fileList.LeftPosZ(0, 300).VSizePos());
    Add(thumbnail.LeftPosZ(310, 120).TopPosZ(10, 120));
    Add(info.LeftPosZ(310, 400).VSizePos(140, 10));

    fileList.WhenSel << THISBACK(OnFileSelect);
    LoadDirectory(GetHomeDir());
}

void IVFileManagerUI::LoadDirectory(const String& path) {
    fileList.Clear();
    for (const auto& f : DirectoryGetEntries(path)) {
        fileList.Add(f.name);
    }
}

void IVFileManagerUI::OnFileSelect() {
    String file = ~fileList;
    String fullpath = AppendFileName(GetHomeDir(), file);
    Metadata meta = ParseMetadata(fullpath);
    info = meta.ToString();
    thumbnail.SetImage(meta.thumbnail);
}