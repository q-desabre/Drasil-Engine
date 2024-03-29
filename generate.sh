#bash gen_drasil.sh ; bash gen_menu.sh ; bash gen_sfml.sh ; bash gen_nexus.sh

#create a simple function that takes a path as argument

#bash gen_drasil.sh ; bash gen_menu.sh ; bash gen_sfml.sh ; bash gen_nexus.sh

#create a simple function that takes a path as argument


function generate() {
    echo "generating $1"
    cd $1 ; make ; cd - > /dev/null
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
    generate "Drasil/build"
    generate "Games/Menu/build"
    generate "Graphicals/SFML/build"
    generate "Nexus/build"
    exit 0
elif [ $1 = "drasil" ]
  then
    generate "Drasil/build"
    exit 0
elif [ $1 = "menu" ]
  then
    generate "Games/Menu/build"
    exit 0
elif [ $1 = "sfml" ]
  then
    generate "Graphicals/SFML/build"
    exit 0
elif [ $1 = "nexus" ]
  then
    generate "Nexus/build"
    exit 0
fi
