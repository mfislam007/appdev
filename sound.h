// constants definitions
//#define DEBUG 
#define RATE 16000		// samples per second
#define CMD "arecord -r16000 -c1 -f S16_LE -d1 -q test.wav"
#define PI 3.1416
// data structures
struct WAVHDR{
	char ChunkID[4];	// it has to be "IRFF"
	int ChunkSize;		// 4-byte number
	char Format[4];		// it has to be "WAVE"

	char Subchunk1ID[4];	// "fmt"
	int Subchunk1Size;	// PCM = 16
	short AudioFormat;	// should be 1
	short NumChannels;	// shuld be 1 for mono
	int SampleRate;		// 1600
	int ByteRate;		// 16000*NumChannels*BitsPersample/8
	short BlockAlign; 	// NumChannel*BitsPerSample/8
	short BitsPerSample; 	// in our app, 16 (-f S16_LE)
	
	char Subchunk2ID[4];	//"data"
	int Subchunk2Size; 	//
};

// function declarations
void displayWAVHDR(struct WAVHDR h);
void displayWAVDATA(short []);
void testTone(int, int, float);
