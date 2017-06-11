#Robootika lõputöö - Robert otsib tantsupartnerit

## Ülesande kirjeldus
Robot sõidab otse kuni esimese takistuse ehk potentsiaalse tantsupartnerini.
Seejärel keerab robot ennast ringi ja asub kaarja liigutusega ümber tantsupartneri tantsima, moodustades tantsupõrandale lille mustreid. Kui tantsupartner peaks ära kaduma, siis tiirutab robot lihtsalt nukralt ringiratast.
Et potentsiaalset partnerit mitte hirmutada, vilgutab robot temale lähenedes tulesid, mida hämaram on tuba, seda eredamalt tuled vilguvad. Programmikoodis on määratud ka valgustuse tase, millest väiksemal juhul vilgutamine algab. Hea valgustuse korral vilgutamist ei toimu.

## Mõned tähelepanekud ja "ai-jaa" momendid
* toa valgustatuse mõõtmine ei ole loogiline, kui sul anduri kõrval põleb samal ajal juba ere LED
* mootorid pöörlevad erineva kiirusega, on tükk timmimist, et robot otse liiguks
* roboti keeramine näiteks täpselt 90 kraadi ei ole sugugi lihtne
* nelinurksete tantsupartnerite ümber tiirutamine on raskendatud, kuna nurkadega ei tule robot väga hästi toime

## Võimalikud edasiarendused
* panna robot mööda musta joont sõitma, kuni takistuseni
* seejärel proovida takistusest ümber minna samasuguse kaarja liigutuseni, kuniks leiab uue musta joone või jõuab sama jooneni tagasi
* jooneni jõudnuna keerab ennast paremale ja sõidab jälle mööda joont kuni esimese takistuseni
