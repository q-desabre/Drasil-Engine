#bash gen_drasil.sh ; bash gen_menu.sh ; bash gen_sfml.sh ; bash gen_nexus.sh

#create a simple function that takes a path as argument

#bash gen_drasil.sh ; bash gen_menu.sh ; bash gen_sfml.sh ; bash gen_nexus.sh

#create a simple function that takes a path as argument


function clean() {
    echo "Cleaning $1"
    cd $1 ; make clean ; cd - > /dev/null
}





# Path: generate.sh

#get first arg
if [ $# -eq 0 ]
  then
    echo "No arguments supplied"
    exit 1
fi

#check if first arg is "all"
if [ $1 = "all" ]
  then
    clean "Drasil/build"
    clean "Games/Menu/build"
    clean "Graphicals/SFML/build"
    clean "Nexus/build"
    exit 0
elif [ $1 = "drasil" ]
  then
    clean "Drasil/build"
    exit 0
elif [ $1 = "menu" ]
  then
    clean "Games/Menu/build"
    exit 0
elif [ $1 = "sfml" ]
  then
    clean "Graphicals/SFML/build"
    exit 0
elif [ $1 = "nexus" ]
  then
    clean "Nexus/build"
    exit 0
fi
