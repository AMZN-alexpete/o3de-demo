# demo project

A demo project

Open a command prompt and run this command:

```
git clone https://github.com/AMZN-alexpete/o3de-demo.git c:\o3de-demo
```

Folder structure after command completes:
```
c:\o3de-demo\
  o3de-sdk     <-- o3de SDK
  demo-project <-- project folder
  Editor.bat   <-- shortcut to run editor
  Game.bat     <-- shortcut to run game  
```

# How I created this repository

```
# make the repository folder
mkdir c:\o3de-demo
cd c:\o3de-demo

# init the git repo
git init .

# clone the o3de fork into o3de folder
git clone https://github.com/AMZN-alexpete/o3de.git

# make own branch
git checkout -b demo

# edit engine.json and rename engine to o3de-demo
git add . && git commit -sm "changed engine name"

# get python
python\get_python.bat

# configure 
cmake -B build/windows_vs2019 -G "Visual Studio 16" -DLY_3RDPARTY_PATH=d:\git\3rdParty\ -DLY_VERSION_ENGINE_NAME=o3de-demo -DCMAKE_INSTALL_PREFIX=d:\demo\o3de-sdk

# build sdk - outputs to d:\demo\o3de-sdk
cmake --build build/windows_vs2019 --target INSTALL --config profile -- -m

# create the project - 5 seconds
scripts\o3de.bat create-project --project-path c:\o3de-demo\demo-project

# register project with sdk  - not needed?
scripts\o3de.bat register --project-path ../demo-project -esep ../o3de-sdk 
# important thing is the project.json has the correct engine name in it "o3de-demo"
git add . && git commit -sm "registered project"

# configure project - 54 seconds
cd c:\o3de-demo\demo-project
cmake -B build/windows_vs2019 -G "Visual Studio 16" -DLY_3RDPARTY_PATH="d:/git/3rdparty"

# build project - 12 minutes
cmake --build build/windows_vs2019 --target Editor demo-project.GameLauncher --config profile -- -m

# add .gitignore, .gitattributes (from o3de), LICENSE.txt, README.md and .cmd shortcuts
# add the git remote and push
git remote add origin https://github.com/AMZN-alexpete/o3de-demo.git
git push -u origin main --force

```
