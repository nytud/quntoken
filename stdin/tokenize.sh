./preproc | ./hyphen | ./snt | ./sntcorr | ./sntcorr |  ./token |\
 sed -e 's/🀰/<s>\n/g' -e 's/🀱/<\/s>/g' -e 's/🀲/<ws>/g' -e 's/🀳/<\/ws>\n/g' -e 's/🀴/<w>/g' -e 's/🀵/<\/w>/g' -e 's/🀶/<c>/g' -e 's/🀷/<\/c>/g' |\
 sed -e 's#</w><ws> </ws>##g' -e 's#^<w>##' -e 's#<ws> </ws>$##g' -e 's#</w><c>#\n<gl/>\n#g' -e 's#</c><w>#\n<gr/>\n#g' -e 's#^<c>##' -e 's#</c>$##' \
     -e 's#</c><ws>$##g' -e 's#^ *</ws>##g' -e '/^$/d' -e 's#</w><ws>##' -e 's#</c></s>#\n</s>\n#g' -e 's#</c><c>##g' -e '/^<ws>$/d'
