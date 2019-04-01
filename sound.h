// constants definitions
#define RATE 16000		// samples per second

// data structures
struct WAVEHDR{
	char ChunkID[4];	// it has to be "IRFF"
	int Chunksize;		// 4-byte number
	char Format[4];		// it has to be "WAVE"

	char SubchunkID[4];	// "fmt"
	int Subchunksize;	// PCM = 16
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
