// Image Reader.cpp : Defines the entry point for the console application.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include <intrin.h>

#include "marker.h"
#include "definitions.h"
#include "datatypes.h"

int main(int argc, char* argv[])
{
	FILE *fp = NULL;
	char *cfilename ;
	cfilename = (char*)malloc(sizeof(char)*255);
	cfilename = "theflash.jpg";
	ubyte ch[2];

	//printf("\nEnter the name of the file:");
	//scanf("%s",filename);
	fp =fopen(cfilename,"r+");
	if( fp == NULL )
	{
		perror("Error while opening the file.\n");
	} 
	else 
	{
		printf("\nSuccessfully opened the file.\n");
		do
		{
			fread(&ch,2,1,fp);
			printf("\n0x%x",ch[0]);
			printf("\n0x%x",ch[1]);
			switch(ch[1])
			{
				case SOI:
					printf("\nStart of Image:\n");
					break;
				case APP0:
					printf("\n This Image is encoded in JPEG File Interchange Format\n");
					JFIF sJfif;
					fread(&sJfif,sizeof(JFIF),1,fp);
					sJfif.usiLength = _byteswap_ushort(sJfif.usiLength);
					printf("\nLength ofMarker: %hu\n",sJfif.usiLength);
					printf("JPEG Format Identifier is %s\n",sJfif.ucaJfifId);
					printf("JFIF Verison is %hu.0%hu\n",sJfif.usiVersion & 1,(sJfif.usiVersion & 512 )>> 8);
					printf("Units for the X and Y densities:%u\n",sJfif.ucUnits);
					printf("Horizontal pixel density is %hu\n",_byteswap_ushort(sJfif.usiXdensity));
					printf("Vertical pixel density is %hu\n",_byteswap_ushort(sJfif.usiYdensity));
					printf("Thumbnail horizontal pixel count: %u\n",sJfif.ucXthumbnail);
					printf("Thumbnail vertical pixel count: %u\n",sJfif.ucYthumbnail);
					break;
				case SOF0:
					printf("\nStart of Frame\n");
					break;
				case SOF1:
					printf("\nStart of Frame\n");
					break;
				case SOF2:
					printf("\nStart of Frame\n");
					break;
				case SOF3:
					printf("\nStart of Frame\n");
					break;
				case SOF5:
					printf("\nStart of Frame\n");
					break;
				case SOF6:
					printf("\nStart of Frame\n");
					break;
				case SOF7:
					printf("\nStart of Frame\n");
					break;
				case SOF8:
					printf("\nStart of Frame\n");
					break;
				case SOF9:
					printf("\nStart of Frame\n");
					break;
				case SOFA:
					printf("\nStart of Frame\n");
					break;
				case SOFB:
					printf("\nStart of Frame\n");
					break;
				case SOFC:
					printf("\nStart of Frame\n");
					break;
				case SOFD:
					printf("\nStart of Frame\n");
					break;
				case SOFE:
					printf("\nStart of Frame\n");
					break;
				case SOFF:
					break;
				default:
					break;
			} 
		} while(ch[1] != EOI);
	}
	printf("\n--------\n");
	getchar();
	return 0;
}