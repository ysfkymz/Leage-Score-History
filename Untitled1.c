#include <stdio.h>
#define n 50

struct{
char *kisaIsim;
char *uzunIsim;
int macSayisi,gSayisi,bSayisi,mSayisi,attigiGolSayisi,yedigiGolSayisi,averaj,puan;

}teams[15];


int main()

{
    FILE *fp1;
    char ayarlar[4][n];
    char *c;
    int i=0;
    fp1=fopen("ayarlar.txt","r");

    do {
            c = fgets(ayarlar[i],100,fp1);
            i++;
        } while (c != NULL);
        fclose(fp1);

    int takimSayisi=atoi(ayarlar[0]);

    char takimIsmi[takimSayisi][n];

        i=0;
        fp1 = fopen("takimlar.txt","r");
        do {
            c = fscanf( fp1 ,"%s",takimIsmi[i]);
            i++;
        } while (c != EOF);

        fclose(fp1);
        for(int i=0;i<takimSayisi;i++)
        {
            teams[i].uzunIsim=takimIsmi[i];
        }
        teams[0].kisaIsim="A";
        teams[1].kisaIsim="B";
        teams[2].kisaIsim="C";
        teams[3].kisaIsim="D";
        teams[4].kisaIsim="E";
        teams[5].kisaIsim="F";
        teams[6].kisaIsim="G";
        teams[7].kisaIsim="H";
        teams[8].kisaIsim="I";
        teams[9].kisaIsim="J";


            i=0;

        char maclar[100][n];

        fp1 = fopen("maclar.txt","r");
        do {
            c = fscanf( fp1 ,"%s",maclar[i]);
            i++;
        } while (c != EOF);
        fclose(fp1);

    for(int l=0;l<10;l++)
        {
            teams[l].puan=0;
            teams[l].attigiGolSayisi=0;
            teams[l].averaj=0;
            teams[l].bSayisi=0;
            teams[l].gSayisi=0;
            teams[l].macSayisi=0;
            teams[l].mSayisi=0;
            teams[l].yedigiGolSayisi=0;
        }

    for(int i=0;i<50;i+=4)
    {
        for(int k=i;k<50;k+=4)
        {
            if(strcmp(maclar[i],maclar[k+4])==0)
            {
                if(strcmp(maclar[i+2],maclar[k+6])==0)
                {
                    printf("Dosyanin %d. satirinda, daha onceden oynanmis mac mevcut.\n",((k+4)/4)+1);
                }

            }
        }
    }


    for(int j=0;j<50;j+=4)
    {
        if(atoi(maclar[j+1])>atoi(maclar[j+3]))
        {
            for(int k=0;k<10;k++)
            {
                if(strcmp(maclar[j],teams[k].kisaIsim)==0)
                {
                    teams[k].puan+=atoi(ayarlar[1]);
                    teams[k].macSayisi+=1;
                    teams[k].gSayisi+=1;
                    teams[k].attigiGolSayisi+=atoi(maclar[j+1]);
                    teams[k].yedigiGolSayisi+=atoi(maclar[j+3]);
                    teams[k].averaj+=atoi(maclar[j+1])-atoi(maclar[j+3]);

                }
                if(strcmp(maclar[j+2],teams[k].kisaIsim)==0)
                {
                    teams[k].puan+=atoi(ayarlar[3]);
                    teams[k].macSayisi+=1;
                    teams[k].mSayisi+=1;
                    teams[k].attigiGolSayisi+=atoi(maclar[j+3]);
                    teams[k].yedigiGolSayisi+=atoi(maclar[j+1]);
                    teams[k].averaj+=-atoi(maclar[j+1])+atoi(maclar[j+3]);
                }

            }
        }
          else if(atoi(maclar[j+1])==atoi(maclar[j+3]))
          {
                for(int k=0;k<10;k++)
                {
                    if(strcmp(maclar[j],teams[k].kisaIsim)==0)
                    {
                        teams[k].puan+=atoi(ayarlar[2]);
                        teams[k].macSayisi+=1;
                        teams[k].bSayisi+=1;
                        teams[k].attigiGolSayisi+=atoi(maclar[j+1]);
                        teams[k].yedigiGolSayisi+=atoi(maclar[j+3]);

                    }
                    if(strcmp(maclar[j+2],teams[k].kisaIsim)==0)
                    {
                        teams[k].puan+=atoi(ayarlar[2]);
                        teams[k].macSayisi+=1;
                        teams[k].bSayisi+=1;
                        teams[k].attigiGolSayisi+=atoi(maclar[j+3]);
                        teams[k].yedigiGolSayisi+=atoi(maclar[j+1]);

                    }
                }

          }
            else
            {
                for(int k=0;k<10;k++)
                {
                    if(strcmp(maclar[j],teams[k].kisaIsim)==0)
                    {
                        teams[k].puan+=atoi(ayarlar[3]);
                        teams[k].macSayisi+=1;
                        teams[k].mSayisi+=1;
                        teams[k].attigiGolSayisi+=atoi(maclar[j+1]);
                        teams[k].yedigiGolSayisi+=atoi(maclar[j+3]);
                        teams[k].averaj+=atoi(maclar[j+1])-atoi(maclar[j+3]);
                    }
                    if(strcmp(maclar[j+2],teams[k].kisaIsim)==0)
                    {
                        teams[k].puan+=atoi(ayarlar[1]);
                        teams[k].macSayisi+=1;
                        teams[k].gSayisi+=1;
                        teams[k].attigiGolSayisi+=atoi(maclar[j+3]);
                        teams[k].yedigiGolSayisi+=atoi(maclar[j+1]);
                        teams[k].averaj+=-atoi(maclar[j+1])+atoi(maclar[j+3]);
                    }

                }

            }

    }




        printf("//======================PUAN TABLOSU=====================\\\\");
        printf("\n");
        printf("TAKIM ADI\t   O      G      M      B      A       Y       Av        P\n\n");

        for(int i=0;i<10;i++)
        {
            printf("%s %s",teams[i].kisaIsim,teams[i].uzunIsim);
            for(int j=0;j+strlen(teams[i].uzunIsim)<17;j++)
            {
                printf(" ");
            }
                printf("%d      %d      %d      %d      %d       %d       %d        %d",teams[i].macSayisi,teams[i].gSayisi,teams[i].mSayisi,teams[i].bSayisi,teams[i].attigiGolSayisi,teams[i].yedigiGolSayisi,teams[i].averaj,teams[i].puan);


            printf("\n");
        }



}
