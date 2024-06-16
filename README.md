# DEMO_DaisyGFX_ST7735
Demo TFT graphical display library for Daisy Seed T7735 driver

## Author
DAD Design

## Présentation
Le présent projet montre la mise en oeuvre de la librairie DaisySeedGFX https://github.com/DADDesign-Projects/DaisySeedGFX.

DaisySeedGFX est une bibliothèque graphique pour la plateforme Daisy Seed de Electrosmith.
La bibliothèque prend en charge pour le moment uniquement les contrôleurs ST7735 et ST7789. A priori la bibliothèque doit pouvoir être adaptée à n’importe quel contrôleur assez facilement.
La bibliothèque utilise un frame buffer intermédiaire ente les primitives graphiques et le contrôleur. Les modifications réalisées dans le frame buffer sont transmises au contrôleur utilisant les transferts SPI sous DMA. Afin de réduire les transferts le frame buffer est divisé en blocs -> seuls les blocs modifiés sont transférés vers l’écran.
Les primitives graphiques sont minimalistes, elles pourront être complétées en fonction des besoins.


## Mise en oeuvre
Le code est modifiable et compilable sous VS Code dans l’environnement de développement du Daisy Seed (voir le https://github.com/electro-smith).

### Configuration
1. Clonez le projet :
```
  git clone --recurse-submodules https://github.com/DADDesign-Projects/DEMO_DaisyGFX_ST7735 VotreDossier
```
3. Le fichier Makefile est à adapter en fonction de l’emplacement des librairies : 
```
  LIBDAISY_DIR = ../../../Desktop/DaisyExamples/libDaisy/
  DAISYSP_DIR = ../../../Desktop/DaisyExamples/DaisySP/
```
3. Le fichier .vscode/c_cpp_properties.json est aussi à adapter :
```
"includePath": [
  "${workspaceFolder}/**",
  "${workspaceFolder}/../../../Desktop/DaisyExamples/libDaisy//**",
  "${workspaceFolder}/../../../Desktop/DaisyExamples/DaisySP//**"
```
4. Le fichier UserConfig.h permet d’adapter la bibliothèque aux différentes implémentations matérielles.
