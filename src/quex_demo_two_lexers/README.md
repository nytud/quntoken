Demo két független quex elemző összekötésére, egy main()-ben.

* input: fájlból olvas, stdin kicsit bonyolultabb
* puffer: std::stringstream
* output: stdout
* formátum: xml. A quex-el lemondunk egy formátumfüggetlen adatszerkezet
  lehetőségéről, mindent stringmanipulációvalkell megoldani. Ennek választott
  formátuma egyelőre az xml. Ha más kimenet kell, akkor a kiíratás előtt
  xml-ből kell átalakítani.


