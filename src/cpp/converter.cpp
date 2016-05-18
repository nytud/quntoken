#include "converter.h"

// konstansok
const std::string SNT_OPEN("🀰");
const std::string SNT_CLOSE("🀱");
const std::string WS_OPEN("🀲");
const std::string WS_CLOSE("🀳");
const std::string WORD_OPEN("🀴");
const std::string WORD_CLOSE("🀵");
const std::string PUNCT_OPEN("🀶");
const std::string PUNCT_CLOSE("🀷");

// konstruktor
Converter::Converter() {
    myConversionMap = ConversionMap();
}

// destruktor
Converter::~Converter() {}


// vesz egy szoveget, egy 'valamit' es egy 'valamire'-t, majd a szovegben a
// 'valami' osszes elofordulasat lecsereli 'valamire'
void Converter::replace_tag(std::string &text, const std::string &what, const std::string &for_what) {
    for(size_t pos = text.find(what);
        pos != std::string::npos;
        pos = text.find(what, pos+1)) {
        text.replace(pos, what.size(), for_what);
    }
}


// vesz egy szotarat es egy szoveget, a szovegben lecsereli a szotar minden
// tetelenek minden elofordulasat a szotarban megadott megfelelojere
std::string& Converter::convert_tags(std::string &text) {
    for(auto it = myConversionMap.begin(); it != myConversionMap.end(); ++it) {
        replace_tag(text, it->first, it->second);
    }
    return text;
}


// szarmaztatott osztalyok konstruktorai: konverzios szotarak feltoltese
// xml:
XmlConverter::XmlConverter() {
    myConversionMap.push_back(std::make_pair(SNT_OPEN, "<s>"));
    myConversionMap.push_back(std::make_pair(SNT_CLOSE, "</s>"));
    myConversionMap.push_back(std::make_pair(WS_OPEN, "<ws>"));
    myConversionMap.push_back(std::make_pair(WS_CLOSE, "</ws>"));
    myConversionMap.push_back(std::make_pair(WORD_OPEN, "<w>"));
    myConversionMap.push_back(std::make_pair(WORD_CLOSE, "</w>"));
    myConversionMap.push_back(std::make_pair(PUNCT_OPEN, "<c>"));
    myConversionMap.push_back(std::make_pair(PUNCT_CLOSE, "</c>"));
}

// json:
JsonConverter::JsonConverter() {
    // close json items with comma and open another
    myConversionMap.push_back(std::make_pair(SNT_CLOSE+WS_OPEN, "],\n\"ws\": \""));
    myConversionMap.push_back(std::make_pair(SNT_CLOSE+SNT_OPEN, "],\n\"s\": [\n"));
    myConversionMap.push_back(std::make_pair(WS_CLOSE+SNT_OPEN, "\",\n\"s\": [\n"));
    myConversionMap.push_back(std::make_pair(WS_CLOSE+WORD_OPEN, "\",\n\"w\": \""));
    myConversionMap.push_back(std::make_pair(WS_CLOSE+PUNCT_OPEN, "\",\n\"c\": \""));
    myConversionMap.push_back(std::make_pair(WORD_CLOSE+WS_OPEN, "\",\n\"ws\": \""));
    myConversionMap.push_back(std::make_pair(WORD_CLOSE+WORD_OPEN, "\",\n\"w\": \""));
    myConversionMap.push_back(std::make_pair(WORD_CLOSE+PUNCT_OPEN, "\",\n\"c\": \""));
    myConversionMap.push_back(std::make_pair(PUNCT_CLOSE+WS_OPEN, "\",\n\"ws\": \""));
    myConversionMap.push_back(std::make_pair(PUNCT_CLOSE+WORD_OPEN, "\",\n\"w\": \""));
    myConversionMap.push_back(std::make_pair(PUNCT_CLOSE+PUNCT_OPEN, "\",\n\"c\": \""));
    // open json items
    myConversionMap.push_back(std::make_pair(SNT_OPEN, "\"s\": [\n"));
    myConversionMap.push_back(std::make_pair(WS_OPEN, "\"ws\": \""));
    myConversionMap.push_back(std::make_pair(WORD_OPEN, "\"w\": \""));
    myConversionMap.push_back(std::make_pair(PUNCT_OPEN, "\"c\": \""));
    // close json items
    myConversionMap.push_back(std::make_pair(SNT_CLOSE, "]\n"));
    myConversionMap.push_back(std::make_pair(WS_CLOSE, "\"\n"));
    myConversionMap.push_back(std::make_pair(WORD_CLOSE, "\"\n"));
    myConversionMap.push_back(std::make_pair(PUNCT_CLOSE, "\"\n"));
}

