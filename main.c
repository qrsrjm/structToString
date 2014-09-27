#include <stdio.h>
#include <stdlib.h>

#include "lrx.h"

void volToStr(VOL_OP *p);

int main()
{
    VOL_OP vol;
    vol.Ch = 1;
    vol.vol.Gain=12;
    vol.vol.Pol=0;
    vol.vol.Mute=0;

    volToStr(&vol);

    return 0;
}


void volToStr(VOL_OP *p)
{
    char tmp[64]={0},dest[64]={0};
    int len=0;
    for(int i=0;i<2;i++)
    {
        memset(tmp,0,64);
        sprintf(tmp,"vol%d,%f,%d,%d,",p->Ch,p->vol.Gain, p->vol.Pol,p->vol.Mute);
        strcpy(dest+len,tmp);
        len = strlen(tmp);
    }

    printf("%s,len=%d\n",dest,strlen(dest));
}
