#include<iostream>
#include<string>
#include<sstream>
#include <gtest/gtest.h>
#include "snt_snt_lexer" // ennek előbb kell lennie, mint a többi quex-esnek
#include <quex/code_base/definitions> // QUEX_CONVERTER_STRING-hez


std::string process_text(std::string text)
{
    std::string res;
    snt::Token*       token_p = 0x0;
    std::stringstream tmp(text);
    snt::snt_lexer lexer(&tmp, "UTF8");

    for (lexer.receive(&token_p);
         token_p->type_id() != SNT_TERMINATION;
         lexer.receive(&token_p))
    {
        res += QUEX_CONVERTER_STRING(unicode, char)(token_p->get_text());
    }

    return res;
}

TEST(process_text, PositiveNos) { 
    // 0. Egyszerű mondat
	// BE: A kutya ugat. Jó\nlenne, ha abbahagyná!
	// KI: <s>A kutya ugat.</s>\n<w> </w>\n<s>Jó\nlenne, ha abbahagyná!</s>
	// BE: Ez itt már\n\nkülön bekezdés!
	// KI: <s>Ez itt már\n</s><w>\n</w><s>külön bekezdés!</s>
    ASSERT_STREQ(
            "<s>A kutya ugat.</s><w> </w><s>Jó\nlenne, ha abbahagyná!</s>",
            process_text("A kutya ugat. Jó\nlenne, ha abbahagyná!").c_str());
    ASSERT_STREQ(
            "<s>Ez itt már\n</s><w>\n</w><s>külön bekezdés!</s>",
            process_text("Ez itt már\n\nkülön bekezdés!").c_str());
    // ASSERT_STREQ("", process_text("").c_str());
    // 1. Mondathatár túllépés: mondatzáró után kis betű
    // BE: N. kormányzósági székhely.
    // KI: <s>N. kormányzósági székhely.</s>
    // BE: A www.akármi.hu.
    // KI: <s>A www.akármi.hu.</s>
    // BE: - Nézd a! - mondta az egyik.
    // KI: <s>- Nézd a! - mondta az egyik.</s>
    // BE: A 4. javítócsomagot.
    // KI: <s>A 4. javítócsomagot.</s>
    // BE: 3434/1992. évi elszámolás.
    // KI: <s>3434/1992. évi elszámolás.</s>
    // BE: "Jót s jól! Ebben áll a nagy titok" - figyelmezteti Kazinczy költőtársait.
    // KI: <s>"Jót s jól!</s>\n<w> </w>\n<s>Ebben áll a nagy titok" - figyelmezteti Kazinczy költőtársait.</s>
    // BE: - Szia Péterkém! Holnap találkozunk - mondta Gizi.
    // KI: <s>- Szia Péterkém!</s>\n<w> </w>\n<s>Holnap találkozunk - mondta Gizi.</s>
    ASSERT_STREQ(
            "<s>N. kormányzósági székhely.</s>",
            process_text("N. kormányzósági székhely.").c_str());
    ASSERT_STREQ(
            "<s>A www.akármi.hu.</s>",
            process_text("A www.akármi.hu.").c_str());
    ASSERT_STREQ(
            "<s>- Nézd a! - mondta az egyik.</s>",
            process_text("- Nézd a! - mondta az egyik.").c_str());
    ASSERT_STREQ(
            "<s>A 4. javítócsomagot.</s>",
            process_text("A 4. javítócsomagot.").c_str());
    ASSERT_STREQ(
            "<s>3434/1992. évi elszámolás.</s>",
            process_text("3434/1992. évi elszámolás.").c_str());
    ASSERT_STREQ(
            "<s>\"Jót s jól!</s><w> </w><s>Ebben áll a nagy titok\" - figyelmezteti Kazinczy költőtársait.</s>",
            process_text("\"Jót s jól! Ebben áll a nagy titok\" - figyelmezteti Kazinczy költőtársait.").c_str());
    ASSERT_STREQ(
            "<s>- Szia Péterkém!</s><w> </w><s>Holnap találkozunk - mondta Gizi.</s>",
            process_text("- Szia Péterkém! Holnap találkozunk - mondta Gizi.").c_str());
    // 2. Mondatzáró után idéző- vagy kötő jel.
    // BE: A "Ne már!"-ral az a baj.
    // KI: <s>A "Ne már!"-ral az a baj.</s>
    ASSERT_STREQ(
            "<s>A \"Ne már!\"-ral az a baj.</s>",
            process_text("A \"Ne már!\"-ral az a baj.").c_str());
    // 3. Pont után közvetlenül szóalkotó karakter a pontot magát leszámítva.
    // BE: A WWW.AKARMI.HU.
    // KI: <s>A WWW.AKARMI.HU.</s>
    ASSERT_STREQ(
            "<s>A WWW.AKARMI.HU.</s>",
            process_text("A WWW.AKARMI.HU.").c_str());
    // 4. Mondatzáró után közvetlenül [,;:], utánuk kisbetű
    // BE: Azt mondta, hogy "Na!", "Csináld!" és így tovább.
    // KI: <s>Azt mondta, hogy "Na!", "Csináld!" és így tovább.</s>
    ASSERT_STREQ(
            "<s>Azt mondta, hogy \"Na!\", \"Csináld!\" és így tovább.</s>",
            process_text("Azt mondta, hogy \"Na!\", \"Csináld!\" és így tovább.").c_str());
    // 5. Mondatban lévő zárójeles rész kezelése.
    // BE: A macska (családjában a 25.) Katinak nyávogott.
    // KI: <s>A macska (családjában a 25.) Katinak nyávogott.</s>
    ASSERT_STREQ(
            "<s>A macska (családjában a 25.) Katinak nyávogott.</s>",
            process_text("A macska (családjában a 25.) Katinak nyávogott.").c_str());
}
 
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

