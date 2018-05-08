/*
 * message.c
 *
 *  Created on: 2018-3-12
 *      Author: Dell
 */

#include "message.h"

int getStartMessge(char* message)
{
    return NULL != strchr(message,'S') && NULL != strchr(message,'E');
}

void parseMessage(char* result, TestMessage* message)
{
    char temp[8] = {0};

    //get start fre
    printf("message %s \n",result);

    char *cur = strchr(result, 'f') + 2;
    char *space = strchr(cur, ' ');
    memcpy(temp,cur, space - cur);
    message->startFre = atoi(temp);
    printf("start fre %d \n", message->startFre);

    //get end fre
    cur = space + 1;
    space = strchr(cur, ' ');
    memset(temp, 0, 8);
    memcpy(temp,cur, space - cur);
    message->endFre = atoi(temp);
    printf("end fre %d \n",message->endFre);

    //get num
    cur = strchr(cur, 'N') + 2;
    space = strchr(cur, ' ');
    memset(temp, 0, 8);
    memcpy(temp,cur, space - cur);
    message->sweepNum = atoi(temp);
    printf("num %d \n",message->sweepNum);

    //get form
    cur = strchr(cur, 'F') + 2;
    memset(temp, 0, 8);
    memcpy(temp,cur, 1);
    message->showForm = atoi(temp);
    printf("form %d \n",message->showForm);

    message->getMessege = 1;
}
