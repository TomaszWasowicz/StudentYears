#include <stdio.h>
#include <stdlib.h>
#include <stdint-gcc.h>
#include <time.h>
#include <string.h>

struct berResult
{
    uint32_t tot; //total number of bits
    uint32_t err; //number of bits in error
    float ber;  //ber calc result
    clock_t t1; //calc start clock
    clock_t t2; //calc stop clock
    double clock_w;
    char *filePatch1;
    char *filePatch2;
};

void    openLog    (void);
void    saveLog    (char* pMsg);
void    closeLog   (void);
void    komparator ();

void    createFileMy(const char *fName, const int32_t fbytes, const char value, const int32_t difbytes, const char difvalue);
void    createFile1(const char *pName, const int32_t count, const char value);
void    createBigFile(const char *fName, const int32_t fmbytes, const char value);

static FILE *pLogFile = NULL; // FILE Log

#define CREATE_FILE 0

int main(int argc, char *argv[])
{
    openLog();
    saveLog("BER v1.1 Start");


    if(3 != argc)
    {
        saveLog("Brak args. Tworzenie pliku");

        #if CREATE_FILE == 0
        createFile1("file1.bin", 100u, 0x55);
        createFile1("file2.bin", 100u, 0x55);


        #elif CREATE_FILE == 1
         createFile1("secfile1.bin", 100u, 0x55);
        createFileMy("secFile2.bin", 100u, 0x55, 10u, 0x54); // n, n, ,n - bajtow nowej wartosci, n - nowa wartosc


        #elif CREATE_FILE == 2
        createBigFile("bigFile1.bin", 400u, 0x55);
        createBigFile("bigFile2.bin", 400u, 0x50);
        #endif


    }
    else
    {
        saveLog("Wczytywanie plików:");
        komparator(argv);
    }

    //Nalezy dodac funkcje modyfikujaca pliki tak aby przeprowadzic obliczenia BER zgodnie z Zadaniem
    //Nalezy dodac funkcje obliczajaca BER
    //saveLog("Obliczam BER");
    //wnk = calculateBer(fpath1, fpath2);
    //Nalezy dodac funkcje drukujaca wynik obliczen na konsoli oraz do pliku logów
    //printResult(wnk);

    closeLog();
    return 0;
}


//printf//
void druk (struct berResult *BER)
{
    printf("Sciezka pliku nr 1: %s \n", BER->filePatch1);
    printf("Sciezka pliku nr 2: %s \n", BER->filePatch2);
    printf("Rozmiar porownywanych plikow : %d bitow \n", BER->tot);
    printf("Ilosc blednych bitow : %d \n", BER->err);
    printf("Wynik BER : %.5f \n", BER->ber);
     printf("Czas %.4f \n",(float)difftime(BER->t1, (float)BER->t2));

//log//
     char buffer [65];
     saveLog(BER->filePatch1);
     saveLog(BER->filePatch2);
     sprintf(buffer, "Łącznie bitów: %ld", BER->tot);
     saveLog(buffer);
     sprintf(buffer, "BER: %.4f", BER->ber);
     saveLog(buffer);
     sprintf(buffer, "Niezgodnych bitów: %ld", BER->err);
     saveLog(buffer);
     sprintf(buffer, "Zajęło mi: %.1f sec", BER->clock_w);
     saveLog(buffer);



}

//comperator//
void komparator (char *argv[])
{
    struct berResult *BER = (struct berResult*) malloc(sizeof(struct berResult));
    BER->t1 = time(NULL);

//file1//
    char *bufor1;
    uint64_t lSize1;
    size_t result1;
    FILE *fileNr1 = NULL;

    fileNr1 = fopen(argv[1], "rb");
    if (fileNr1 == NULL)
    {
        puts("Blad przy otwieraniu");
        saveLog("Błąd przy otwieraniu");
    }
//save the size//
    fseek(fileNr1, 0, SEEK_END);
    lSize1 = ftell(fileNr1);
    rewind(fileNr1);
    printf("Plik 1 ma %I64d bajtow \n", lSize1);

//allocate the memory//
    bufor1 = (char*)malloc(sizeof(char)*lSize1);
    if (bufor1 == NULL) {puts("Blad przy alokacji pamieci"); }

//copy from a file to a buffor//
    result1 = fread(bufor1, sizeof(char), lSize1, fileNr1);
    if (result1 != lSize1) puts("Blad przy odczycie");

//close the file//
    if (fclose(fileNr1) != 0) puts("Blad przy zamykaniu pliku!");

//file2//
    char *bufor2;
    uint64_t lSize2;
    size_t result2;
    FILE *fileNr2 = NULL;

    fileNr2 = fopen(argv[2], "rb");
    if (fileNr2 == NULL)
    {
        puts("Blad przy otwieraniu");
        saveLog("Błąd przy otwieraniu");
    }
//save the size//
    fseek(fileNr2, 0, SEEK_END);
    lSize2 = ftell(fileNr2);
    rewind(fileNr2);
    printf("Plik 2 ma %I64d bajtow \n", lSize2);

//allocate the memory for a whole file//
    bufor2 = (char*)malloc(sizeof(char)*lSize2);
    if (bufor2 == NULL) {puts("Blad przy alokacji pamieci"); }

//copy from a file to a buffor//
    result2 = fread(bufor2, sizeof(char), lSize2, fileNr2);
    if (result2 != lSize2) puts("Blad przy odczycie");

    // zamknij plik //
    if (fclose(fileNr2) != 0) puts("Blad przy zamykaniu pliku!");

//compare the sizes//
uint64_t allSize = 0;
if (lSize1 == lSize2) {puts("Pliki maja jednakowy rozmiar"); allSize = lSize1; }
else if (lSize1 > lSize2) { allSize = lSize2; puts("Plik nr 1 jest wiekszy");}
else {allSize = lSize1; puts("Plik nr 2 jest wiekszy");}



//bit comperator//

    //double percent = 0.0;
    double ber = 0.0;

    uint8_t komp = 0x01;
    uint64_t difbits = 0;
    uint8_t xortemp = 0x00;
    uint8_t temp = 0x00;

    for (uint64_t byte = 0; byte < allSize; byte++)
    {
        komp = 0x01;
        xortemp = bufor1[byte] ^ bufor2[byte];

        for (uint8_t bit = 0; bit<8; bit++)
        {
            temp = xortemp & komp;
            temp = temp >> bit;
            difbits+=temp;
            komp = komp << 1;
        }
    }
//end of the comperator//

    // save the results in a structure//
    //percent = (100.0f/(allSize*8))*((allSize*8)-difbits);
    ber = (float)difbits / (allSize*8);
     printf("BER: %.5f \n",ber);

     BER->t2 = time(NULL);
     BER->ber = (float)difbits / (allSize*8);
     BER->tot = (allSize*8);
     BER->err = difbits;
     BER->t2 = time(NULL);
     BER->clock_w = difftime(BER->t2, BER->t1);
        BER->filePatch1 = malloc(strlen(argv[1])+1);
     strcpy(BER->filePatch1, argv[1]);
        BER->filePatch2 = malloc(strlen(argv[2])+1);
     strcpy(BER->filePatch2, argv[2]);

     druk(BER);

     free(BER);

}
//end of the comperator//


//file creator//
void createFileMy (const char *fName, const int32_t fbytes, const char value, const int32_t difbytes, const char difvalue)
{
    FILE *myFile = NULL;
    uint32_t i = 0;
    size_t s = 0;

    myFile = fopen(fName, "w+");
    if (NULL == myFile) perror("fopen file failed");
    saveLog("Save to custom file started");
    for(i=0u; i < (fbytes-difbytes) ; i++)
    {
        s = fwrite(&value, sizeof(char), 1u, myFile);
        if(s != 1) perror("fwrite failed");
    }
    for (i=0u; i<difbytes; i++)
    {
        s = fwrite(&difvalue, sizeof(char), 1u, myFile);
        if(s != 1) perror("fwrite failed");
    }

    if(0 != fclose(myFile)) perror("fclose file failed");
    saveLog("Custom file ready");
}


//big file//
void createBigFile (const char *fName, const int32_t fmbytes, const char value)
{
    FILE *bigFile = NULL;
    uint32_t i = 0;
    size_t s = 0;

    bigFile = fopen(fName, "w+");
    if (NULL == bigFile) perror("fopen file failed");
    saveLog("Save to custom file started");
    for(i=0u; i < (fmbytes*1024*1024) ; i++)
    {
        s = fwrite(&value, sizeof(char), 1u, bigFile);
        if(s != 1) perror("fwrite failed");
    }

    if(0 != fclose(bigFile)) perror("fclose file failed");
    saveLog("Custom file ready");
}
//end//


void createFile1(const char *pName, const int32_t count, const char value)
{
    FILE *pFile = NULL;
    uint32_t i = 0;
    size_t s = 0;

    pFile = fopen(pName, "w+");
    if (NULL == pFile) perror("fopen file failed");
    saveLog("Save to file started");
    for(i=0u; i < count ; i++)
    {
        s = fwrite(&value, sizeof(char), 1u, pFile);
        if(s != 1) perror("fwrite failed");
    }
    if(0 != fclose(pFile)) perror("fclose file failed");
    saveLog("File ready");
}

void openLog(void)
{
    pLogFile = fopen("log.txt", "a+");
    if (NULL == pLogFile) perror("fopen file failed");
}

void saveLog(char *pMsg)
{
//Write the log header
    time_t now = time(NULL);
    size_t headerSize = snprintf(NULL, 0, asctime(localtime(&now)));

    char *pLogHeader = malloc(headerSize);
    headerSize = snprintf(pLogHeader, headerSize, asctime(localtime(&now)));
    size_t s = fwrite(pLogHeader, sizeof(char), headerSize - 1u, pLogFile);
    if(s != headerSize - 1u) perror("fwrite failed");
    s = fwrite(" ", sizeof(char), 1u, pLogFile);
    if(s != 1u) perror("fwrite failed");
    free(pLogHeader);

//Write user pMsg
    s = fwrite(pMsg, sizeof(char), strlen(pMsg), pLogFile);
    s += fwrite("\n", sizeof(char), 1u, pLogFile);
    if(s != strlen(pMsg) + 1u) perror("fwrite failed");
    if (0 != fflush(pLogFile)) perror("fflush failed");
}

void closeLog (void)
{
    if(0 != fclose(pLogFile)) perror("fclose file failed");
}
