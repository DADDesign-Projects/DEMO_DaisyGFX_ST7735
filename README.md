# DEMO_DaisyGFX_ST7735
Demo TFT graphical display library for Daisy Seed T7789 driver

## Author
DAD Design

## Présentation / Introduction
The present project demonstrates the implementation of the DaisySeedGFX library  
https://github.com/DADDesign-Projects/DaisySeedGFX.  
*Le présent projet montre la mise en oeuvre de la librairie DaisySeedGFX*  
*https://github.com/DADDesign-Projects/DaisySeedGFX.*

DaisySeedGFX is a graphical library for the Daisy Seed platform by Electrosmith.
The library currently only supports ST7735 and ST7789 controllers. In principle, the library should be easily adaptable to any controller.
The library uses an intermediate frame buffer between the graphical primitives and the controller. Modifications made in the frame buffer are transmitted to the controller using SPI transfers under DMA. To reduce transfers, the frame buffer is divided into blocks -> only the modified blocks are transferred to the screen.
The graphical primitives are minimalistic and can be expanded as needed.

*DaisySeedGFX est une bibliothèque graphique pour la plateforme Daisy Seed de Electrosmith.*  
*La bibliothèque prend en charge pour le moment uniquement les contrôleurs ST7735 et ST7789. A priori la bibliothèque doit pouvoir être adaptée à n’importe quel contrôleur assez facilement.*  
*La bibliothèque utilise un frame buffer intermédiaire ente les primitives graphiques et le contrôleur. Les modifications réalisées dans le frame buffer sont transmises au contrôleur utilisant les transferts SPI sous DMA. Afin de réduire les transferts le frame buffer est divisé en blocs -> seuls les blocs modifiés sont transférés vers l’écran.*  
*Les primitives graphiques sont minimalistes, elles pourront être complétées en fonction des besoins.*  


## Mise en oeuvre / Implementation
The code can be modified and compiled in VS Code within the Daisy Seed development environment (see https://github.com/electro-smith).  
*Le code est modifiable et compilable sous VS Code dans l’environnement de développement du Daisy Seed (voir https://github.com/electro-smith).*

### Configuration
1. Clonez le projet / Clone the project:
```
  git clone --recurse-submodules https://github.com/DADDesign-Projects/DEMO_DaisyGFX_ST7789 VotreDossier
```
   
2. Le fichier Makefile est à adapter en fonction de l’emplacement des librairies / Adapt the Makefile to the location of the libraries : 
```
  LIBDAISY_DIR = ../../../Desktop/DaisyExamples/libDaisy/
  DAISYSP_DIR = ../../../Desktop/DaisyExamples/DaisySP/
```
3. Le fichier .vscode/c_cpp_properties.json est aussi à adapter / Adapt the .vscode/c_cpp_properties.json file as well :
```
"includePath": [
  "${workspaceFolder}/**",
  "${workspaceFolder}/../../../Desktop/DaisyExamples/libDaisy//**",
  "${workspaceFolder}/../../../Desktop/DaisyExamples/DaisySP//**"
```
4. Le fichier UserConfig.h permet d’adapter la bibliothèque aux différentes implémantations matérielles / The UserConfig.h file allows adapting the library to different hardware implementations..


**N'hésitez pas à me contacter si vous avez des questions ou des suggestions.**  
**Don't hesitate to contact me if you have any questions or suggestions.**
