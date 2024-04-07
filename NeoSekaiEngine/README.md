# SekaiTemplate
The template that implement SekaiEngine to develop game

## Libraries
* raylib 4.2.0

## Requirements
* git
* [CMake](https://cmake.org/download/)
* [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html) (for Web platform)
* **MSVC** or **Makefile**

## Installation
### Clone this project
``` bash
git clone https://github.com/hailiang194/SekaiEngine.git <project_name>
```
**Note:** You can **NOT** use **SekaiEngine** for your project name

### Install SekaiEngine

#### Linux user
If you use **Debian** or **Redhat**, you need to run the pre-installer script in scripts

First, you need to give the script the permission to execute
``` bash
sudo chmod +x scripts/pre-installer/linux/<os>/preinstaller.sh
```
Then run that script
``` bash
./scripts/pre-installer/linux/<os>/preinstaller.sh
```
Which ```<os>``` is **```debian```** if you use **Debian** distro and **```redhat```** if you use **Fedora-based**
## Generate project
### Setup project

Download ```scripts/tool/tool.py```

Run the script
```sh
python3 tool.py [-h] [--engine_versions] [-y] [-v] [-p PATH] project_name engine_version
```
```
positional arguments:
  project_name          Name of project
  engine_version        set version of engine

options:
  -h, --help            show this help message and exit
  --engine_versions     Show all engine versions
  -y, --yes             Yes to all for every prompt
  -v, --verbose         Show verbose
  -p PATH, --path PATH  Project path
```

**Note**: You may need ```sudo``` for setup script in Linux. 

### Desktop platform
Create ```build``` folder and go to this folder 
``` bash
mkdir build
cd build
```
run CMake
``` bash
cmake ..
```
After that, It's going to generate a project for you
### Web platform
At the root project folder run
``` bash
emcmake cmake -S . -B build -DPLATFORM=Web -DBUILD_SHARED_LIBS=0
```
## Build project
### Desktop platform
#### **MSVC:**
If you set ```MSBuild.exe``` as a PATH, Run ```MSBuild.exe``` the ```*.snl``` file in build folder.
```
MSBuild <Project-name>.sln
```
If you open by Visual Studio, keep going

#### **Makefile**

Go to build folder and run
```
make
```
### Web platform
Go to build folder
``` bash
cd build
```
Run makefile
``` bash
make PLATFORM=PLATFORM_WEB -B
```
## Start our game
### Desktop platformm
#### **MSVC**
If you build project by ```MSBuild.exe```, your execution file is in
```
<Project root folder>\build\out\<Configure Mode>\<Game-project-name>.exe
```
and if you use Visual Studio, just click **Run**
#### **Makefile**
Your execution file in in ```<Project root folder>\build\out``` folder
### Web platform
Go to ```<Project root folder>\build\bin``` folder
Run python server
```
python -m http.server <port>
```
Go to the browser and access to
```
localhost:<port>/<Game-project-name>.html
```