#include "daisy_seed.h"
#include "daisysp.h"
#include "DaisySeedGFX\GFX.h"
#include "Fonts/FreeMonoBold9pt7b.h"
#include "Img/Pap.h"

using namespace daisy;
using namespace daisysp;

// Gestion du hardware de la carte
DaisySeed hw;

// Gestion de l'écran
FIFO_Data   DMA_BUFFER_MEM_SECTION  __Fifo;								// FIFO pour émission SPI en DMA
RGB 	    DSY_SDRAM_BSS           __FrameBuff[TFT_WIDTH*TFT_HEIGHT];  // Frame Buffer
cGFX 								__Display;							// Ecran

// Intialisation des Fontes
cFont	FreeBold9pt(&FreeMonoBold9pt7b);

void AudioCallback(AudioHandle::InputBuffer in, AudioHandle::OutputBuffer out, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		out[0][i] = in[0][i];
		out[1][i] = in[1][i];
	}
}

int main(void)
{
	// Configuration et Initialisation du Hardware
	hw.Init();
	hw.SetAudioBlockSize(4); // number of samples handled per callback
	hw.SetAudioSampleRate(SaiHandle::Config::SampleRate::SAI_48KHZ);
	
	// Configuration et initialisation de l'écran
	__Display.Init(__FrameBuff, &__Fifo, TFT_WIDTH, TFT_HEIGHT);

	// Start
	hw.StartAudio(AudioCallback);
	
	// Tests de l'écran
	__Display.setFont(&FreeBold9pt);
	__Display.setTextBackColor(cColor(37, 184, 176));
	__Display.setTextFrontColor(cColor(255,255,255));
	uint16_t TextWidth = __Display.getTextWidth("Hello World");
	uint16_t Width = 159;
	uint16_t Height = 127;

	while(1) {
	// Image
	__Display.setRotation(Rotation::Degre_90);
	__Display.drawR8G8B8Image(25, 15, 100, 100, Pap_map);
	__Display.FlushFrame();
	System::Delay(5000);
	
	// Rot 0
	__Display.setRotation(Rotation::Degre_0);
	Width = 127;
	Height = 159;
	__Display.drawRect(0,0,Width,Height,cColor(255,255,255));
	__Display.drawLine(0,0,Width,Height,cColor(255,255,255));
	__Display.drawLine(0,Height,Width,0,cColor(255,255,255));

	__Display.setCursor((Width-TextWidth)/2, (Height/2));
	__Display.drawText("Hello World");
	__Display.FlushFrame();
	System::Delay(5000);
	
	// Rot 90
	__Display.setRotation(Rotation::Degre_90);
	Width = 159;
	Height = 127;
	__Display.drawRect(0,0,Width,Height,cColor(255,255,255));
	__Display.drawLine(0,0,Width,Height,cColor(255,255,255));
	__Display.drawLine(0,Height,Width,0,cColor(255,255,255));

	__Display.setCursor((Width-TextWidth)/2, (Height/2));
	__Display.drawText("Hello World");
	__Display.FlushFrame();
	System::Delay(5000);

	// Rot 180
	__Display.setRotation(Rotation::Degre_180);
	Width = 127;
	Height = 159;
	__Display.drawRect(0,0,Width,Height,cColor(255,255,255));
	__Display.drawLine(0,0,Width,Height,cColor(255,255,255));
	__Display.drawLine(0,Height,Width,0,cColor(255,255,255));

	__Display.setCursor((Width-TextWidth)/2, (Height/2));
	__Display.drawText("Hello World");
	__Display.FlushFrame();
	System::Delay(5000);

	// Rot 270
	__Display.setRotation(Rotation::Degre_270);
	Width = 159;
	Height = 127;
	__Display.drawRect(0,0,Width,Height,cColor(255,255,255));
	__Display.drawLine(0,0,Width,Height,cColor(255,255,255));
	__Display.drawLine(0,Height,Width,0,cColor(255,255,255));

	__Display.setCursor((Width-TextWidth)/2, (Height/2));
	__Display.drawText("Hello World");
	__Display.FlushFrame();
	System::Delay(5000);
	}
}
