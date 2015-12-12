#include<iostream>
#include<string>
#include<sstream>
#include <gtest/gtest.h>
#include "snt_snt_lexer"


std::string process_text(std::string text)
{
    std::string res;
    snt::Token*       token_p = 0x0;
    std::stringstream tmp(text);
    snt::snt_lexer lexer(&tmp, "UTF8");

    for (lexer.receive(&token_p); token_p->type_id() != SNT_TERMINATION; lexer.receive(&token_p))
    {
        res += token_p->pretty_char_text() + "\n";
    }

    return res;
}

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
TEST(process_text, PositiveNos) { 
    ASSERT_STREQ("<s>N. kormányzósági székhely.</s>\n", process_text("N. kormányzósági székhely.").c_str());
    ASSERT_STREQ("<s>A www.akármi.hu.</s>\n", process_text("A www.akármi.hu.").c_str());
    ASSERT_STREQ("<s>- Nézd a! - mondta az egyik.</s>\n", process_text("- Nézd a! - mondta az egyik.").c_str());
    ASSERT_STREQ("<s>A 4. javítócsomagot.</s>\n", process_text("A 4. javítócsomagot.").c_str());
    ASSERT_STREQ("<s>3434/1992. évi elszámolás.</s>\n", process_text("3434/1992. évi elszámolás.").c_str());
    ASSERT_STREQ("<s>\"Jót s jól!</s>\n<w> </w>\n<s>Ebben áll a nagy titok\" - figyelmezteti Kazinczy költőtársait.</s>\n", process_text("\"Jót s jól! Ebben áll a nagy titok\" - figyelmezteti Kazinczy költőtársait.").c_str());
    ASSERT_STREQ("<s>- Szia Péterkém!</s>\n<w> </w>\n<s>Holnap találkozunk - mondta Gizi.</s>\n", process_text("- Szia Péterkém! Holnap találkozunk - mondta Gizi.").c_str());
}
 
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

