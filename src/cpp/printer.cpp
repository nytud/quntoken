#include "printer.h"

// konstansok
const std::string SNT_OPEN_CPP("🀰");
const std::string SNT_CLOSE_CPP("🀱");
const std::string SNT_OPEN_WS("🀲");
const std::string SNT_CLOSE_WS("🀳");

// konstruktor
Printer::Printer(OUTPUT_TYPE type) {
    switch(type) {
        case XML:
            myConversionMap = xml_map;
            break;
        case JSON:
            myConversionMap = json_map;
            break;
        case TSV:
            myConversionMap = tsv_map;
            break;
    }
}


// atvett szoveg konvertalasa es kiirasa
// TODO: valamiert nem megy referenciaval, pedig az hatekonyabb lenne
void Printer::operator<<(std::string text) {
    convert_tags(text);
    std::cout << text;
}


// vesz egy szoveget, egy 'valamit' es egy 'valamire'-t, majd a szovegben a
// 'valami' osszes elofordulasat lecsereli 'valamire'
void Printer::replace_tag(std::string &text, const std::string &what, const std::string &for_what) {
    for(size_t pos = text.find(what);
        pos != std::string::npos;
        pos = text.find(what, pos+1)) {
        text.replace(pos, what.size(), for_what);
    }
}


// vesz egy szotarat es egy szoveget, a szovegben lecsereli a szotar minden
// tetelenek minden elofordulasat a szotarban megadott megfelelojere
std::string& Printer::convert_tags(std::string &text) {
    for(auto it = myConversionMap.begin(); it != myConversionMap.end(); ++it) {
        replace_tag(text, it->first, it->second);
    }
    return text;
}


// szotarak feltoltese
// xml:
Printer::ConversionMap Printer::createXmlMap() {
    ConversionMap xml_map;
    xml_map[SNT_OPEN_CPP] = "<s>";
    xml_map[SNT_CLOSE_CPP] = "</s>";
    xml_map[SNT_OPEN_WS] = "<w>";
    xml_map[SNT_CLOSE_WS] = "</w>";
    return xml_map;
}

// json:
Printer::ConversionMap Printer::createJsonMap() {
    ConversionMap json_map;
    return json_map;
}

// tsv:
Printer::ConversionMap Printer::createTsvMap() {
    ConversionMap tsv_map;
    /* tsv_map["n"] = "X"; */
    return tsv_map;
}

Printer::ConversionMap Printer::xml_map = Printer::createXmlMap();
Printer::ConversionMap Printer::json_map = Printer::createJsonMap();
Printer::ConversionMap Printer::tsv_map = Printer::createTsvMap();

