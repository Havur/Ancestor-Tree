# Readme
Husk å skrive en god beskrivelse i readme-filen deres. Husk å legge ved et enkelt UML diagram.

# Git

Dere har .gitiginore som fanger opp de fleste standard filtyperi tillegg til  entries for autogenererte filer fra CMake og CLion. Supert! Et tips til innlegget for CMake:
Skriver dere `cmake-build-*` så vil git automatisk ignorere alt som begynner med `cmake-build-`. Søk opp betydningen av "wildcard". 

# CMake

## Unit test

Mangler enhetstester. Dette må dere få inn, bruk pathfinding-prosjektet til inspirasjon https://github.com/AIS1002-OOP/Pathfinding/tree/master/tests. Sjekk både top-level CMakelists.txt og mappen det er lenket til. 

# CI

Mangler CI. Dette må dere få inn, bruk pathfinding-prosjektet og config.yaml https://github.com/AIS1002-OOP/Pathfinding/tree/master/.github/workflows som mal.

# Kode

Husk at innleveringsfristen begynner å nærme seg. 

## Main og programflyt

Dere har fått opp skjelettstruktur for menyvalg, dette er bra. Det samme gjelder person-klassen og mulighet til å legge til og printe personer. 

Angående datastruktur:
Søk opp "binary tree structure" for en mulig datastruktur som kan representere familietreet deres. Hver node i treet har en "parent node" og to "child nodes". Hvordan relateres dette til familietreet? Hvordan henger de tekniske konseptene "parent" og "child" sammen med konseptene "mor", "far" og "barn" i familiesammenheng? Hva representerer roten (rotnode / root node) i treet?
`std::vector<person> persons` i seg selv er en liste av personer, ikke en trestruktur. (Rotnodene kan derimot lagres i en vektor dersom dere ønsker å ha flere familietrær).

## Person-klassen
Angående noen designvalg: 
Bør man ha en variabel for "age" eller "birthyear" for hver person? Hva skjer med variabelen "age" etter man har hatt bursdag? Da må denne inkrementeres. Kan det være bedre å jobbe med "birtyear" og heller regne ut alder når det trengs?

God bruk av const i accessor-metodene til person (mangler for getId() - fort gjort!). Kan getName() returnere en const-referanse? Bør en gjøre dette? Hvorfor? Hvorfor ikke?

Trenger dere mutator-metoder? Hvordan vil dere endre en person senere?

### Kjønn
Ser dere har "gender" i personbuilder men ikke i person, dette må dere huske å legge til. 
Angående datatype:
De mulige verdiene til `gender` har egentlig restriksjoner, de kan (i prinsippet) kun settes til to verdier. Bruker dere en `enum` kan dere definere `Gender` som en egen type der verdiene er `male` og `female`, i motsetning til en streng der verdien i praksis kan settes til hva som helst. Tekststrenger kan brukes til å holde på "male" og "female", men enums tilbyr like god lesbarhet samtidig som kompilatoren sjekker at typene er riktig. Enums definerer en type med navngitte verdier (male/female), og siden strenger egentlig kan settes til hva som helst må ha egen logikk for å verifisere at verdiene er korrekt. Dersom dere på sikt trenger å ha logikk for et tredje kjønn kan dette enkelt utvides på et senere tidspunkt ved bruk av enums. 

```cpp
// in the header file somewhere
enum class Gender {female, male};
Gender gender;

//in the source file somewhere
if(gender == Gender::female)
{
    std::cout << "This individual has the chromosome pair XX" << std::endl;
}
```

---

Disclaimer: Tilbakemeldingen er ikke nødvendigvis komplett og kan ikke brukes som fasit. Bruk skjønn.