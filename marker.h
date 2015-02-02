//Header file defining structure for marker and format specifiers used in JPEG
#ifndef MARKER_H
#define MARKER_H

#include<stdio.h>
#include "datatypes.h"
#pragma pack(1)

typedef struct marker
{
	ubyte MID[2];		//Marker Identificagtion Code
	ubyte LEN[2];		//Length of the Segment including these two bytes
	ubyte *Content;		//Content of the segment
} Marker;

//JPEG File Interchange Format Specification 
//X’FF’, APP0, length, identifier, version, units, Xdensity, Ydensity, Xthumbnail, Ythumbnail (RGBn is not included)
typedef struct jfif
{
	//Total APP0 field byte count, including the byte count value (2 bytes), but excluding the APP0 marker itself
	ubyte2 usiLength;
	
	//= X'4A', X'46', X'49', X'46', X'00'. This zero terminated string (“JFIF”) uniquely identifies this APP0 marker.
	//This string shall have zero parity (bit 7=0).
	ubyte ucaJfifId[5];	
	
	//The most significant byte is used for major revisions, the least significant byte for minor revisions. 
	//Version 1.02 is the current released revision
	ubyte2 usiVersion;

	//Units for the X and Y densities.
	//units = 0: no units, X and Y specify the pixel aspect ratio
	//units = 1: X and Y are dots per inch
	//units = 2: X and Y are dots per cm
	ubyte ucUnits;
	
	//Horizontal pixel density
	ubyte2 usiXdensity;

	//Vertical pixel density
	ubyte2 usiYdensity;

	// Thumbnail horizontal pixel count
	ubyte ucXthumbnail;

	//Thumbnail vertical pixel count
	ubyte ucYthumbnail;
} JFIF;





#endif


#if 0
struct header
{
	ubyte SOI[2]; //start of the image, must be 0xFF, 0xD8
	
	Marker SOS;		//Start of Scan
	Marker TEMP;	//For temporary use in arithmetic coding
	Marker APP0;
	Marker APP1;
	Marker APP2;
	Marker APP3;
	Marker APP4;
	Marker APP5;
	Marker APP6;
	Marker APP7;
	Marker APP8;
	Marker APP9;
	Marker APP10;
	Marker APP11;
	Marker APP12;
	Marker APP13;
	Marker APP14;
	Marker APP15;
	/*	
		Start of Frame (Baseline DCT)
		Length : Variable length with known structure
		Function : begins a frame header n in SOFn
		identifies the mode of compression and the entropy coder
		used within the frame
	*/

	//Nondifferential Huffman-Coding frames
	Marker SOF0;	//Baseline DCT
	Marker SOF1;	//Extended Sequential DCT
	Marker SOF2;	//Progressive DCT
	Marker SOF3;	//Lossless(Sequential)
	

	//Differential Huffman-Coding frames
	Marker SOF5;	//Differential Sequential DCT
	Marker SOF6;	//Differential progressive DCT
	Marker SOF7;	//Differential lossless
	
	Marker SOF8;

	//Nondifferential arithmetic coding frames
	Marker SOF9;	//Extended Sequential DCT
	Marker SOF10;	//Progressive DCT
	Marker SOF11;	//Lossless(Sequential)
	
	Marker SOF12;
	
	//Differential arithmetic coding frames
	Marker SOF13;	//Differential Sequential DCT
	Marker SOF14;	//Differential progressive DCT
	Marker SOF15;	//Differential lossless
	
	Marker COM;		//Comment
	Marker DAC;		//Define Arithmetic conditioning table(s)
	Marker DHP;		//Define Hierarchical Progression
	Marker DHT;		//Define Huffman table

	Marker DNL;		//Define number of lines
	Marker DQT;		//Define Quantization table; Length: Variable name with known structure; Function: defines one or more quantization table
	Marker DRI;		//Define restart interval
	
	Marker EXP;		//Expand reference image
	
	Marker JPG;		//Reserved for JPG Extension

	ubyte EOI[2];//end of the image, must be 0xFF,0xD9

};

#endif