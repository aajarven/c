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
    tcphdr[0]=(port & 0b1111111111111111);
    tcphdr[1]=(port & 0b00000000000000001111111111111111);
}

void setDestinationPort(unsigned char *tcphdr, int port)
{
    (void) tcphdr;
    (void) port;
}

int getAckFlag(const unsigned char *tcphdr)
{
    return (tcphdr[6] & 0b0000000000010000) >> 4;
}

void setAckFlag(unsigned char *tcphdr, int flag)
{
    (void) tcphdr;
    (void) flag;
}

int getDataOffset(const unsigned char *tcphdr)
{
    return (tcphdr[6] & 0b1111000000000000) >> 12;
}

void setDataOffset(unsigned char *tcphdr, int offset)
{
    (void) tcphdr;
    (void) offset;
}
