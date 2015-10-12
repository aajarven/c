#include <stdio.h>
#include "tcpheader.h"


int getSourcePort(const unsigned char *tcphdr)
{
    (void) tcphdr;
    return 0;
}

int getDestinationPort(const unsigned char *tcphdr)
{
    (void) tcphdr;
    return 0;
}

void setSourcePort(unsigned char *tcphdr, int port)
{
    (void) tcphdr;
    (void) port;
}

void setDestinationPort(unsigned char *tcphdr, int port)
{
    (void) tcphdr;
    (void) port;
}

int getAckFlag(const unsigned char *tcphdr)
{
    (void) tcphdr;
    return 0;
}

void setAckFlag(unsigned char *tcphdr, int flag)
{
    (void) tcphdr;
    (void) flag;
}

int getDataOffset(const unsigned char *tcphdr)
{
    (void) tcphdr;
    return 0;
}

void setDataOffset(unsigned char *tcphdr, int offset)
{
 (void) tcphdr;
  (void) offset;
}
