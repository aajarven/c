#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tcpheader.h"


int getSourcePort(const unsigned char *tcphdr)
{
    int palautus = 0;
    palautus += tcphdr[0];
    palautus = palautus << 8;
    palautus += tcphdr[1];
    return palautus;
}

int getDestinationPort(const unsigned char *tcphdr)
{
    int palautus = 0;
    palautus += tcphdr[2];
    palautus = palautus << 8;                                                                
    palautus += tcphdr[3];
    return palautus;
}

void setSourcePort(unsigned char *tcphdr, int port)
{
    tcphdr[0]=(port >> 8);
    tcphdr[1]=(port & 0b0000000011111111) ;
}

void setDestinationPort(unsigned char *tcphdr, int port)
{
    tcphdr[2]=(port >> 8);
    tcphdr[3]=(port & 0b0000000011111111) ;
}

int getAckFlag(const unsigned char *tcphdr)
{
    return (tcphdr[13] & 0b00010000) >> 4;
}

void setAckFlag(unsigned char *tcphdr, int flag)
{
    if (flag == 1){
        tcphdr[13] |= 0b00010000;
    } else {
        tcphdr[13] &= 0b11101111;
    } 
}

int getDataOffset(const unsigned char *tcphdr)
{
    return (tcphdr[12]) >> 4;
}

void setDataOffset(unsigned char *tcphdr, int offset)
{
    int byte12 = offset << 4;
    byte12 += tcphdr[12] & 0b00001111;
    tcphdr[12] = byte12;
}
