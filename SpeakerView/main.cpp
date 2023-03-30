#include "SpeakerView.h"
using namespace std;

int main(int argc, char **argv){
    
    SpeakerView* speaker = new SpeakerView("sampleInput.txt");
    speaker->determineVisibilty();
    
    return 0;
}