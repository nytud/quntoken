#ifndef PRINTER_H
#define PRINTER_H

// quex modulok belso formatumanak atalakitasa a vegso kimeneti formatumra
// API:
//      convert_tags(string& text);
//          a kapott textben lecsereli a quex modulokban hasznalt belso
//          tag-eket a Printer tipusanak megfelelo stringekre (xml. json, tsv)
//      operator<<();
//          TODO: kitalalni! a lenyeg, hogy a kapott dolgokra meghivja a
//          sajat convert_tags metodusat es az eredmenyt kitolja a cout-ra
// TODO:
//  - kitalalni, mi legyen a json es a tsv kimenettel, nem biztos, hogy a
//      szotaras modszer jo lesz azokhoz is!
//  - legyen egy enum tipus, ami parameterkent kap a konstruktor es a neki
//      megfelelo Printert inicializalja: enum OUTPUT_TYPE {XML, JSON, TSV};
//      lehet, hogy ehhez valami tombbe kell tenni a szotarakat es a konstruktor
//      parameterevel beleindexelni (mar ha meg lehet szotar alapon csinalni a
//      tobbi kimeneti formazast is!)
//  - legyen kapcsolo a main-hez, amivel megadhato a kivant kimeneti formatum
//  - C++11-esiteni a statikus ertekadast (http://stackoverflow.com/a/6219450)
//  - megoldani, hogy eleve csak a Printer obj. sajat szotara jojjon letre, a
//      tobbi inicializalo fv ne fusson le! ezt ertelmesen valoszinuleg csak
//      template-elessel es functor-ral lehet jol megcsinalni

#include <map>
#include <string>

enum OUTPUT_TYPE {
    XML = 0,
    JSON,
    TSV
};

class Printer {
    typedef std::map<std::string, std::string> ConversionMap;
    public:
        // konstruktor, destruktor
        Printer(OUTPUT_TYPE type);
        ~Printer() {}
        // API:
        std::string& convert_tags(std::string &text);
        void operator<<(std::string text);
    private:
        // statikus fordito szotarak es az oket inicializalo fuggvenyek
        static ConversionMap xml_map;
        static ConversionMap json_map;
        static ConversionMap tsv_map;
        static ConversionMap createXmlMap();
        static ConversionMap createJsonMap();
        static ConversionMap createTsvMap();

        // a Printer sajat fordito szotara
        ConversionMap myConversionMap;

        // privat tagfuggvenyek:
        void replace_tag(std::string &text, const std::string &what, const std::string &for_what);
};


#endif // PRINTER_H

