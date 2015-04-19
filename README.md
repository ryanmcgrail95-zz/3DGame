# 3DGame

The game is an open world that can be explored enemies can be fought and many things can happen

##set up git
sudo apt-get update

sudo apt-get install git

git config --global user.name "Username"

git config --global user.email "UserEmail"

ssh-keygen -t rsa -C "UserEmail"

eval "$(ssh-agent -s)"

ssh-add ~/.ssh/id_rsa

cat ~/.ssh/id_rsa.pub

####copy printed text to clipboard
####open github.com
####click on gear for "settings" in top right corner of screen
####click "ssh keys" on left side of page
####click "add SSH key" on right side
####create a title for this machine
####paste the text copied from ~/.ssh/id_rsa.pub in the "Key" box
####click "Add key" at the bottom of the "Key" box

ssh -T git@github.com

####type "yes" when the RSA fingerprint message appears
##clone github repository

git clone https://github.com/rmcgrai1/3DGame.git

cd 3DGame

###install dependencies
sudo apt-get install g++##Not needed in last 2 tries, but required in first installation

sudo apt-get install libX11-dev##Not needed in first 2 tries, but needed last time

sudo apt-get install libpng-dev##Not needed in first 2 tries, but needed last time

sudo apt-get install freeglut3-dev

##OPENAL
sudo add-apt-repository "deb http://archive.ubuntu.com/ubuntu $(lsb_release -sc) universe"

sudo apt-get update

sudo apt-get install libopenal-dev

sudo apt-get install libalut-dev

