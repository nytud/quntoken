#ifndef PRINTER_H
#define PRINTER_H

// quex modulok belso formatumanak atalakitasa a vegso kimeneti formatumra
// TODO:
//  - a forditasi parokat szotarba (map) tenni.
//  - tobb konstans szotarat letrehozni a lehetseges kimenetekhez (nem biztos,
//    hogy a szotar jo modszer json vagy tsv kimenethez)
//  - legyen kapcsolo a main-hez, amivel megadhato a kivant kimeneti formatum
//  - igazabol kene valami kulon formazo osztaly

void replace_tag(std::string &text, const std::string &what, const std::string &for_what) {
    for(size_t pos = text.find(what);
        pos != std::string::npos;
        pos = text.find(what, pos+1)) {
        text.replace(pos, what.size(), for_what);
    }
}

std::string& convert_to_xml(std::string &text) {
    replace_tag(text, "🀰", "<s>");
    replace_tag(text, "🀱", "</s>");
    replace_tag(text, "🀲", "<w>");
    replace_tag(text, "🀳", "</w>");

    return text;
}

#endif // PRINTER_H

