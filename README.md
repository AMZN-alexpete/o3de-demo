# demo project

A demo project

Open a command prompt and run this command:

```
git clone https://github.com/AMZN-alexpete/o3de-demo.git c:\o3de-demo
```

Folder structure after command completes:
```
c:\o3de-demo\
  demo-project <-- project folder
  Editor.bat <-- shortcut to run editor
  Game.bat <-- shortcut to run game  
```

# How I created this repository

mkdir c:\o3de-demo
cd c:\o3de-demo
# clone the o3de fork

git clone https://github.com/AMZN-alexpete/o3de.git

# make own branch
git checkout -b demo

# edit engine.json and rename engine to o3de-demo
git add . && git commit -sm "changed engine name"

# configure to get python & cmake
cmake -B build/windows_vs2019 -G "Visual Studio 16" -DLY_3RDPARTY_PATH="d:/git/3rdparty"

# register the engine (maybe don't need this?)
scripts\o3de.bat register --this-engine

# create the project - 5 seconds
scripts\o3de.bat create-project --project-path c:\o3de-demo\demo-project

# register project with engine
scripts\o3de.bat register --project-path ../demo-project -esep .
# manually edit engine.json so project path is relative like this:
# "../demo-project"
git add . && git commit -sm "registered project"

# configure project - 54 seconds
cd c:\o3de-demo\demo-project
cmake -B build/windows_vs2019 -G "Visual Studio 16" -DLY_3RDPARTY_PATH="d:/git/3rdparty"

# build project - 12 minutes
cmake --build build/windows_vs2019 --target Editor demo-project.GameLauncher --config profile -- -m

# add .gitignore, .gitattributes (from o3de), LICENSE.txt, README.md and .cmd shortcuts
