# O3DE Demo Project


## Install

Open a command prompt and run this command:

```
git clone https://github.com/AMZN-alexpete/o3de-demo.git c:\o3de-demo
```

## Running the Editor with Editor.cmd

Running `Editor.cmd` will run the Editor and also run `Install.cmd` for you to make sure Python is installed and the engine is registered.
The Asset Processor will open and take some time to prepare the assets and then you're ready!

## Running the Game with Game.cmd

Running `Game.cmd` will run the Game (launcher) and also run `Install.cmd` for you to make sure Python is installed and the engine is registered.
The Asset Processor will also open but if you've already run the Editor it shouldn't need to process any additional assets. 


### Folder structure
```
c:\o3de-demo\
  o3de-sdk     <-- o3de SDK
  demo-project <-- project folder
  Editor.cmd   <-- shortcut to run editor
  Game.cmd     <-- shortcut to run game  
  Install.cmd  <-- shortcut to get python and register the engine
```

## Workflow

### Non-engineers
- work on game files in the `demo-project` folder
- work on art and other files likely stored in an `art` folder that engineers do not use

### Engineers
- clone the engine fork into c:\o3de-demo\o3de and register it
- modify engine and game code
- create and upload new builds for non-engineers
  The `CreateBuild.cmd` copies binary files from `build\windows_vs2019\bin\profile` into `bin`


## How I created this repository

These are the basic steps I followed to create this layout.

### 1. Created the folder and boilerplate files
```
# make the repository folder
mkdir c:\o3de-demo
cd c:\o3de-demo

# init the git repo
git init .
git checkout -b main
git remote add origin https://github.com/AMZN-alexpete/o3de-demo.git

# add .gitignore, .gitattributes (from o3de), LICENSE.txt, README.md and .cmd shortcuts
```

### 2. Get the engine fork
```
# clone the o3de fork into o3de folder
git clone https://github.com/AMZN-alexpete/o3de.git

# make own branch
git checkout -b demo

# get python
cd o3de
python\get_python.bat

# rename engine to o3de-demo
scripts\o3de.bat edit-engine-properties --engine-path . -enn o3de-demo

# commit changes
git add . && git commit -sm "changed engine name"
git push -u origin demo
```

### 3. Create an SDK in `o3de-sdk`
```
# configure 
cmake -B build/windows_vs2019 -G "Visual Studio 16" -DLY_3RDPARTY_PATH=d:\git\3rdParty\ -DLY_VERSION_ENGINE_NAME=o3de-demo -DCMAKE_INSTALL_PREFIX=c:\o3de-demo\o3de-sdk

# build sdk - outputs to c:\o3de-demo\o3de-sdk
cmake --build build/windows_vs2019 --target INSTALL --config profile -- -m
```

### 4. Create the project
```
# create the project - 5 seconds
scripts\o3de.bat create-project --project-path c:\o3de-demo\demo-project

# register project with sdk - important thing is the project.json has the correct engine name in it "o3de-demo"
scripts\o3de.bat register --project-path ../demo-project 

# configure project
cd c:\o3de-demo\demo-project
cmake -B build/windows_vs2019 -G "Visual Studio 16" -DLY_3RDPARTY_PATH="d:/git/3rdparty"

# build project
cmake --build build/windows_vs2019 --target Editor demo-project.GameLauncher --config profile -- -m

# run CreateBuild.cmd to copy project binary files into demo-project/bin
cd ..
CreateBuild.cmd

# commit the project 
git add . && git commit -sm "added project"
```

### 5. Upload to GitHub
```
git push -u origin main --force
```
