#ifndef CONVERTER_H
#define CONVERTER_H

// quex modulok belso formatumanak atalakitasa a vegso kimeneti formatumra
// Felulet:
//      convert_tags(string& text);
//          Kapott szovegben lecsereli a quex modulokban hasznalt belso
//          tag-eket a Converter tipusanak megfelelo stringekre (xml. json, tsv)
//      operator<<();
//          Kapott stringre meghivja a sajat convert_tags metodusat es az
//          eredmenyt kitolja a cout-ra.
// TODO:
//  - kitalalni, mi legyen a json es a tsv kimenettel, nem biztos, hogy a
//    szotaras modszer jo lesz azokhoz is!
//  - legyen kapcsolo a main-hez, amivel megadhato a kivant kimeneti formatum
//  - C++11-esiteni a statikus ertekadast (http://stackoverflow.com/a/6219450)
//  - Megoldani, hogy eleve csak a Converter obj. sajat szotara jojjon letre, a
//    tobbi inicializalo fv ne fusson le! ezt ertelmesen valoszinuleg csak
//    template-elessel (es functor-ral) lehet megcsinalni. (Nem biztos, hogy
//    kell!)

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
        void operator<<(std::string text);

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

