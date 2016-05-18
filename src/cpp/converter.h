#ifndef CONVERTER_H
#define CONVERTER_H

// quex modulok belso formatumanak atalakitasa a vegso kimeneti formatumra
// Felulet:
//      convert_tags(string& text);
//          Kapott szovegben lecsereli a quex modulokban hasznalt belso
//          tag-eket a Converter tipusanak megfelelo stringekre (xml. json, tsv)
// TODO:
//  - kitalalni, a tsv kimenettel, nem biztos, hogy a szotaras modszer
//    jo lesz ahoz is!

#include <vector>
#include <utility>
#include <string>
#include "quntoken_api.h"

class Converter {

    // type definitions
    typedef std::vector<std::pair<std::string, std::string> > ConversionMap;

    // private members
    protected:
        ConversionMap myConversionMap;

    // konstruktor, destruktor
    public:
        Converter();
        virtual ~Converter() = 0;

    // private functions
    private:
        void replace_tag(std::string &text, const std::string &what, const std::string &for_what);

    // public functions
    public:
        std::string& convert_tags(std::string &text);

};


class XmlConverter : public Converter {
    public:
        XmlConverter();
        ~XmlConverter() {}
};


class JsonConverter : public Converter {
    public:
        JsonConverter();
        ~JsonConverter() {}
};

#endif // CONVERTER_H

